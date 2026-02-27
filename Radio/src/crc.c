// CRC 计算 - 简化版
#include "crc.h"

uint16_t crc16_calc(uint8_t *data, uint8_t len) {
    uint16_t crc = 0xFFFF;
    uint8_t i, j;
    
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if (crc & 0x0001)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc >>= 1;
        }
    }
    
    return crc;
}
