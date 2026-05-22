/**
 * @file app.c
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief Application entry point
 * @version 0.1
 * @date 2026-05-17
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <log.h>
#include <sys.h>
#include <ip_module.h>

LOG_REGISTER(MAIN, CONFIG_IP_MODULE_LOG_LEVEL);

int
main(void)
{
    SysInit();

    // start_communication_thread();

    while (1)
    {
        PRINT_INF("Application Running");
        k_sleep(K_SECONDS(10));
    }

    return (0);
}