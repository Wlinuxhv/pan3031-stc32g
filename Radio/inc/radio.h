#ifndef __RADIO_H__
#define __RADIO_H__

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    RADIO_STATE_IDLE = 0,
    RADIO_STATE_TX,
    RADIO_STATE_RX,
    RADIO_STATE_SLEEP
} radio_state_t;

// 函数声明
uint32_t rf_init(void);
uint32_t rf_send(uint8_t *data, uint8_t len);
void rf_poll_tx(void);
void rf_start_rx(void);
uint32_t rf_poll_rx(uint8_t *data, uint8_t *len);
void rf_sleep(void);
radio_state_t rf_get_state(void);

#endif
