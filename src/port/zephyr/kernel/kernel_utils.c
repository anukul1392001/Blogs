/**
 * @file kernel_utils.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-05-23
 *
 * @copyright Copyright (c) 2026
 *
 */


#include <zephyr/kernel.h>
#include <kernel_utils.h>

#ifndef _API_FUNCTIONS_

int64_t
convert_to_ticks(timeout_t value)
{
    int64_t     ticks   = 0;
    k_timeout_t timeout = { 0 };

    switch (value.unit)
    {
    case T_US:
        timeout = K_USEC(value.dimension);
        break;

    case T_MS:
        timeout = K_MSEC(value.dimension);
        break;

    case T_S:
        timeout = K_SECONDS(value.dimension);
        break;

    case T_MIN:
        timeout = K_MINUTES(value.dimension);
        break;

    case T_HOUR:
        timeout = K_HOURS(value.dimension);
        break;

    case T_FOREVER:
        timeout = K_FOREVER;
        break;

    case T_NO_WAIT:
    default:
    {
        timeout = K_NO_WAIT;
    }
    }

    ticks = timeout.ticks;

    return (ticks);
}


#endif /* _API_FUNCTIONS_ */