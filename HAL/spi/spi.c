// STC32G 硬件 SPI 驱动
// 基于 STC32G 数据手册 SPI 章节

#include "spi.h"
#include "STC32G.h"

// SPI 引脚定义 (使用硬件 SPI1)
// SCK:  P1.5
// MISO: P1.6  
// MOSI: P1.7
// CS:   P2.3 (软件控制)

void SPI1_Init(void) {
    // 1. 配置 GPIO 为 SPI 功能
    P_SW2 |= 0x10;  // 选择 SPI1 引脚位置
    
    // 2. 配置 GPIO 模式
    // SCK, MOSI - 推挽输出
    P1M0 |= 0xA0;  // P1.5, P1.6, P1.7
    P1M1 &= ~0xA0;
    
    // CS - 推挽输出
    P2M0 |= 0x08;  // P2.3
    P2M1 &= ~0x08;
    
    // 3. 初始状态
    P2 |= 0x08;  // CS 高
    
    // 4. 配置 SPI 控制寄存器
    // SPCTL = SPEN + MSTR + CPOL + CPHA
    // SPEN: 使能 SPI
    // MSTR: 主机模式
    // CPOL: 时钟极性 (空闲时高)
    // CPHA: 时钟相位 (第一个边沿采样)
    SPCTL = 0x54;  // 0101 0100
    
    // 5. 设置 SPI 时钟分频
    // SPSTAT = 0x00
    // 时钟 = Fosc / 4 = 24MHz / 4 = 6MHz
    SPCTL |= 0x00;  // 最快时钟
}

// 读写一个字节
uint8_t SPI1_ReadWriteByte(uint8_t data) {
    // 写入数据
    SPDAT = data;
    
    // 等待传输完成
    while (!(SPSTAT & 0x80));
    
    // 清除标志
    SPSTAT = 0xC0;
    
    // 返回接收的数据
    return SPDAT;
}

// CS 控制
void PAN3031_CS_HIGH(void) {
    P2 |= 0x08;
}

void PAN3031_CS_LOW(void) {
    P2 &= ~0x08;
}
