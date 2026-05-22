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

#include <hw_timer.h>
#include <ip_module_states.h>

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
    phy_type_t          phy_type;

    hw_timer_handlers_t timer_handler;

    ip_module_config_t  ip_config;

    ip_state_t          sm_state;
    ip_state_t          next_state;

    uint16_t            sm_error;
} ip_module_ctx_t;


uint16_t IPModuleInit(void *ctx);
uint16_t IPModuleRun(void *ctx);

#endif /* IP_MODULE_H */