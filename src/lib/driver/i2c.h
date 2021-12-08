#ifndef __SUMERU_DEV_I2C_H
#define __SUMERU_DEV_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*i2c_user_intr_callback_t)(unsigned int unit);

int	i2c_transceive(
	    unsigned int unit,
	    char *buf, unsigned int len, 
	    unsigned char addr);

void	i2c_async_transceive(
	    unsigned int unit,
	    char *buf, unsigned int len, 
	    unsigned char addr);

int	i2c_async_transceive_done(unsigned int unit);

int	i2c_set_speed(unsigned int unit, unsigned char clk_sel);

void	i2c_set_user_intr_callback(
	    unsigned int unit, i2c_user_intr_callback_t h);

#ifdef __cplusplus
}
#endif

#endif
