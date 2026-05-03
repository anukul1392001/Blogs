/**
 * @file log.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief Logging abstraction layer over Zephyr's logging subsystem
 * @version 0.1
 * @date 2026-05-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef LOG_H
#define LOG_H

#include <zephyr/logging/log.h>

#define LOG_REGISTER(Name, Level)    LOG_MODULE_REGISTER(Name, Level)
#define LOG_DECLARE(Name)            LOG_MODULE_DECLARE(Name)

#define PRINT_ERR            LOG_ERR
#define PRINT_WRN            LOG_WRN
#define PRINT_INF            LOG_INF
#define PRINT_DBG            LOG_DBG

#define PRINT_HEXDUMP_ERR    LOG_HEXDUMP_ERR
#define PRINT_HEXDUMP_WRN    LOG_HEXDUMP_WRN
#define PRINT_HEXDUMP_INF    LOG_HEXDUMP_INF
#define PRINT_HEXDUMP_DBG    LOG_HEXDUMP_DBG

#define OFF                  LOG_LEVEL_OFF
#define ERR                  LOG_LEVEL_ERR
#define WRN                  LOG_LEVEL_WRN
#define INF                  LOG_LEVEL_INF
#define DBG                  LOG_LEVEL_DBG

#endif /* LOG_H */