#ifndef __PAN3031_PORT_H__
#define __PAN3031_PORT_H__

#include "STC32G.h"
#include <stdint.h>
#include <stdbool.h>

// PAN3031 寄存器定义
#define REG_SYS_CTL           0x00
#define REG_FIFO_ACC_ADDR     0x01
#define REG_OP_MODE           0x02
#define REG_PAYLOAD_LEN       0x0C
#define REG_IRQ_STATUS        0x10
#define REG_IRQ_MASK          0x11
#define REG_FREQ_CTRL         0x20
#define REG_MOD_CTRL          0x21
#define REG_SF_BW             0x22
#define REG_CR_CRC            0x23
#define REG_TX_POWER          0x24
#define REG_PREAMBLE          0x25
#define REG_SYNC_WORD         0x26
#define REG_GPIO_CTRL         0x30
#define REG_AGC_CTRL          0x31
#define REG_RSSI_THRESH       0x32
#define REG_TIMEOUT_CTRL      0x33

// 工作模式
#define MODE_DEEP_SLEEP       0x00
#define MODE_SLEEP            0x01
#define MODE_STBY             0x02
#define MODE_TX               0x03
#define MODE_RX               0x04

// IRQ 标志
#define IRQ_TX_DONE           0x01
#define IRQ_RX_DONE           0x08
#define IRQ_CRC_ERR           0x04
#define IRQ_TIMEOUT           0x02

// GPIO 定义
#define RF_NSS_PORT           P2
#define RF_NSS_PIN            0x08  // P2.3
#define RF_IRQ_PORT           P3
#define RF_IRQ_PIN            0x04  // P3.2
#define RF_RST_PORT           P3
#define RF_RST_PIN            0x08  // P3.3



// SPI 宏
#define CS_LOW()              (RF_NSS_PORT &= ~RF_NSS_PIN)
#define CS_HIGH()             (RF_NSS_PORT |= RF_NSS_PIN)
#define IRQ_READ()            ((RF_IRQ_PORT & RF_IRQ_PIN) ? 1 : 0)
#define RST_LOW()             (RF_RST_PORT &= ~RF_RST_PIN)
#define RST_HIGH()            (RF_RST_PORT |= RF_RST_PIN)

// 类型定义
typedef enum {
    PAGE0_SEL = 0,
    PAGE1_SEL = 1,
    PAGE2_SEL = 2,
    PAGE3_SEL = 3
} page_sel_t;

typedef struct {
    uint8_t (*spi_readwrite)(uint8_t);
    void (*cs_high)(void);
    void (*cs_low)(void);
    void (*delay_ms)(uint32_t);
    void (*delay_us)(uint32_t);
} rf_port_t;

// 函数声明
uint8_t SPI1_ReadWriteByte(uint8_t data);
void PAN3031_CS_HIGH(void);
void PAN3031_CS_LOW(void);
void Delay_Ms(uint32_t ms);
void Delay_Us(uint32_t us);

extern rf_port_t rf_port;

#endif
