/**
 * @file smf.h
 * @author Anukul Anand (kool@anukul-a.com)
 * @brief SMF abstraction layer over Zephyr's State Machine Framework
 * @version 0.1
 * @date 2026-05-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef SMF_H
#define SMF_H

#include <zephyr/smf.h>

typedef struct smf_state        smf_state_t;
typedef enum smf_state_result   smf_state_result_t;

/* ── State creation ─────────────────────────────────────────────────────── */

/* Create a flat state (no parent, no initial sub-state) */
#define STATE_CREATE(entry, run, exit) \
        SMF_CREATE_STATE(entry, run, exit, NULL, NULL)

/* Create a hierarchical state with a parent */
#define STATE_CREATE_WITH_PARENT(entry, run, exit, parent) \
        SMF_CREATE_STATE(entry, run, exit, parent, NULL)

/* Create a parent state that has an initial child sub-state */
#define STATE_CREATE_PARENT(entry, run, exit, parent, initial) \
        SMF_CREATE_STATE(entry, run, exit, parent, initial)

/* ── Context ────────────────────────────────────────────────────────────── */

/* Cast a user-defined object pointer to smf_ctx */
#define SM_CTX(obj)    SMF_CTX(obj)

/* ── Lifecycle ──────────────────────────────────────────────────────────── */

/* Initialise the state machine and set the initial state */
#define SM_SET_INITIAL(ctx, init_state)    smf_set_initial(ctx, init_state)

/* Transition to a new state */
#define SM_SET_STATE(ctx, new_state)       smf_set_state(ctx, new_state)

/* Terminate the state machine with a reason code */
#define SM_TERMINATE(ctx, val)             smf_set_terminate(ctx, val)

/* Run one iteration of the state machine; returns non-zero on termination */
#define SM_RUN(ctx)                        smf_run_state(ctx)

/* ── State introspection ────────────────────────────────────────────────── */

/* Get the current leaf (active) state */
#define SM_CURRENT_STATE(ctx)      smf_get_current_leaf_state(ctx)

/* Get the state that is currently executing (entry/run/exit) */
#define SM_EXECUTING_STATE(ctx)    smf_get_current_executing_state(ctx)

/* ── Run-action return values ───────────────────────────────────────────── */

#define SM_EVENT_HANDLED      SMF_EVENT_HANDLED
#define SM_EVENT_PROPAGATE    SMF_EVENT_PROPAGATE

/* ── Error codes ────────────────────────────────────────────────────────── */

#define SM_ERR_NULL_TRANSITION       SMF_ERR_NULL_TRANSITION
#define SM_ERR_TRANSITION_IN_EXIT    SMF_ERR_TRANSITION_IN_EXIT

#endif /* SMF_H */