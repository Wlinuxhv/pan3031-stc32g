#ifndef __STC32G_H__
#define __STC32G_H__

// STC32G12K128 寄存器定义
// 基于官方数据手册

// 基本类型
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef __bit bool;

// 标准 SFR
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

// GPIO 模式寄存器
__sfr __at(0x93) P0M1;  __sfr __at(0x94) P0M0;
__sfr __at(0x91) P1M1;  __sfr __at(0x92) P1M0;
__sfr __at(0x95) P2M1;  __sfr __at(0x96) P2M0;
__sfr __at(0xB1) P3M1;  __sfr __at(0xB2) P3M0;
__sfr __at(0xE9) P4M1;  __sfr __at(0xEA) P4M0;
__sfr __at(0xF9) P5M1;  __sfr __at(0xFA) P5M0;

// 外设切换寄存器
__sfr __at(0xA8) P_SW1;  // UART1, UART2, UART3, UART4
__sfr __at(0xBA) P_SW2;  // SPI, I2C

// SPI 寄存器 (STC32G)
__sfr __at(0xCD) SPSTAT;  // SPI 状态寄存器
__sfr __at(0xCE) SPCTL;   // SPI 控制寄存器
__sfr __at(0xCF) SPDAT;   // SPI 数据寄存器

// SPI 位定义
#define SPSTAT_SPIF   0x80  // 传输完成标志
#define SPSTAT_WCOL   0x40  // 写冲突标志
#define SPCTL_SPEN    0x40  // SPI 使能
#define SPCTL_MSTR    0x20  // 主机模式
#define SPCTL_CPOL    0x10  // 时钟极性
#define SPCTL_CPHA    0x08  // 时钟相位
#define SPCTL_SPR     0x07  // 时钟分频

// UART 寄存器
__sfr __at(0x8C) AUXR;   // 辅助寄存器
__sfr __at(0x98) SCON;   // 串口控制
__sfr __at(0x99) SBUF;   // 串口数据

// Timer2 寄存器
__sfr __at(0xC8) T2CON;
__sfr __at(0xC9) T2MOD;
__sfr __at(0xCA) RCAP2L;
__sfr __at(0xCB) RCAP2H;
__sfr __at(0xCC) TL2;
__sfr __at(0xCD) TH2;

// 系统时钟
#define FOSC 24000000UL

// 常用宏
#define TRUE 1
#define FALSE 0
#define OK 1
#define FAIL 0

// NOP 宏
#define _nop_() __asm__("nop")

#endif
