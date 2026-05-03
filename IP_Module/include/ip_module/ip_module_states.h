/**
 * @file ip_module_states.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief IP module state enumeration
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IP_MODULE_STATES_H
#define IP_MODULE_STATES_H

#include <stdint.h>

typedef enum
{
    IP_STATE_INIT = 0,
    IP_STATE_CONNECTING,
    IP_STATE_CONNECTED,
    IP_STATE_DISCONNECTED,
    IP_STATE_FAILED,

    IP_STATE_MAX = UINT8_MAX
} ip_state_t;


void ip_state_init_entry(void *smObj);
void ip_state_init_run(void *smObj);

void ip_state_connecting_entry(void *smObj);
void ip_state_connecting_run(void *smObj);
void ip_state_connecting_exit(void *smObj);

void ip_state_connected_entry(void *smObj);
void ip_state_connected_run(void *smObj);
void ip_state_connected_exit(void *smObj);

void ip_state_disconnected_entry(void *smObj);
void ip_state_disconnected_run(void *smObj);
void ip_state_disconnected_exit(void *smObj);

void ip_state_failed_entry(void *smObj);
void ip_state_failed_run(void *smObj);


#endif /* IP_MODULE_STATES_H */