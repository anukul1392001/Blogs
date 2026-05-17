cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ip_module VERSION 0.1)

# ── Include paths ────────────────────────────────────────────────────────────
set(ZEPHYR_PORT_INCLUDE_DIRS
    src/port/zephyr/log
    src/port/zephyr/smf
    src/port/zephyr/threads
    src/port/zephyr/hw_timer
)

target_include_directories(app PRIVATE
    include
    include/ip_module
    ${ZEPHYR_PORT_INCLUDE_DIRS}
)

# ── Application sources ──────────────────────────────────────────────────────
target_sources(app PRIVATE
    src/app/app.c
)

# ── Optional module sources ──────────────────────────────────────────────────
if(CONFIG_IP_MODULE)
    target_sources(app PRIVATE
        src/core/ip_module/ip_module.c
        src/core/ip_module/ip_module_sm.c
        src/core/ip_module/ip_module_states.c
    )
endif()

target_sources(app PRIVATE
    src/core/sys.c
)

# Add future modules using the same pattern:
#
# if(CONFIG_OTHER_MODULE)
#     target_sources(app PRIVATE
#         src/core/other_module.c
#     )
# endif()
