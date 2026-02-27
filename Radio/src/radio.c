// PAN3031 无线模块 - 简化应用层
#include "pan3031_port.h"
#include "radio.h"

// 外部驱动函数
extern uint32_t PAN3031_reset(void);
extern uint32_t PAN3031_init(void);
extern uint32_t PAN3031_set_freq(uint32_t freq);
extern uint32_t PAN3031_set_sf(uint8_t sf);
extern uint32_t PAN3031_set_bw(uint8_t bw);
extern uint32_t PAN3031_set_tx_power(uint8_t power);
extern uint32_t PAN3031_set_crc(uint8_t enable);
extern uint32_t PAN3031_send(uint8_t *data, uint8_t len);
extern uint32_t PAN3031_recv(uint8_t *data, uint8_t *len);
extern uint32_t PAN3031_start_rx(void);
extern uint32_t PAN3031_standby(void);
extern uint32_t PAN3031_sleep(void);
extern void PAN3031_clear_irq(void);
extern uint8_t PAN3031_get_irq(void);
extern bool PAN3031_tx_done(void);
extern bool PAN3031_rx_done(void);

// 全局状态
static radio_state_t radio_state = RADIO_STATE_IDLE;
static uint8_t tx_buf[64];
static uint8_t rx_buf[64];
static uint8_t tx_len = 0;
static uint8_t rx_len = 0;

// 初始化
uint32_t rf_init(void) {
    // 复位
    PAN3031_reset();
    
    // 初始化
    if (PAN3031_init() != OK)
        return FAIL;
    
    // 配置参数：434MHz, SF7, BW125K
    PAN3031_set_freq(434000000);
    PAN3031_set_sf(7);
    PAN3031_set_bw(7);  // 125K
    PAN3031_set_tx_power(20);
    PAN3031_set_crc(1);
    
    radio_state = RADIO_STATE_IDLE;
    return OK;
}

// 发送数据
uint32_t rf_send(uint8_t *data, uint8_t len) {
    if (len > 64)
        return FAIL;
    
    // 拷贝数据
    for (uint8_t i = 0; i < len; i++)
        tx_buf[i] = data[i];
    tx_len = len;
    
    // 发送
    PAN3031_send(tx_buf, tx_len);
    radio_state = RADIO_STATE_TX;
    
    return OK;
}

// 轮询发送状态
void rf_poll_tx(void) {
    if (radio_state != RADIO_STATE_TX)
        return;
    
    uint8_t irq = PAN3031_get_irq();
    
    if (irq & 0x01) {  // TX_DONE
        PAN3031_clear_irq();
        radio_state = RADIO_STATE_IDLE;
        PAN3031_start_rx();  // 回到接收模式
    }
}

// 开始接收
void rf_start_rx(void) {
    PAN3031_start_rx();
    radio_state = RADIO_STATE_RX;
}

// 轮询接收
uint32_t rf_poll_rx(uint8_t *data, uint8_t *len) {
    if (radio_state != RADIO_STATE_RX)
        return FAIL;
    
    uint8_t irq = PAN3031_get_irq();
    
    if (irq & 0x08) {  // RX_DONE
        PAN3031_recv(data, len);
        PAN3031_clear_irq();
        return OK;
    }
    
    return FAIL;
}

// 进入睡眠
void rf_sleep(void) {
    PAN3031_sleep();
    radio_state = RADIO_STATE_SLEEP;
}

// 获取状态
radio_state_t rf_get_state(void) {
    return radio_state;
}
