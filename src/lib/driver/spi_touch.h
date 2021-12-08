#ifndef SUMERU_SPI_TOUCH_H
#define SUMERU_SPI_TOUCH_H

#ifdef __cplusplus
extern "C" {
#endif

#define TOUCH_MAX_X		320
#define TOUCH_MAX_Y		480

#define TOUCH_STATE_PRESSED    	(1 << 0)        
#define TOUCH_STATE_DRAG    	(1 << 1)        


typedef void (*touch_callback_t)(
			unsigned int unit, 
			unsigned int state,
			int x, int y);

int	touch_start(unsigned int unit, touch_callback_t cb);
void	touch_stop();

#ifdef __cplusplus
}
#endif

#endif
