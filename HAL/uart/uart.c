#include "uart.h"

void UART1_Init(uint32_t baudrate)
{
    uint16_t baud;
    
    P_SW1 = 0x00;
    
    P3M0 &= 0xFC;
    P3M1 &= 0xFC;
    
    baud = (uint16_t)(65536 - (FOSC / 4 / baudrate));
    
    TH1 = baud;
    TL1 = baud;
    
    TR1 = 1;
    
    SCON = 0x50;
}

void UART1_SendByte(uint8_t dat)
{
    SBUF = dat;
    while(!TI);
    TI = 0;
}

void UART1_SendString(uint8_t *str)
{
    while(*str != '\0')
    {
        UART1_SendByte(*str);
        str++;
    }
}

void UART1_SendBuf(uint8_t *buf, uint16_t len)
{
    uint16_t i;
    for(i = 0; i < len; i++)
    {
        UART1_SendByte(buf[i]);
    }
}
