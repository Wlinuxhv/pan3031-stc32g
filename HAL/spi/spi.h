#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>

void SPI1_Init(void);
uint8_t SPI1_ReadWriteByte(uint8_t data);
void PAN3031_CS_HIGH(void);
void PAN3031_CS_LOW(void);

#endif
