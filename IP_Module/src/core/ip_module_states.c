/**
 * @file ip_module_states.c
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief IP module state machine handlers and state table
 * @version 0.1
 * @date 2026-05-02
 *
 * @copyright Copyright (c) 2026
 *
 */


#include <smf.h>
#include <ip_module_states.h>

static smf_state_t ip_states[] = {
    [IP_STATE_INIT]         = STATE_CREATE(ip_state_init_entry,         ip_state_init_run,         NULL),
    [IP_STATE_CONNECTING]   = STATE_CREATE(ip_state_connecting_entry,   ip_state_connecting_run,   ip_state_connecting_exit),
    [IP_STATE_CONNECTED]    = STATE_CREATE(ip_state_connected_entry,    ip_state_connected_run,    ip_state_connected_exit),
    [IP_STATE_DISCONNECTED] = STATE_CREATE(ip_state_disconnected_entry, ip_state_disconnected_run, ip_state_disconnected_exit),
    [IP_STATE_FAILED]       = STATE_CREATE(ip_state_failed_entry,       ip_state_failed_run,       NULL)
};

void ip_state_init_entry(void *smObj)
{

}

void ip_state_init_run(void *smObj)
{

}

void ip_state_connecting_entry(void *smObj)
{

}

void ip_state_connecting_run(void *smObj)
{

}

void ip_state_connecting_exit(void *smObj)
{

}

void ip_state_connected_entry(void *smObj)
{

}

void ip_state_connected_run(void *smObj)
{

}

void ip_state_connected_exit(void *smObj)
{

}

void ip_state_disconnected_entry(void *smObj)
{

}

void ip_state_disconnected_run(void *smObj)
{

}

void ip_state_disconnected_exit(void *smObj)
{

}

void ip_state_failed_entry(void *smObj)
{

}

void ip_state_failed_run(void *smObj)
{
    
}