/**
 * @file ip_module.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief IP module public API
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IP_MODULE_H
#define IP_MODULE_H

#include <common_error.h>
#include <ip_module_states.h>
#include <hw_timer.h>

typedef enum
{
    PHY_WIFI = 0,
    PHY_LTE
} phy_type_t;

typedef struct
{
    uint16_t ip_init_timeout;
    uint16_t ip_connect_timeout;
    uint16_t ip_disconnect_timeout;
} ip_module_config_t;

typedef struct
{
    phy_type_t         phy_type;

    timer_handler_t    hw_timer;

    ip_module_config_t ip_config;

    ip_state_t         sm_state;
    ip_state_t         next_state;

    err_t              sm_error;
} ip_module_ctx_t;


err_t IPModuleInit(void *ctx);
err_t IPModuleRun(void *ctx);

#endif /* IP_MODULE_H */