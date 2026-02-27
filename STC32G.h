#ifndef __STC32G_H__
#define __STC32G_H__

#include <reg52.h>
#include <intrins.h>

#define TRUE    1
#define FALSE   0
#define SUCCESS 1
#define FAIL    0

sfr P0   = 0x80;
sfr SP   = 0x81;
sfr DPL  = 0x82;
sfr DPH  = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr P1   = 0x90;
sfr SCON = 0x98;
sfr SBUF = 0x99;
sfr P2   = 0xA0;
sfr IE   = 0xA8;
sfr P3   = 0xB0;
sfr IP   = 0xB8;
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;

sfr P0M0  = 0x94;
sfr P0M1  = 0x93;
sfr P1M0  = 0x92;
sfr P1M1  = 0x91;
sfr P2M0  = 0x96;
sfr P2M1  = 0x95;
sfr P3M0  = 0xB2;
sfr P3M1  = 0xB1;

sfr CLK_DIV = 0x8F;
sfr IRTRIM  = 0x8E;
sfr IRTC    = 0x98;
sfr IRCR    = 0x9F;

sfr AUXR   = 0x8C;
sfr AUXR1  = 0xA2;
sfr P_SW2   = 0xBA;
sfr IE2     = 0xAF;
sfr IP2     = 0xB5;
sfr IP2H    = 0xB6;
sfr P_SW1   = 0xA8;

sfr S2CON   = 0x9A;
sfr S2BUF   = 0x9B;
sfr S2BRT   = 0x9C;
sfr IE2     = 0xAF;

sfr SPI_SSPSTAT = 0xA2;
sfr SPI_SSPCON  = 0xA3;
sfr SPI_SSPD    = 0xA4;
sfr SPI_SSPSRK  = 0xA5;

sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;

sfr WDT_CONTR = 0xC1;
sfr IAP_CONTR = 0xC7;
sfr IAP_DATA  = 0xC2;
sfr IAP_ADDRH = 0xC3;
sfr IAP_ADDRL = 0xC4;
sfr IAP_CMD   = 0xC5;
sfr IAP_TRIG  = 0xC6;

sfr P4   = 0xE8;
sfr P4M0 = 0xE9;
sfr P4M1 = 0xEA;
sfr XICON = 0xC0;

sfr P5   = 0xF8;
sfr P5M0 = 0xF9;
sfr P5M1 = 0xFA;

sfr PWMA_ETO0 = 0xEC;
sfr PWMA_ETO1 = 0xED;
sfr PWMA_ETO2 = 0xEE;
sfr PWMA_ETO3 = 0xEF;
sfr PWMB_ETO4 = 0xF4;
sfr PWMB_ETO5 = 0xF5;
sfr PWMB_ETO6 = 0xF6;
sfr PWMB_ETO7 = 0xF7;

sfr PWMA_CR1  = 0xFC;
sfr PWMA_CR2  = 0xFD;
sfr PWMA_CCMR1 = 0xFB;
sfr PWMA_CCMR2 = 0xFA;
sfr PWMA_CCMR3 = 0xF9;
sfr PWMA_CCMR4 = 0xF8;
sfr PWMA_CCER1 = 0xF7;
sfr PWMA_CCER2 = 0xF6;
sfr PWMA_CNTRH = 0xF5;
sfr PWMA_CNTRL = 0xF4;
sfr PWMA_PSCR  = 0xF3;
sfr PWMA_ARRH  = 0xF2;
sfr PWMA_ARRL  = 0xF1;
sfr PWMA_CCR1H = 0xEF;
sfr PWMA_CCR1L = 0xEE;
sfr PWMA_CCR2H = 0xED;
sfr PWMA_CCR2L = 0xEC;
sfr PWMA_CCR3H = 0xEB;
sfr PWMA_CCR3L = 0xEA;
sfr PWMA_CCR4H = 0xE9;
sfr PWMA_CCR4L = 0xE8;
sfr PWMA_BKR   = 0xFF;
sfr PWMA_EGR   = 0xF0;

sfr PWMB_CR1  = 0xBC;
sfr PWMB_CR2  = 0xBD;
sfr PWMB_CCMR1 = 0xBB;
sfr PWMB_CCMR2 = 0xBA;
sfr PWMB_CCMR3 = 0xB9;
sfr PWMB_CCMR4 = 0xB8;
sfr PWMB_CCER1 = 0xB7;
sfr PWMB_CCER2 = 0xB6;
sfr PWMB_CNTRH = 0xB5;
sfr PWMB_CNTRL = 0xB4;
sfr PWMB_PSCR  = 0xB3;
sfr PWMB_ARRH  = 0xB2;
sfr PWMB_ARRL  = 0xB1;
sfr PWMB_CCR1H = 0xAF;
sfr PWMB_CCR1L = 0xAE;
sfr PWMB_CCR2H = 0xAD;
sfr PWMB_CCR2L = 0xAC;
sfr PWMB_CCR3H = 0xAB;
sfr PWMB_CCR3L = 0xAA;
sfr PWMB_CCR4H = 0xA9;
sfr PWMB_CCR4L = 0xA8;
sfr PWMB_BKR   = 0xBF;
sfr PWMB_EGR   = 0xB0;

sfr CMP_CONFX = 0x9E;
sfr ADC_CONTR = 0xBC;
sfr ADC_DATA  = 0xBD;
sfr ADC_RES   = 0xBD;
sfr ADC_RESL  = 0xC4;

sfr PIOCON1 = 0x92;
sfr PIOCON2 = 0x93;

sfr EIE1  = 0xE8;
sfr EIE2  = 0xF0;
sfr EIP1  = 0xF8;
sfr EIP2  = 0xFF;

sfr POR_SYNC = 0xDF;

#define INT_CLKO_IC1  0x10
#define INT_CLKO_IC2   0x20
#define INT_CLKO_IC3   0x40
#define INT_CLKO_IC4   0x80

#define T2CON_T2_ESS   0x04

#define SPI_SS         0x01
#define SPI_MISO       0x02
#define SPI_MOSI       0x04
#define SPI_SCK        0x08
#define SPI_FIFO_EN    0x40
#define SPI_SPIF       0x80

#define SPI_SS_LOW()   do{P1 &= ~SPI_SS;}while(0)
#define SPI_SS_HIGH()  do{P1 |= SPI_SS;}while(0)
#define SPI_SCK_LOW()  do{P1 &= ~SPI_SCK;}while(0)
#define SPI_SCK_HIGH() do{P1 |= SPI_SCK;}while(0)
#define SPI_MOSI_LOW() do{P1 &= ~SPI_MOSI;}while(0)
#define SPI_MOSI_HIGH() do{P1 |= SPI_MOSI;}while(0)

#define SPI_READ_MISO() (P1 & SPI_MISO)

#define P30 0x80
#define P31 0x40
#define P32 0x20
#define P33 0x10
#define P34 0x08
#define P35 0x04
#define P36 0x02
#define P37 0x01

#define P40 0x01
#define P41 0x02
#define P42 0x04
#define P43 0x08
#define P44 0x10
#define P45 0x20
#define P46 0x40
#define P47 0x80

#define P50 0x01
#define P51 0x02
#define P52 0x04
#define P53 0x08

#define STC32G_SystemClock 24000000UL

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;
typedef bit bool;

#define FOSC    24000000UL
#define BAUD    115200

#endif
