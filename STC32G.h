#ifndef __STC32G_H__
#define __STC32G_H__

// Minimal STC32G header for SDCC compatibility
// No type definitions to avoid conflicts with stdint.h

#define _nop_() __asm__("nop")

// Standard 8051 SFRs
__sfr __at(0x80) P0;  __sfr __at(0x90) P1;  __sfr __at(0xA0) P2;
__sfr __at(0xB0) P3;  __sfr __at(0xC0) P4;  __sfr __at(0xF8) P5;

__sfr __at(0xA8) IE;  __sfr __at(0xB8) IP;  __sfr __at(0xD0) PSW;
__sfr __at(0xE0) ACC; __sfr __at(0xF0) B;

__sfr __at(0x88) TCON;  __sfr __at(0x89) TMOD;
__sfr __at(0x8A) TL0;   __sfr __at(0x8B) TL1;
__sfr __at(0x8C) TH0;   __sfr __at(0x8D) TH1;

__sfr __at(0x98) SCON;  __sfr __at(0x99) SBUF;
__sfr __at(0x87) PCON;

// GPIO mode registers
__sfr __at(0x93) P0M1;  __sfr __at(0x94) P0M0;
__sfr __at(0x91) P1M1;  __sfr __at(0x92) P1M0;
__sfr __at(0x95) P2M1;  __sfr __at(0x96) P2M0;
__sfr __at(0xB1) P3M1;  __sfr __at(0xB2) P3M0;
__sfr __at(0xE9) P4M1;  __sfr __at(0xEA) P4M0;
__sfr __at(0xF9) P5M1;  __sfr __at(0xFA) P5M0;

// UART
__sfr __at(0xA8) P_SW1;
__sfr __at(0x8C) AUXR;

// Timer2
__sfr __at(0xC8) T2CON;  __sfr __at(0xC9) T2MOD;
__sfr __at(0xCA) RCAP2L; __sfr __at(0xCB) RCAP2H;
__sfr __at(0xCC) TL2;    __sfr __at(0xCD) TH2;

// Macros
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0

#define FOSC 24000000UL

// GPIO bits
#define P32 0x20
#define P33 0x10
#define P34 0x08
#define P35 0x04

#endif
