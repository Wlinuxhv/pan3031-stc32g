#include "STC32G.h"
#include "gpio.h"
#include "spi.h"
#include "delay.h"
#include "uart.h"
#include "pan3031_port.h"
#include "radio.h"

#define TX_LEN 10
#define RX_LEN 64

bool pan3031_irq_trigged_flag = FALSE;

uint8_t tx_test_buf[TX_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t rx_test_buf[RX_LEN] = {0};
uint32_t tx_time = 0;

extern struct RxDoneMsg RxDoneParams;

void System_Init(void)
{
    Delay_Init();
    GPIO_Init();
    SPI1_Init();
    UART1_Init(115200);
    EX0 = 1;
    IT0 = 1;
    EA = 1;
}

void LED_Toggle(void)
{
    LED1_TOGGLE();
    Delay_Ms(50);
    LED1_TOGGLE();
    Delay_Ms(50);
}

void Master_Send(void)
{
    if(rf_single_tx_data(tx_test_buf, TX_LEN, &tx_time) != OK)
    {
        LED1_LOW();
    }
    while(rf_get_transmit_flag() == RADIO_FLAG_IDLE);
    rf_set_transmit_flag(RADIO_FLAG_IDLE);
    LED_Toggle();
    
    rf_enter_single_timeout_rx(15000);
}

void Slave_Receive(void)
{
    uint8_t i;
    if(rf_get_recv_flag() == RADIO_FLAG_RXDONE)
    {
        rf_set_recv_flag(RADIO_FLAG_IDLE);
        
        for(i = 0; i < RxDoneParams.Size; i++)
        {
            rx_test_buf[i] = RxDoneParams.Payload[i];
        }
        
        rf_enter_single_timeout_rx(15000);
        LED_Toggle();
    }
    
    if((rf_get_recv_flag() == RADIO_FLAG_RXTIMEOUT) || (rf_get_recv_flag() == RADIO_FLAG_RXERR))
    {
        rf_set_recv_flag(RADIO_FLAG_IDLE);
        rf_enter_single_timeout_rx(15000);
    }
}

void PAN3031_IRQ_Handler(void) interrupt 0
{
    pan3031_irq_trigged_flag = TRUE;
    rf_irq_handler();
}

void main(void)
{
    uint32_t ret;
    
    System_Init();
    
    UART1_SendString("PAN3031 STC32G Demo\r\n");
    
    Delay_Ms(10);
    
    ret = rf_init();
    
    if(ret != OK)
    {
        UART1_SendString("RF Init Failed!\r\n");
        while(1)
        {
            LED_Toggle();
        }
    }
    
    UART1_SendString("RF Init OK!\r\n");
    
    rf_set_default_para();
    
    rf_enter_single_timeout_rx(15000);
    
    UART1_SendString("Start Receiving...\r\n");
    
    while(1)
    {
        rf_irq_process();
        Slave_Receive();
    }
}
