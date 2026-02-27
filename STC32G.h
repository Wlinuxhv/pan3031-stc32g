#ifndef __STC32G_H__
#define __STC32G_H__

// Minimal SDCC compatible header for PAN3031 STC32G project
// Only includes registers actually used by the driver

#define _nop_() __asm__("nop")

// Basic types
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;
typedef __bit bool;

#define TRUE    1
#define FALSE   0
#define SUCCESS 1
#define FAIL    0

// Standard 8051 SFRs
__sfr __at(0x80) P0;
__sfr __at(0x90) P1;
__sfr __at(0xA0) P2;
__sfr __at(0xB0) P3;
__sfr __at(0xC0) P4;
__sfr __at(0xF8) P5;

__sfr __at(0xA8) IE;
__sfr __at(0xB8) IP;
__sfr __at(0xD0) PSW;
__sfr __at(0xE0) ACC;
__sfr __at(0xF0) B;

__sfr __at(0x81) SP;
__sfr __at(0x82) DPL;
__sfr __at(0x83) DPH;

__sfr __at(0x88) TCON;
__sfr __at(0x89) TMOD;
__sfr __at(0x8A) TL0;
__sfr __at(0x8B) TL1;
__sfr __at(0x8C) TH0;
__sfr __at(0x8D) TH1;

__sfr __at(0x98) SCON;
__sfr __at(0x99) SBUF;

__sfr __at(0x87) PCON;

// GPIO mode registers (STC specific)
__sfr __at(0x93) P0M1;  __sfr __at(0x94) P0M0;
__sfr __at(0x91) P1M1;  __sfr __at(0x92) P1M0;
__sfr __at(0x95) P2M1;  __sfr __at(0x96) P2M0;
__sfr __at(0xB1) P3M1;  __sfr __at(0xB2) P3M0;
__sfr __at(0xE9) P4M1;  __sfr __at(0xEA) P4M0;
__sfr __at(0xF9) P5M1;  __sfr __at(0xFA) P5M0;

// UART1
__sfr __at(0xA8) P_SW1;  // Peripheral port switch
__sfr __at(0x8C) AUXR;   // Auxiliary register

// Timer2 for baud rate
__sfr __at(0xC8) T2CON;
__sfr __at(0xC9) T2MOD;
__sfr __at(0xCA) RCAP2L;
__sfr __at(0xCB) RCAP2H;
__sfr __at(0xCC) TL2;
__sfr __at(0xCD) TH2;

// Interrupts
#define EA  0xAF    // Global interrupt enable (bit address)
#define EX0 0xA8    // External interrupt 0
#define IT0 0x88    // External interrupt 0 type
#define ET0 0xA9    // Timer 0 interrupt
#define EX1 0xAA    // External interrupt 1
#define ET1 0xAB    // Timer 1 interrupt
#define ES  0xAC    // UART interrupt

// Bit definitions for T2CON
#define T2R     0x02
#define T2X12   0x01

// System clock
#define FOSC    24000000UL
#define STC32G_SystemClock FOSC

// GPIO helper macros
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

// Interrupt vector for external interrupt 0
#define INT0_VECTOR 0

#endif
