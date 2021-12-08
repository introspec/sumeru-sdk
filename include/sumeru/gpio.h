#ifndef __SUMERU_DEV_GPIO_H
#define __SUMERU_DEV_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*gpio_user_intr_callback_t)();

void	gpio_wait_intr();
void	gpio_set_user_intr_callback(gpio_user_intr_callback_t h);

#ifdef __cplusplus
}
#endif

#endif
