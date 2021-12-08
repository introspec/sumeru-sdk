#ifndef __SUMERU_DEV_SPI_H
#define __SUMERU_DEV_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*spi_user_intr_callback_t)(unsigned int unit);

int	spi_transceive(
	    unsigned int unit,
	    char *buf, unsigned int len, 
	    unsigned char aux);

void	spi_async_transceive(
	    unsigned int unit,
	    char *buf, unsigned int len, 
	    unsigned char aux);

int	spi_async_transceive_done(unsigned int unit);

int	spi_set_speed(unsigned int unit, unsigned char clk_sel);

void	spi_set_user_intr_callback(
	    unsigned int unit, spi_user_intr_callback_t h);

#ifdef __cplusplus
}
#endif

#endif
