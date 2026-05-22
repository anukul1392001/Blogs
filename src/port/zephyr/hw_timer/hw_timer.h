/**
 * @file hw_timer.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief Hardware timer abstraction over Zephyr kernel timers
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */


#ifndef HW_TIMER_H
#define HW_TIMER_H

#include <stdint.h>
#include <kernel_utils.h>
#include <zephyr/kernel.h>

typedef void (*hw_timer_expiry_handler_t)(void *timer);
typedef void (*hw_timer_stop_handler_t)(void *timer);

typedef struct
{
    hw_timer_expiry_handler_t timer_expiry_handler;
    hw_timer_stop_handler_t   timer_stop_handler;
} hw_timer_handlers_t;

typedef hw_timer_handlers_t *Timer_handle_t;

// #define HW_TIMEOUT_MS(ms)    K_MSEC(ms)
// #define HW_TIMEOUT_S(s)      K_SECONDS(s)
// #define HW_TIMEOUT_US(us)    K_USEC(us)
// #define HW_TIMEOUT_NS(ns)    K_NSEC(ns)
// #define HW_TIMEOUT_FOREVER    K_FOREVER
// #define HW_TIMEOUT_NO_WAIT    K_NO_WAIT

// #define HW_MS_TO_TICKS(time)           k_ms_to_ticks_ceil64(time)
// #define HW_TICKS_TO_MS(ticks)          k_ticks_to_ms_ceil64(ticks)

// #define HW_S_TO_TICKS(time)            k_sec_to_ticks_ceil64(time)
// #define HW_TICKS_TO_S(ticks)           k_ticks_to_sec_ceil64(ticks)

// #define HW_TIMER_STOP(h)               k_timer_stop(&(h)->timer)
// #define HW_TIMER_STATUS_GET(h)         k_timer_status_get(&(h)->timer)
// #define HW_TIMER_STATUS_SYNC(h)        k_timer_status_sync(&(h)->timer)

// #define HW_TIMER_EXPIRES_TICKS(h)      k_timer_expires_ticks(&(h)->timer)
// #define HW_TIMER_REMAINING_TICKS(h)    k_timer_remaining_ticks(&(h)->timer)
// #define HW_TIMER_REMAINING_GET(h)      k_timer_remaining_get(&(h)->timer)


uint16_t hw_timer_register_timer_handlers(Timer_handle_t handler);

uint16_t hw_timer_start(timeout_t duration, timeout_t period);

#endif /* HW_TIMER_H */