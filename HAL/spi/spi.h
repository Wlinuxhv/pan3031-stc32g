#ifndef __SPI_H__
#define __SPI_H__

#include "STC32G.h"

void SPI1_Init(void);
void SPI2_Init(void);
uint8_t SPI1_ReadWriteByte(uint8_t dat);
uint8_t SPI2_ReadWriteByte(uint8_t dat);

#define PAN3031_SPI    SPI1

#define PAN3031_SCK_PORT   P2
#define PAN3031_SCK_PIN    0x04

#define PAN3031_MISO_PORT  P2
#define PAN3031_MISO_PIN  0x02

#define PAN3031_MOSI_PORT  P2
#define PAN3031_MOSI_PIN  0x01

#define PAN3031_CS_PORT    P2
#define PAN3031_CS_PIN     0x08

#define PAN3031_SCK_HIGH() do{PAN3031_SCK_PORT |= PAN3031_SCK_PIN;}while(0)
#define PAN3031_SCK_LOW()  do{PAN3031_SCK_PORT &= ~PAN3031_SCK_PIN;}while(0)
#define PAN3031_MOSI_HIGH() do{PAN3031_MOSI_PORT |= PAN3031_MOSI_PIN;}while(0)
#define PAN3031_MOSI_LOW()  do{PAN3031_MOSI_PORT &= ~PAN3031_MOSI_PIN;}while(0)
#define PAN3031_MISO_READ() (PAN3031_MISO_PORT & PAN3031_MISO_PIN)

#define PAN3031_CS_HIGH()  do{PAN3031_CS_PORT |= PAN3031_CS_PIN;}while(0)
#define PAN3031_CS_LOW()   do{PAN3031_CS_PORT &= ~PAN3031_CS_PIN;}while(0)

#endif
