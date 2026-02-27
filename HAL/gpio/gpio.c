#include "gpio.h"

void GPIO_Init(void)
{
    P2M0 &= 0xF0;
    P2M1 &= 0xF0;
    P2M0 |= 0x0A;
    P2M1 |= 0x0A;
    
    P3M0 &= 0x07;
    P3M1 &= 0x07;
    P3M0 |= 0xE0;
    P3M1 |= 0x00;
    
    P5M0 &= 0xEF;
    P5M1 &= 0xEF;
    P5M0 |= 0x10;
    P5M1 |= 0x00;
    
    PAN3031_CS_HIGH();
    PAN3031_SCK_LOW();
    PAN3031_MOSI_LOW();
    
    PAN3031_RST_HIGH();
    PAN3031_TX_EN_LOW();
    PAN3031_RX_EN_LOW();
    
    LED1_HIGH();
}
