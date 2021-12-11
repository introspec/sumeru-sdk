#include <sumeru/cpu/memctl.h>

#include "spi.h"
#include "spi_touch.h"
#include "timer.h"

#define TOUCH_FLAG_POLL_INPROGRESS	(1 << 0)

#define RCOUNT				4
#define DATA_LEN			(2 * RCOUNT + 4)

#define PRESS_THRESHOLD_LOW		1000
#define PRESS_THRESHOLD_HIGH		30000

#define X_END           		480
#define Y_END           		320

#define Y_COEF                          -0.01079198139
#define Y_OFFSET                        338.0504932

#define X_COEF                          0.01592380275
#define X_OFFSET                        23.21100478


static unsigned int 		s_touch_flag;
static unsigned int 		s_touch_state;
static int 			s_touch_x;
static int 			s_touch_y;
static touch_callback_t 	s_callback;
static short 			s_io_data[DATA_LEN];
static unsigned int 		s_unit;


#define ASYNC_TRANSCEIVE(b,l) \
    spi_async_transceive(s_unit, (char *)b, l, 0x2)

/* 0x91 -- x reading (lcd small side) left-to-right (left is wrt top) */
/* 0xd1 -- y reading (lcd big side) bot-to-top (top is fpc end)) */
/* 0xb1 -- z reading - touched or not */

static void touch_poll();

    
static void
memset_short(short *data, short b, unsigned int len)
{
    for (unsigned int i = 0; i < len; ++i)
        data[i] = b;
}


static int
average_short(short *data, unsigned int len)
{
    int x = 0;
    for (unsigned int i = 0; i < len; ++i)
        x += data[i];
    return (x / len);
}


static void 
intr_user_callback(unsigned int unit)
{
    if (s_touch_flag & TOUCH_FLAG_POLL_INPROGRESS) 
    {
	int x, y;

	spi_async_transceive_done(unit);
	s_touch_flag &= ~TOUCH_FLAG_POLL_INPROGRESS;

	if (s_io_data[3] < PRESS_THRESHOLD_LOW ||
	    s_io_data[3] > PRESS_THRESHOLD_HIGH) 
	{
	    if (s_touch_state & TOUCH_STATE_PRESSED) {
		s_touch_state &= ~(TOUCH_STATE_PRESSED | TOUCH_STATE_DRAG);
		if (s_callback)
		    (*s_callback)(unit, s_touch_state, s_touch_x, s_touch_y);
	    }
	    return;
	}

	y = average_short(s_io_data + 4 + (RCOUNT / 4), 
				RCOUNT - (RCOUNT / 4));

	x = average_short(s_io_data + RCOUNT + 4 + (RCOUNT / 4), 
				RCOUNT - (RCOUNT / 4));

	double dy = average_short(
                        s_io_data + 4 + (RCOUNT / 4),
                        RCOUNT - (RCOUNT / 4));

	dy = (dy * Y_COEF) + Y_OFFSET;
	y = dy;

	double dx = average_short(
                        s_io_data + RCOUNT + 4 + (RCOUNT / 4),
                        RCOUNT - (RCOUNT / 4));

	dx = (dx * X_COEF) - X_OFFSET;
	x = dx;

        x = (x >= X_END ? X_END : x);
        x = (x < 0 ? 0 : x);

        y = (y >= Y_END ? Y_END : y);
        y = (y < 0 ? 0 : y);


	if ((s_touch_state & TOUCH_STATE_PRESSED == 0) ||
	     s_touch_x != x || 
	     s_touch_y != y) 
	{
	    if (s_touch_state & TOUCH_STATE_PRESSED)
		s_touch_state |= TOUCH_STATE_DRAG;

	    s_touch_state |= TOUCH_STATE_PRESSED;
	    s_touch_x = x;
	    s_touch_y = y;
	    if (s_callback)
		(*s_callback)(unit, s_touch_state, s_touch_x, s_touch_y);
	}
    }
}


int
touch_start(unsigned int unit, touch_callback_t cb)
{

    s_callback = cb;
    s_touch_x = s_touch_y = 0;
    s_touch_flag = 0;
    s_touch_state = 0;
    s_unit = unit;
    spi_set_speed(unit, SPI_CLK_SEL_1p125M); 
    spi_set_user_intr_callback(unit, intr_user_callback);
    timer_set_poller(1, touch_poll);
    return 0;
}


void
touch_stop()
{
    timer_set_poller(1, 0);
    s_touch_state = 0;
}

    
static void
touch_poll()
{
    if ((s_touch_flag & TOUCH_FLAG_POLL_INPROGRESS) == 0) {
	memset_short(s_io_data, 0xB1, 4);
	memset_short(s_io_data + 4, 0x91, RCOUNT);
	memset_short(s_io_data + 4 + RCOUNT, 0xD1, RCOUNT);
	s_io_data[4 + (RCOUNT * 2) - 1] = 0xD0;
	s_touch_flag |= TOUCH_FLAG_POLL_INPROGRESS;
	ASYNC_TRANSCEIVE(s_io_data, DATA_LEN * sizeof(short));
    }
}
