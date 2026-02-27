#include "pan3031_port.h"

rf_port_t rf_port = {
    .antenna_init = rf_antenna_init,
    .tcxo_init = rf_tcxo_init,
    .set_tx = rf_antenna_tx,
    .set_rx = rf_antenna_rx,
    .antenna_close = rf_antenna_close,
    .tcxo_close = rf_tcxo_close,
    .spi_readwrite = spi_readwritebyte,
    .spi_cs_high = spi_cs_set_high,
    .spi_cs_low = spi_cs_set_low,
    .delayms = rf_delay_ms,
    .delayus = rf_delay_us,
};

uint8_t spi_readwritebyte(uint8_t tx_data)
{
    return SPI1_ReadWriteByte(tx_data);
}

void spi_cs_set_high(void)
{
    PAN3031_CS_HIGH();
}

void spi_cs_set_low(void)
{
    PAN3031_CS_LOW();
}

void rf_delay_ms(uint32_t time)
{
    Delay_Ms(time);
}

void rf_delay_us(uint32_t time)
{
    Delay_Us(time);
}

void rf_antenna_init(void)
{
    PAN3031_TX_EN_LOW();
    PAN3031_RX_EN_LOW();
}

void rf_tcxo_init(void)
{
}

void rf_tcxo_close(void)
{
}

void rf_antenna_rx(void)
{
    PAN3031_TX_EN_LOW();
    PAN3031_RX_EN_HIGH();
}

void rf_antenna_tx(void)
{
    PAN3031_RX_EN_LOW();
    PAN3031_TX_EN_HIGH();
}

void rf_antenna_close(void)
{
    PAN3031_TX_EN_LOW();
    PAN3031_RX_EN_LOW();
}
