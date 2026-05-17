/**
 * @file sys.c
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief System initialization implementation
 * @version 0.1
 * @date 2026-05-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <sys.h>
#include <hw_timer.h>

static hw_timer_t timer_ctx;

#ifndef _API_FUNCTIONS_

void
sys_init(void)
{
    /* Initialize HW Timer */
    HW_TIMER_INIT(&timer_ctx, timer_ctx.timer_expiry_handler, timer_ctx.timer_stop_handler);
}

#endif /* _API_FUNCTIONS_ */
