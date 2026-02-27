#ifndef __GPIO_H__
#define __GPIO_H__

#include "STC32G.h"

#define PAN3031_IRQ_PORT   P3
#define PAN3031_IRQ_PIN    0x04

#define PAN3031_RST_PORT   P3
#define PAN3031_RST_PIN    0x08

#define PAN3031_TX_EN_PORT P3
#define PAN3031_TX_EN_PIN  0x10

#define PAN3031_RX_EN_PORT P3
#define PAN3031_RX_EN_PIN  0x20

#define LED1_PORT          P5
#define LED1_PIN           0x10

#define PAN3031_IRQ_READ() (PAN3031_IRQ_PORT & PAN3031_IRQ_PIN)

#define PAN3031_RST_HIGH() do{PAN3031_RST_PORT |= PAN3031_RST_PIN;}while(0)
#define PAN3031_RST_LOW()  do{PAN3031_RST_PORT &= ~PAN3031_RST_PIN;}while(0)

#define PAN3031_TX_EN_HIGH() do{PAN3031_TX_EN_PORT |= PAN3031_TX_EN_PIN;}while(0)
#define PAN3031_TX_EN_LOW()  do{PAN3031_TX_EN_PORT &= ~PAN3031_TX_EN_PIN;}while(0)

#define PAN3031_RX_EN_HIGH() do{PAN3031_RX_EN_PORT |= PAN3031_RX_EN_PIN;}while(0)
#define PAN3031_RX_EN_LOW()  do{PAN3031_RX_EN_PORT &= ~PAN3031_RX_EN_PIN;}while(0)

void LED1_HIGH(void);
void LED1_LOW(void);
void LED1_TOGGLE(void);
void GPIO_Init(void);

#endif
