/**
 * @file ip_module_sm.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief IP module state machine internal types and SM API
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IP_MODULE_SM_H
#define IP_MODULE_SM_H

#include <smf.h>
#include <ip_module.h>

struct sm_obj
{
    struct smf_ctx   ctx;
    ip_module_ctx_t *ip_ctx;
};

uint16_t ip_module_sm_run(ip_state_t state);

#endif /* IP_MODULE_SM_H */