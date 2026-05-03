cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ip_module VERSION 0.1)

# ── Include paths ────────────────────────────────────────────────────────────
target_include_directories(app PUBLIC
    include
    src/port/zephyr/log
    src/port/zephyr/smf
    src/port/zephyr/threads
)

# ── Application sources ──────────────────────────────────────────────────────
target_sources(app PRIVATE
    src/app/app.c
)

# ── Core sources ─────────────────────────────────────────────────────────────
target_sources(app PRIVATE
    src/core/ip_module_events.c
    src/core/ip_module_sm.c
    src/core/ip_module_states.c
)
