#include "delay.h"

void Delay_Init(void)
{
    AUXR &= 0xBF;
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TH0 = 0;
    TL0 = 0;
    TR0 = 1;
}

void Delay_Ms(uint16_t ms)
{
    uint16_t i, j;
    for(j = 0; j < ms; j++)
    {
        for(i = 0; i < 1000; i++)
        {
            _nop_();
            _nop_();
            _nop_();
            _nop_();
        }
    }
}

void Delay_Us(uint16_t us)
{
    uint16_t i;
    for(i = 0; i < us; i++)
    {
        _nop_();
        _nop_();
    }
}
