// PAN3031 简化驱动 - STC32G 移植版
// 只保留基本收发功能

#include "pan3031_port.h"

// 全局变量
static uint8_t current_page = 0;
static uint8_t irq_flags = 0;

// SPI 读写
static uint8_t spi_transfer(uint8_t data) {
    return rf_port.spi_readwrite(data);
}

// 写寄存器
static uint8_t write_reg(uint8_t addr, uint8_t value) {
    CS_LOW();
    spi_transfer(0x01 | (addr << 1));
    spi_transfer(value);
    CS_HIGH();
    return OK;
}

// 读寄存器
static uint8_t read_reg(uint8_t addr) {
    uint8_t value;
    CS_LOW();
    spi_transfer(0x00 | (addr << 1));
    value = spi_transfer(0x00);
    CS_HIGH();
    return value;
}

// 切换页面
static void select_page(page_sel_t page) {
    if (page != current_page) {
        write_reg(0x00, page);
        current_page = page;
    }
}

// 复位 PAN3031
uint32_t PAN3031_reset(void) {
    RST_LOW();
    rf_port.delay_ms(10);
    RST_HIGH();
    rf_port.delay_ms(50);
    return OK;
}

// 初始化
uint32_t PAN3031_init(void) {
    select_page(PAGE0_SEL);
    
    // 设置工作模式为待机
    write_reg(REG_OP_MODE, MODE_STBY);
    
    // 配置 GPIO
    write_reg(REG_GPIO_CTRL, 0x01);
    
    return OK;
}

// 设置频率 (单位 Hz)
uint32_t PAN3031_set_freq(uint32_t freq) {
    select_page(PAGE0_SEL);
    
    // 简化的频率设置
    // 实际需要根据 PLL 分频计算
    uint8_t freq_ctrl = (freq / 1000000) / 10;
    write_reg(REG_FREQ_CTRL, freq_ctrl);
    
    return OK;
}

// 设置扩频因子
uint32_t PAN3031_set_sf(uint8_t sf) {
    select_page(PAGE0_SEL);
    write_reg(REG_SF_BW, (sf - 7) << 4);
    return OK;
}

// 设置带宽
uint32_t PAN3031_set_bw(uint8_t bw) {
    select_page(PAGE0_SEL);
    uint8_t reg = read_reg(REG_SF_BW);
    reg = (reg & 0xF0) | (bw & 0x0F);
    write_reg(REG_SF_BW, reg);
    return OK;
}

// 设置发射功率
uint32_t PAN3031_set_tx_power(uint8_t power) {
    select_page(PAGE0_SEL);
    write_reg(REG_TX_POWER, power & 0x1F);
    return OK;
}

// 设置 CRC
uint32_t PAN3031_set_crc(uint8_t enable) {
    select_page(PAGE0_SEL);
    uint8_t reg = read_reg(REG_CR_CRC);
    if (enable)
        reg |= 0x01;
    else
        reg &= ~0x01;
    write_reg(REG_CR_CRC, reg);
    return OK;
}

// 发送数据
uint32_t PAN3031_send(uint8_t *data, uint8_t len) {
    select_page(PAGE0_SEL);
    
    // 设置 payload 长度
    write_reg(REG_PAYLOAD_LEN, len);
    
    // 写入 FIFO
    CS_LOW();
    spi_transfer(0x01 | (REG_FIFO_ACC_ADDR << 1));
    for (uint8_t i = 0; i < len; i++) {
        spi_transfer(data[i]);
    }
    CS_HIGH();
    
    // 切换到发射模式
    write_reg(REG_OP_MODE, MODE_TX);
    
    return OK;
}

// 接收数据
uint32_t PAN3031_recv(uint8_t *data, uint8_t *len) {
    select_page(PAGE0_SEL);
    
    // 读取 payload 长度
    *len = read_reg(REG_PAYLOAD_LEN);
    
    // 从 FIFO 读取
    CS_LOW();
    spi_transfer(0x00 | (REG_FIFO_ACC_ADDR << 1));
    for (uint8_t i = 0; i < *len; i++) {
        data[i] = spi_transfer(0x00);
    }
    CS_HIGH();
    
    return OK;
}

// 进入接收模式
uint32_t PAN3031_start_rx(void) {
    select_page(PAGE0_SEL);
    write_reg(REG_OP_MODE, MODE_RX);
    return OK;
}

// 进入待机模式
uint32_t PAN3031_standby(void) {
    select_page(PAGE0_SEL);
    write_reg(REG_OP_MODE, MODE_STBY);
    return OK;
}

// 进入睡眠模式
uint32_t PAN3031_sleep(void) {
    select_page(PAGE0_SEL);
    write_reg(REG_OP_MODE, MODE_SLEEP);
    return OK;
}

// 清除中断
void PAN3031_clear_irq(void) {
    select_page(PAGE0_SEL);
    write_reg(REG_IRQ_STATUS, 0xFF);
    irq_flags = 0;
}

// 读取中断状态
uint8_t PAN3031_get_irq(void) {
    select_page(PAGE0_SEL);
    irq_flags = read_reg(REG_IRQ_STATUS);
    return irq_flags;
}

// 检查 TX 完成
bool PAN3031_tx_done(void) {
    return (irq_flags & IRQ_TX_DONE) ? true : false;
}

// 检查 RX 完成
bool PAN3031_rx_done(void) {
    return (irq_flags & IRQ_RX_DONE) ? true : false;
}

// 获取 RSSI
int8_t PAN3031_get_rssi(void) {
    select_page(PAGE2_SEL);
    uint8_t rssi = read_reg(0x1A);
    return -(int8_t)rssi / 2;
}

// 获取 SNR
int8_t PAN3031_get_snr(void) {
    select_page(PAGE2_SEL);
    uint8_t snr = read_reg(0x1B);
    return (int8_t)snr / 4;
}
