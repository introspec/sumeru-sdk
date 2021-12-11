#ifndef __SUMERU_OS_H
#define __SUMERU_OS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <sumeru/cpu/csr.h>
#include <sumeru/cpu/memctl.h>
#include <sumeru/constant.h>

#include "thread.h"

#define OS_VERSION		"SUMERU-01.00"
#define enable_all_intr()	csr_intr_ctrl_set(1)
#define disable_all_intr()	csr_intr_ctrl_clr(1)

/*
 * Functions _sys_main and _sys_handle_interrupt are only called by 
 * the crt0 (startup and interrupt) code.
 */

/*
 * _sys_main is called with 
 * 	(a) interrupts disabed
 *	(b) GTABLE ICTX_GP, GTABLE_ICTX_REENT and GTABLE_CURTHREAD set
 * 	(c) Thread-0 REENT and STACKMEM set
 *
 * 	Among other things _sys_main should
 * 		configure devices
 * 		enable interrupts
 * 		start uart services
 * 		start timer service
 * 		call main
 *
 *
 * If _sys_main returns, control is transferred to the bootloader.
 * 
 */

void		_sys_main(
			unsigned int crt0_version, 
			unsigned int periph_cfg);


/*
 * _sys_interrupt_handler
 *
 *	id is INTR_ID_1, INTR_ID_2 ... , INTR_ID_15
 *
 *	Handler should return zero if control should return to the
 *	interrupted thread or it should return a thread pointer 
 *	to switch to another thread.
 */

thread_t*	_sys_handle_interrupt(unsigned int id);

typedef struct _sys_timeval {
    uint64_t	tv_sec;
    uint64_t	tv_usec;
} _sys_timeval_t;

void		_sys_gettimeofday_r(_sys_timeval_t *tv);
void		_sys_waitms(unsigned int ms);
void		_sys_difftime(uint64_t a, uint64_t b, _sys_timeval_t *tv);

#ifdef __cplusplus
}
#endif

#endif
