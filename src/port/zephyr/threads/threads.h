/**
 * @file threads.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief Thread abstraction layer over Zephyr's kernel threading primitives
 * @version 0.1
 * @date 2026-05-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef THREADS_H
#define THREADS_H

#include <zephyr/kernel.h>

/* ── Thread definition ──────────────────────────────────────────────────── */

#define THREAD_DEFINE(name, stack_size, entry, p1, p2, p3, prio, delay) \
        K_THREAD_DEFINE(name, stack_size, entry, p1, p2, p3, prio, 0, delay)

#define THREAD_STACK_DEFINE(name, size)    K_THREAD_STACK_DEFINE(name, size)

#define THREAD_CREATE(tid, stack, stack_size, entry, p1, p2, p3, prio, delay) \
        k_thread_create(tid, stack, stack_size, entry, p1, p2, p3, prio, 0, delay)

#define THREAD_START(tid)            k_thread_start(tid)
#define THREAD_ABORT(tid)            k_thread_abort(tid)
#define THREAD_JOIN(tid, timeout)    k_thread_join(tid, timeout)
#define THREAD_SELF()                k_current_get()
#define THREAD_YIELD()               k_yield()

/* ── Sleep ──────────────────────────────────────────────────────────────── */

#define SLEEP_MS(ms)    k_msleep(ms)
#define SLEEP_US(us)    k_usleep(us)
#define SLEEP_S(s)      k_sleep(K_SECONDS(s))

/* ── Timeouts ───────────────────────────────────────────────────────────── */

#define TIMEOUT_MS(ms)    K_MSEC(ms)
#define TIMEOUT_S(s)      K_SECONDS(s)
#define TIMEOUT_FOREVER    K_FOREVER
#define TIMEOUT_NO_WAIT    K_NO_WAIT

/* ── Mutex ──────────────────────────────────────────────────────────────── */

#define MUTEX_DEFINE(name)        K_MUTEX_DEFINE(name)
#define MUTEX_INIT(m)             k_mutex_init(m)
#define MUTEX_LOCK(m, timeout)    k_mutex_lock(m, timeout)
#define MUTEX_UNLOCK(m)           k_mutex_unlock(m)

/* ── Semaphore ──────────────────────────────────────────────────────────── */

#define SEM_DEFINE(name, init, limit)    K_SEM_DEFINE(name, init, limit)
#define SEM_INIT(s, init, limit)         k_sem_init(s, init, limit)
#define SEM_GIVE(s)                      k_sem_give(s)
#define SEM_TAKE(s, timeout)             k_sem_take(s, timeout)
#define SEM_COUNT(s)                     k_sem_count_get(s)
#define SEM_RESET(s)                     k_sem_reset(s)

#endif /* THREADS_H */