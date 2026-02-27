#ifndef __UART_H__
#define __UART_H__

#include "STC32G.h"

void UART1_Init(uint32_t baudrate);
void UART1_SendByte(uint8_t dat);
void UART1_SendString(uint8_t *str);
void UART1_SendBuf(uint8_t *buf, uint16_t len);

#endif
