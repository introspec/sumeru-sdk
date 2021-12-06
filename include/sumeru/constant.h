#ifndef __SUMERU_CONSTANT_H
#define __SUMERU_CONSTANT_H

#include "cpu/constant.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UART0_RX_BUF_START    		0x1000
#define UART0_RX_BUF_END      		0x2000

#define UART0_TX_BUF_START    		0x2000
#define UART0_TX_BUF_END      		0x3000

#define UART1_RX_BUF_START   		0x3000
#define UART1_RX_BUF_END   		0x4000

#define UART1_TX_BUF_START        	0x4000
#define UART1_TX_BUF_END          	0x5000

#define UART2_RX_BUF_START        	0x5000
#define UART2_RX_BUF_END          	0x6000

#define UART2_TX_BUF_START        	0x6000
#define UART2_TX_BUF_END   		0x7000

#define ICTX_STACK_BOTTOM		0xE000
#define ICTX_STACK_TOP			0xEFF0

#define THREAD0_ADDR			0xF000				

/*  
 * SYS TIMER PERIOD		: (1/72000000)	= 0.000000013888 sec
 * SYS TIMER INTERVAL TICKS	: 655360
 * SYS TIMER INTERVAL		: (1/72000000 * INTERVAL) = 0.009101639680 sec
 */

#define SYS_TIMER_MIN_TICKS		16
#define SYS_TIMER_MIN_PERIOD_NS		222

#define SYS_TIMER_INTERVAL_TICKS	655360
#define SYS_TIMER_INTERVAL_PERIOD_NS	9101640


#define FLASH_BLOCK_SIZE		65536

#define FLASH_FIRMWARE_START		0	/* Start at 0 */
#define FLASH_FIRMWARE_END		7	/* 512K size */

#define FLASH_APP_START			8	/* Start at 512K */
#define FLASH_APP_END			39	/* 2M size */

#define FLASH_ROOT_FS_START		40	/* Start at 2.5M */
#define FLASH_ROOT_FS_END		63	/* 1.5M size */

#define ROOT_FS_ERASESIZE		65536
#define ROOT_FS_PROGSIZE		256

#ifdef __cplusplus
}
#endif

#include "cpu/periph.h"

#endif
