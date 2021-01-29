#ifndef FSM_EVENTS_H
#define FSM_EVENTS_H

// My Includes
    // None for the moment.
    
// Includes
    // None for the moment.

// Defines
#define LINE_SIZE 3
#define NB_OF_VAL 1

typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event,
    last_Event
} eSystemEvent;

eSystemEvent read_event(void);

#endif // FSM_EVENTS_H