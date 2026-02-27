// UART 驱动 - STC32G
#include "uart.h"
#include "STC32G.h"

void UART1_Init(uint32_t baud) {
    // 使用 Timer2 作为波特率发生器
    P_SW1 |= 0x80;  // P3.0/RXD, P3.1/TXD
    
    T2MOD |= 0x30;  // Timer2 为波特率发生器
    T2CON = 0x34;   // Timer2 启动
    
    // 计算重载值：65536 - (24000000 / 4 / baud)
    uint16_t reload = 65536 - (24000000 / 4 / baud);
    RCAP2H = reload >> 8;
    RCAP2L = reload & 0xFF;
    
    SCON = 0x50;  // 模式 1, 8 位 UART, 允许接收
    AUXR |= 0x15; // Timer2 时钟，UART1 使能
}

void UART1_SendByte(uint8_t data) {
    SBUF = data;
    while (!(SCON & 0x02));  // 等待发送完成
    SCON &= ~0x02;
}

void UART1_SendString(const char *str) {
    while (*str)
        UART1_SendByte(*str++);
}

uint8_t UART1_RecvByte(void) {
    while (!(SCON & 0x01));  // 等待接收完成
    SCON &= ~0x01;
    return SBUF;
}
