#ifndef FSM_H
#define FSM_H

// My Includes
#include "fsm_states.h"
#include "fsm_events.h"

// Includes
    // None for the moment.
// Defines
    // None for the moment.

// Structure of state and event with event handler
typedef struct
{
    eSystemState        state;
    eSystemEvent        event;
    pf_eventHandler     event_handler;
} s_FSM;

#endif // FSM_H