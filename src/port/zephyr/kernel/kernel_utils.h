/**
 * @file kernel_utils.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2026-05-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef KERNEL_UTILS_H
#define KERNEL_UTILS_H

#include <stdint.h>

#define HW_TIMEOUT_MS(ms)    K_MSEC(ms)
#define HW_TIMEOUT_S(s)      K_SECONDS(s)
#define HW_TIMEOUT_US(us)    K_USEC(us)
#define HW_TIMEOUT_NS(ns)    K_NSEC(ns)
#define HW_TIMEOUT_FOREVER    K_FOREVER
#define HW_TIMEOUT_NO_WAIT    K_NO_WAIT


typedef enum
{
    T_NO_WAIT = 0,
    T_US,
    T_MS,
    T_S,
    T_MIN,
    T_HOUR,
    T_FOREVER,

    T_MAX = UINT8_MAX
} timeout_unit_t;


typedef struct
{
    uint16_t       dimension;
    timeout_unit_t unit;
} timeout_t;


int64_t convert_to_ticks(timeout_t value);

#endif /* KERNEL_UTILS_H */