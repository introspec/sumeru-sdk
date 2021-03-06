#define IVEC_DEF(nr) \
ivec_##nr: \
    sw a0, GTABLE_ICTX_SCRATCH_0(zero);	\
    li a0, INTR_ID_##nr;		\
    j asm_handle_interrupt;		\
    nop;


.section .text.ivector
.global _sys_restore_caller_registers_and_switch
.global _sys_save_callee_registers_and_switch
.global _ivector

_ivector:
ivec_boot:
    j _start
    nop 
    nop
    nop

IVEC_DEF(1)
IVEC_DEF(2)
IVEC_DEF(3)
IVEC_DEF(4)
IVEC_DEF(5)
IVEC_DEF(6)
IVEC_DEF(7)
IVEC_DEF(8)
IVEC_DEF(9)
IVEC_DEF(10)
IVEC_DEF(11)
IVEC_DEF(12)
IVEC_DEF(13)
IVEC_DEF(14)
IVEC_DEF(15)

asm_handle_interrupt:
    #
    # Reload the correct thead pointer (tp) 
    # as it may be modified by the process
    #

    sw tp, GTABLE_ICTX_SCRATCH_1(zero)
    lw tp, GTABLE_CURTHREAD_TP_ADDR(zero) # x4

    sw ra, 0(tp)			# x1
    sw sp, 4(tp)			# x2
    sw gp, 8(tp)			# x3

    lw ra, GTABLE_ICTX_SCRATCH_1(zero)	# S1 contains original tp
    sw ra, 12(tp)
    
    sw x5, 16(tp)
    sw x6, 20(tp)
    sw x7, 24(tp)

    lw ra, GTABLE_ICTX_SCRATCH_0(zero)	# S0 contains original x10 (a0)
    sw ra, 28(tp)

    sw x11, 32(tp)
    sw x12, 36(tp)
    sw x13, 40(tp)
    sw x14, 44(tp)
    sw x15, 48(tp)
    sw x16, 52(tp)
    sw x17, 56(tp)
    sw x28, 60(tp)
    sw x29, 64(tp)
    sw x30, 68(tp)
    sw x31, 72(tp)

    # -- Update thread PC
    csrrsi a1, CSR_REG_CTX_SAVED_PC, 0
    sw a1, TP_OFFSET_PC(tp)

    # -- We use a private stack for intr context
    li sp, ICTX_STACK_TOP

    # -- Load interrupt context global pointer
    lw gp, GTABLE_ICTX_GP(zero)

    # -- Load interrupt context reent struct
    lw a1, GTABLE_ICTX_REENT(zero)
    la a2, g_REENT
    sw a1, 0(a2)

#==========================================================================

    call _sys_handle_interrupt
    bnez a0, _sys_save_callee_registers_and_switch

#==========================================================================

_sys_restore_caller_registers_and_switch:

    # Switch to thread in tp, restore g_REENT
    #
    # Note: In the present scheme, g_REENT is set at thread creation
    # and not modified thereafter, therefore we never save the dynamic
    # value of the thread's g_REENT. This strategy will break threads
    # that change their g_REENT at runtime, for that to work we need 
    # to update the thread specific THREAD_REENT too.
    #

    lw a1, TP_OFFSET_REENT(tp)
    la a2, g_REENT
    sw a1, 0(a2)

    # Restore thread registers 
    lw ra, 0(tp)			# x1
    lw sp, 4(tp)			# x2
    lw gp, 8(tp)			# x3

    lw x5, 16(tp)
    lw x6, 20(tp)
    lw x7, 24(tp)
    # x10 restored below
    lw x11, 32(tp)
    lw x12, 36(tp)
    lw x13, 40(tp)
    lw x14, 44(tp)
    lw x15, 48(tp)
    lw x16, 52(tp)
    lw x17, 56(tp)
    lw x28, 60(tp)
    lw x29, 64(tp)
    lw x30, 68(tp)
    lw x31, 72(tp)

    lw a0, TP_OFFSET_PC(tp)
    csrrw  zero, CSR_REG_CTX_SWITCH_PC, a0

    lw a0, 28(tp)			# x10
    lw tp, 12(tp)			# x4
    csrrwi zero, CSR_REG_CTX_SWITCH, 0
    #******* not reached ***********

_sys_save_callee_registers_and_switch:

    # Saves callee registers to tp and switch to thread in a0

    sw x8, 76(tp)
    sw x9, 80(tp)
    sw x18, 84(tp)
    sw x19, 88(tp)
    sw x20, 92(tp)
    sw x21, 96(tp)
    sw x22, 100(tp)
    sw x23, 104(tp)
    sw x24, 108(tp)
    sw x25, 112(tp)
    sw x26, 116(tp)
    sw x27, 120(tp)

    mv tp, a0

    lw x8, 76(tp)
    lw x9, 80(tp)
    lw x18, 84(tp)
    lw x19, 88(tp)
    lw x20, 92(tp)
    lw x21, 96(tp)
    lw x22, 100(tp)
    lw x23, 104(tp)
    lw x24, 108(tp)
    lw x25, 112(tp)
    lw x26, 116(tp)
    lw x27, 120(tp)

    j _sys_restore_caller_registers_and_switch
    
