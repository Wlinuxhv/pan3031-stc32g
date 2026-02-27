// PAN3031 STC32G 演示程序
#include "STC32G.h"
#include "spi.h"
#include "gpio.h"
#include "delay.h"
#include "uart.h"
#include "pan3031_port.h"
#include "radio.h"

// 外部变量
extern rf_port_t rf_port;

// 初始化 rf_port 结构
rf_port_t rf_port = {
    .spi_readwrite = SPI1_ReadWriteByte,
    .cs_high = PAN3031_CS_HIGH,
    .cs_low = PAN3031_CS_LOW,
    .delay_ms = Delay_Ms,
    .delay_us = Delay_Us
};

// 系统初始化
void System_Init(void) {
    Delay_Init();
    GPIO_Init();
    SPI1_Init();
    UART1_Init(115200);
}

// 主函数
void main(void) {
    uint8_t tx_data[] = "Hello PAN3031!";
    uint8_t rx_data[64];
    uint8_t rx_len;
    
    System_Init();
    
    // 发送欢迎信息
    UART1_SendString("\r\n=== PAN3031 STC32G Demo ===\r\n");
    
    // 初始化射频
    UART1_SendString("RF Init... ");
    if (rf_init() == OK) {
        UART1_SendString("OK\r\n");
    } else {
        UART1_SendString("FAIL!\r\n");
        while (1);
    }
    
    // 开始接收
    UART1_SendString("Start RX...\r\n");
    rf_start_rx();
    
    // 主循环
    while (1) {
        // 轮询接收
        if (rf_poll_rx(rx_data, &rx_len) == OK) {
            UART1_SendString("RX: ");
            for (uint8_t i = 0; i < rx_len; i++) {
                UART1_SendByte(rx_data[i]);
            }
            UART1_SendString("\r\n");
            
            // 回复
            rf_send(tx_data, sizeof(tx_data) - 1);
            
            // 等待发送完成
            while (rf_get_state() == RADIO_STATE_TX) {
                rf_poll_tx();
            }
            
            // 回到接收
            rf_start_rx();
        }
        
        Delay_Ms(10);
    }
}
