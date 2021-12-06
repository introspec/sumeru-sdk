#ifndef __SUMERU_STRUCT_OFFSET_H
#define __SUMERU_STRUCT_OFFSET_H

#ifdef __cplusplus
extern "C" {
#endif

#define GTABLE_BASE			0x10

#define GTABLE_ICTX_SCRATCH_0		(GTABLE_BASE + 0)
#define GTABLE_ICTX_SCRATCH_1		(GTABLE_BASE + 4)
#define GTABLE_ICTX_GP			(GTABLE_BASE + 8)
#define GTABLE_ICTX_REENT		(GTABLE_BASE + 12)
#define GTABLE_CURTHREAD_TP_ADDR	(GTABLE_BASE + 16)

#ifndef _ASSEMBLER
static inline uint32_t 
gtable_get(uint32_t addr)
{
    return *(uint32_t*)addr;
}
#endif


#define TP_OFFSET_PC                	(128 - 4)
#define TP_OFFSET_STACK			(128 + 0)
#define TP_OFFSET_REENT			(128 + 4)

#ifdef __cplusplus
}
#endif

#endif

