#ifndef __STC32G_H__
#define __STC32G_H__

// SDCC compatible STC32G12K128 register definitions
// No external dependencies required

// Standard 8051 bit definitions
#define _nop_() __asm__("nop")

#define TRUE    1
#define FALSE   0
#define SUCCESS 1
#define FAIL    0

// Standard 8051 SFRs
__sfr __at(0x80) P0;
__sfr __at(0x81) SP;
__sfr __at(0x82) DPL;
__sfr __at(0x83) DPH;
__sfr __at(0x87) PCON;
__sfr __at(0x88) TCON;
__sfr __at(0x89) TMOD;
__sfr __at(0x8A) TL0;
__sfr __at(0x8B) TL1;
__sfr __at(0x8C) TH0;
__sfr __at(0x8D) TH1;
__sfr __at(0x90) P1;
__sfr __at(0x98) SCON;
__sfr __at(0x99) SBUF;
__sfr __at(0xA0) P2;
__sfr __at(0xA8) IE;
__sfr __at(0xB0) P3;
__sfr __at(0xB8) IP;
__sfr __at(0xD0) PSW;
__sfr __at(0xE0) ACC;
__sfr __at(0xF0) B;

// STC32G specific SFRs
__sfr __at(0x94) P0M0;  __sfr __at(0x93) P0M1;
__sfr __at(0x92) P1M0;  __sfr __at(0x91) P1M1;
__sfr __at(0x96) P2M0;  __sfr __at(0x95) P2M1;
__sfr __at(0xB2) P3M0;  __sfr __at(0xB1) P3M1;
__sfr __at(0xE9) P4M0;  __sfr __at(0xEA) P4M1;
__sfr __at(0xF9) P5M0;  __sfr __at(0xFA) P5M1;

__sfr __at(0x8F) CLK_DIV;  __sfr __at(0x8E) IRTRIM;
__sfr __at(0x98) IRTC;     __sfr __at(0x9F) IRCR;
__sfr __at(0x8C) AUXR;     __sfr __at(0xA2) AUXR1;
__sfr __at(0xBA) P_SW2;    __sfr __at(0xAF) IE2;
__sfr __at(0xB5) IP2;      __sfr __at(0xB6) IP2H;
__sfr __at(0xA8) P_SW1;

__sfr __at(0x9A) S2CON;  __sfr __at(0x9B) S2BUF;  __sfr __at(0x9C) S2BRT;
__sfr __at(0xA2) SPI_SSPSTAT;  __sfr __at(0xA3) SPI_SSPCON;
__sfr __at(0xA4) SPI_SSPD;     __sfr __at(0xA5) SPI_SSPSRK;

__sfr __at(0xC8) T2CON;   __sfr __at(0xC9) T2MOD;
__sfr __at(0xCA) RCAP2L;  __sfr __at(0xCB) RCAP2H;
__sfr __at(0xCC) TL2;     __sfr __at(0xCD) TH2;

__sfr __at(0xC1) WDT_CONTR;  __sfr __at(0xC7) IAP_CONTR;
__sfr __at(0xC2) IAP_DATA;   __sfr __at(0xC3) IAP_ADDRH;
__sfr __at(0xC4) IAP_ADDRL;  __sfr __at(0xC5) IAP_CMD;
__sfr __at(0xC6) IAP_TRIG;

__sfr __at(0xE8) P4;   __sfr __at(0xC0) XICON;
__sfr __at(0xF8) P5;

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
typedef __bit bool;

#define FOSC    24000000UL
#define BAUD    115200

#endif
