#include <sumeru/constant.h>
#include <sumeru/cpu/csr.h>

#include "device.h"
#include "sys.h"

void
_sys_gettimeofday(_sys_timeval_t *tv)
{
    uint64_t t, z;
    uint32_t x;

    do {
    	x = rdtime_h();
	t = x;
    	t <<= 32;
    	t |= rdtime();
    } while (rdtime_h() != x);

    z = t / CPU_CLK_FREQ;
    tv->tv_sec = z;
    t = t - (z * CPU_CLK_FREQ);
    tv->tv_usec = t / CPU_CLK_TICKS_PER_US;
}


void
_sys_waitms(unsigned int ms)
{
    struct _sys_timeval tv;
    uint64_t a, b;

    _sys_gettimeofday(&tv);
    a = (tv.tv_sec * 1000000) + tv.tv_usec;
    a /= 1000;
    a += ms;
    while (1) {
        _sys_gettimeofday(&tv);
        b = (tv.tv_sec * 1000000) + tv.tv_usec;
        b /= 1000;
        if (b >= a)
            break;
    }
}


void
_sys_difftime(uint64_t a, uint64_t b, _sys_timeval_t *tv)
{
    uint64_t t, z;

    if (b > a) {
	t = b;
	b = a;
	a = t;
    }

    t = a - b;
    z = t / CPU_CLK_FREQ;
    tv->tv_sec = z;
    t = t - (z * CPU_CLK_FREQ);
    tv->tv_usec = t / CPU_CLK_TICKS_PER_US;
}
