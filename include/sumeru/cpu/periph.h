#ifndef __CPU_PERIPH_H
#define __CPU_PERIPH_H

#ifdef __cplusplus
extern "C" {
#endif

#define PERIPH_NONE		0
#define PERIPH_UART		1
#define PERIPH_SPI		2
#define PERIPH_I2C		3
#define PERIPH_PSEUDO		7

#define CPU_PERIPH_VERSION_MASK		(0xff << 24)
#define CPU_PERIPH_VERSION_0x11		(0x11 << 24)

/* MARK8_0x11 = 0x1105b490 */

#define CPU_PERIPH_MARK8_0x11 		(CPU_PERIPH_VERSION_0x11 | \
	(PERIPH_UART << 18) | \
	(PERIPH_I2C << 15) | \
	(PERIPH_I2C << 12) | \
	(PERIPH_SPI << 9) | \
	(PERIPH_SPI << 6) | \
	(PERIPH_SPI << 3))

#ifdef __cplusplus
}
#endif

#endif
