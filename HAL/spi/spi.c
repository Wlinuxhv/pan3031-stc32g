#include "spi.h"

void SPI1_Init(void)
{
    P_SW2 |= 0x01;
    
    SPI_SSPSTAT = 0x40;
    SPI_SSPCON = 0x30;
    
    P_SW2 &= ~0x01;
}

void SPI2_Init(void)
{
    P_SW2 |= 0x01;
    
    SPI_SSPSTAT = 0x40;
    SPI_SSPCON = 0x30;
    
    P_SW2 &= ~0x01;
}

uint8_t SPI1_ReadWriteByte(uint8_t dat)
{
    uint8_t i;
    for(i = 0; i < 8; i++)
    {
        if(dat & 0x80)
        {
            PAN3031_MOSI_HIGH();
        }
        else
        {
            PAN3031_MOSI_LOW();
        }
        dat <<= 1;
        
        PAN3031_SCK_HIGH();
        _nop_();
        _nop_();
        
        if(PAN3031_MISO_READ())
        {
            dat |= 0x01;
        }
        
        PAN3031_SCK_LOW();
        _nop_();
        _nop_();
    }
    return dat;
}

uint8_t SPI2_ReadWriteByte(uint8_t dat)
{
    return SPI1_ReadWriteByte(dat);
}
