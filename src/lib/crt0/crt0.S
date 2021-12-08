#define _ASSEMBLER
#include <sumeru/constant.h>
#include "sys-struct-offset.h"

#define CRT0_MAJOR_VERSION	1
#define CRT0_MINOR_VERSION	(0 << 16)

#define CRT0_VERSION		(CRT0_MAJOR_VERSION | CRT0_MINOR_VERSION)	

#include "interrupt.S"

#=========================================================================
# crt0.S/_start : Entry point for SUMERU RISC-V binaries
#
#		CPU bootcode will transfer control to
#		interrupt-vector 0
#
#		As per the convention SP points to 
#		top of stack with the last valid value
#
#		SP(0) contains the processor version and 
#		processor device configuration.
#
#=========================================================================

.text
.global _start
.type   _start, @function
_start:
    csrrci 	zero, CSR_REG_INTR_CTRL, 0x1		# disable intr
    la 		a0, _ivector				
    csrrw 	zero, CSR_REG_IVECTOR_ADDR, a0		# set ivector

.option push
.option norelax
    1:auipc 	gp, %pcrel_hi(__global_pointer$)
    addi  	gp, gp, %pcrel_lo(1b)
.option pop
    sw 		gp, GTABLE_ICTX_GP(zero)		# set global ptr


    li 		tp, THREAD0_TP_ADDR
    sw 		tp, GTABLE_CURTHREAD_TP_ADDR(zero)

    # clear the bss segment
    la      	a0, _edata
    la      	a2, _end
    sub     	a2, a2, a0
    li      	a1, 0
    call    	memset

    ### do this early 
    call   	__init_libc_reent
    la 		a0, g_REENT
    lw 		a0, 0(a0)

    ### thread0 and interrupt context share the same REENT
    sw 		a0, GTABLE_ICTX_REENT(zero)	
    sw 		a0, TP_OFFSET_REENT(tp)

    ### thread0 uses static stack memory at the top of memory (~32M)
    # 	therefore its STACK location is zero to flag static
    #   allocation.
    sw 		zero, TP_OFFSET_STACK(tp)

    ### run gloal termination functions on exit
    #
    la		a0, __libc_fini_array
    call	atexit                  

    ### run global initialization functions
    call    	__libc_init_array

    li		a0, CRT0_VERSION
    lw		a1, 0(sp)

    ### call _sys_main
    la		a2, _sys_main 
    jalr	a2

    ### exit will soft reset the CPU and 
    ##  re-execute the CPU bootcode
    ##
    tail    	exit

.size  _start, .-_start
