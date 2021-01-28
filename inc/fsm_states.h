#ifndef FSM_STATES_H
#define FSM_STATES_H

// My Includes
    // None for the moment.

// Includes
#include <stdio.h>

// Defines
    // None for the moment.

typedef enum
{
    Idle_State,
    Card_Inserted_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
    last_State
} eSystemState;


// Typedef of function pointer
typedef eSystemState (*pf_eventHandler)(void);


// Function call to dispatch the amount and return the ideal state
eSystemState amount_dispatch_handler(void)  {   printf("Event called is '%s'\n\n", __FUNCTION__);   return Idle_State;              }

// Function call to processing track data and return card inserted state
eSystemState insert_card_handler(void)      {   printf("Event called is '%s'\n\n", __FUNCTION__);   return Card_Inserted_State;     }

// Function call to enter the pin and return pin entered state
eSystemState enter_pin_handler(void)        {   printf("Event called is '%s'\n\n", __FUNCTION__);   return Pin_Eentered_State;      }

// Function call to option select and return the option selected state
eSystemState option_selection_handler(void) {   printf("Event called is '%s'\n\n", __FUNCTION__);   return Option_Selected_State;   }

// Function call to Enter amount and return amount entered state
eSystemState enter_amount_handler(void)     {   printf("Event called is '%s'\n\n", __FUNCTION__);   return Amount_Entered_State;    }

#endif // FSM_STATES_H