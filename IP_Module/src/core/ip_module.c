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


#include <ip_module.h>
#include <ip_module_sm.h>

static struct sm_obj ip_module_sm;
static ip_module_ctx_t ip_module_ctx;

#ifndef _API_FUNCTIONS_

err_t
IPModuleInit(void *ctx)
{
    uint16_t err = ERR_OK;

    ip_module_ctx_t p_ctx = (ip_module_ctx_t *)ctx; 

    ip_module_sm.ip_ctx = &ip_module_ctx;

    ip_module_ctx.ip_config.ip_init_timeout = 100;
    ip_module_ctx.ip_config.ip_connect_timeout = 200;
    ip_module_ctx.ip_config.ip_disconnect_timeout = 100;

    ip_module_ctx.sm_state = IP_STATE_INIT;
    ip_module_ctx.next_state = IP_STATE_MAX;
    ip_module_ctx.sm_error = ERR_OK;

    return (err);
}


err_t
IPModuleRun(void *ctx)
{
    uint16_t err = ERR_OK;
    
    return (err);
}


#endif /* _API_FUNCTIONS_ */


#ifndef _LOCAL_FUNCTIONS_

#endif /* _LOCAL_FUNCTIONS_ */