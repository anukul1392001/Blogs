/**
 * @file hw_timer.c
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief
 * @version 0.1
 * @date 2026-05-20
 *
 * @copyright Copyright (c) 2026
 *
 */


#include <hw_timer.h>
#include <kernel_utils.h>
#include <common_error.h>

static struct k_timer timer;

static void on_hw_timer_expiry(struct k_timer *timer);
static void on_hw_timer_stop(struct k_timer *timer);

#ifndef _API_FUNCTIONS_

uint16_t
hw_timer_register_timer_handlers(Timer_handle_t handler)
{
    uint16_t err = ERR_OK;

    k_timer_init(&timer,
                 (NULL == handler->timer_expiry_handler) ? NULL : on_hw_timer_expiry,
                 (NULL == handler->timer_stop_handler) ? NULL : on_hw_timer_stop);

    k_timer_user_data_set(&timer, handler);

    return (err);
}


uint16_t
hw_timer_start(timeout_t duration, timeout_t period)
{
    uint16_t err = 0;

    const k_timeout_t duration_ticks = {
        .ticks = convert_to_ticks(duration)
    };

    const k_timeout_t period_ticks = {
        .ticks = convert_to_ticks(period)
    };

    k_timer_start(&timer, duration_ticks, period_ticks);

    return (err);
}


#endif /* _API_FUNCTIONS_ */

#ifndef _LOCAL_FUNCTIONS_

static void
on_hw_timer_expiry(struct k_timer *timer)
{
    Timer_handle_t handler = k_timer_user_data_get(timer);

    if (handler != NULL)
    {
        (handler->timer_expiry_handler)(timer);
    }
}


static void
on_hw_timer_stop(struct k_timer *timer)
{
    Timer_handle_t handler = k_timer_user_data_get(timer);

    if (handler != NULL)
    {
        (handler->timer_stop_handler)(timer);
    }
}


#endif /* _LOCAL_FUNCTIONS_ */