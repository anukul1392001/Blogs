/**
 * @file ip_module.c
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief IP module public API implementation
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */


#include <common_error.h>
#include <ip_module.h>
#include <ip_module_sm.h>

static struct sm_obj   ip_module_sm;
static ip_module_ctx_t ip_module_ctx;

static void ip_module_state_run_timer_expiry(void *timer);
static void ip_module_state_run_timer_stop(void *timer);

#ifndef _API_FUNCTIONS_

uint16_t
IPModuleInit(void *ctx)
{
    uint16_t err = ERR_OK;

    (void)ctx;

    ip_module_sm.ip_ctx = &ip_module_ctx;

    ip_module_ctx.phy_type = PHY_WIFI;

    ip_module_ctx.ip_config.ip_init_timeout       = 100;
    ip_module_ctx.ip_config.ip_connect_timeout    = 200;
    ip_module_ctx.ip_config.ip_disconnect_timeout = 100;


    ip_module_ctx.timer_handler.timer_expiry_handler = ip_module_state_run_timer_expiry;
    ip_module_ctx.timer_handler.timer_stop_handler   = ip_module_state_run_timer_stop;

    err = hw_timer_register_timer_handlers(&ip_module_ctx.timer_handler);
    if (ERR_OK != err)
    {
        return (err);
    }

    ip_module_ctx.sm_state   = IP_STATE_INIT;
    ip_module_ctx.next_state = IP_STATE_MAX;
    ip_module_ctx.sm_error   = ERR_OK;

    return (err);
}


uint16_t
IPModuleRun(void *ctx)
{
    uint16_t err = ERR_OK;

    // Run different state from here
    // ip_module_sm_run()

    return (err);
}


#endif /* _API_FUNCTIONS_ */


#ifndef _LOCAL_FUNCTIONS_

static void
ip_module_state_run_timer_expiry(void *timer)
{
}


static void
ip_module_state_run_timer_stop(void *timer)
{
}


#endif /* _LOCAL_FUNCTIONS_ */