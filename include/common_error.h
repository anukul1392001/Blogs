/**
 * @file common_error.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief Generic error code definitions
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef COMMOM_ERROR_H
#define COMMOM_ERROR_H

#include <stdint.h>

typedef enum
{
    ERR_OK = 0,             /* Success                           */

    /* IP Module Specific Error Codes */
    IP_ERR_INVALID_PARAM,   /* One or more parameters invalid    */
    IP_ERR_INVALID_STATE,   /* Operation not valid in this state */
    IP_ERR_TIMEOUT,         /* Operation timed out               */
    IP_ERR_ALREADY_INIT,    /* Module already initialised        */
    IP_ERR_NOT_INIT,        /* Module not yet initialised        */

    ERR_MAX = UINT16_MAX    /* Max error code value              */
} err_t;

#endif /* COMMOM_ERROR_H */