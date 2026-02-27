// 延时驱动 - STC32G (24MHz)
#include "delay.h"
#include "STC32G.h"

void Delay_Init(void) {
    // 无需特殊初始化
}

void Delay_Ms(uint32_t ms) {
    uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 2400; j++);
    }
}

void Delay_Us(uint32_t us) {
    uint32_t i;
    for (i = 0; i < us; i++) {
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
    }
}
