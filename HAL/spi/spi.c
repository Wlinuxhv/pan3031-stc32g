// SPI 驱动 - STC32G 软件模拟
#include "spi.h"
#include "STC32G.h"

// 引脚定义 (P2.0-P2.3)
#define SCK_PIN     0x01  // P2.0
#define MISO_PIN    0x02  // P2.1
#define MOSI_PIN    0x04  // P2.2
#define CS_PIN      0x08  // P2.3

// 初始化 SPI GPIO
void SPI1_Init(void) {
    // 设置为推挽输出
    P2M0 |= (SCK_PIN | MOSI_PIN | CS_PIN);
    P2M1 &= ~(SCK_PIN | MOSI_PIN | CS_PIN);
    
    // MISO 设置为输入
    P2M0 &= ~MISO_PIN;
    P2M1 &= ~MISO_PIN;
    
    // 初始状态
    P2 |= SCK_PIN;  // SCK 高
    P2 |= CS_PIN;   // CS 高
}

// 读写一个字节
uint8_t SPI1_ReadWriteByte(uint8_t data) {
    uint8_t i;
    uint8_t result = 0;
    
    for (i = 0; i < 8; i++) {
        // 输出 MOSI
        if (data & 0x80)
            P2 |= MOSI_PIN;
        else
            P2 &= ~MOSI_PIN;
        
        data <<= 1;
        
        // SCK 高，读取 MISO
        P2 &= ~SCK_PIN;
        __asm__("nop");
        __asm__("nop");
        P2 |= SCK_PIN;
        
        // 读取 MISO
        result <<= 1;
        if (P2 & MISO_PIN)
            result |= 0x01;
    }
    
    return result;
}

// CS 高
void PAN3031_CS_HIGH(void) {
    P2 |= CS_PIN;
}

// CS 低
void PAN3031_CS_LOW(void) {
    P2 &= ~CS_PIN;
}
