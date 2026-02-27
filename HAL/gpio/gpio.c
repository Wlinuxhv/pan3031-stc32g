// GPIO 驱动 - STC32G
#include "gpio.h"
#include "STC32G.h"

// 初始化 GPIO
void GPIO_Init(void) {
    // P2 - SPI (已在 SPI_Init 中配置)
    
    // P3 - IRQ, RST, 其他控制
    // P3.2 IRQ - 输入
    P3M0 &= ~0x04;
    P3M1 &= ~0x04;
    
    // P3.3 RST - 输出
    P3M0 |= 0x08;
    P3M1 &= ~0x08;
    
    // P3.4 TX_EN - 输出
    P3M0 |= 0x10;
    P3M1 &= ~0x10;
    
    // P3.5 RX_EN - 输出
    P3M0 |= 0x20;
    P3M1 &= ~0x20;
    
    // P5.4 LED - 输出
    P5M0 |= 0x10;
    P5M1 &= ~0x10;
    
    // 初始状态
    P3 |= 0x08;  // RST 高
    P3 &= ~0x10; // TX_EN 低
    P3 &= ~0x20; // RX_EN 低
    P5 |= 0x10;  // LED 灭
}

// LED 控制
void LED1_ON(void) {
    P5 &= ~0x10;
}

void LED1_OFF(void) {
    P5 |= 0x10;
}

void LED1_TOGGLE(void) {
    P5 ^= 0x10;
}
