// My Includes
#include "../inc/fsm.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
	// None for the moment.

int main()
{
	printf("Hello from C-Finite State Machine.\n");
	printf("This FSM follows a sequence of 5 states, from 0 to 4.\n\n");

	// Initialize array of structure with states and event with proper handler
	s_FSM fsm [] =
	{
		{Idle_State,			Card_Insert_Event,		insert_card_handler},
		{Card_Inserted_State,	Pin_Enter_Event,		enter_pin_handler},
		{Pin_Eentered_State,	Option_Selection_Event,	option_selection_handler},
		{Option_Selected_State,	Amount_Enter_Event,		enter_amount_handler},
		{Amount_Entered_State,	Amount_Dispatch_Event,	amount_dispatch_handler}
	};

	eSystemState next_state = Idle_State;

	while(1)
	{
		// Get event
		eSystemEvent eNewEvent = read_event();
		printf("State is %d\n", eNewEvent);

        if(		(next_state < last_State)
			&&	(eNewEvent < last_Event)
			&&	(fsm[next_state].event == eNewEvent)
			&&	(fsm[next_state].event_handler != NULL)
		)
		{
            // Function call as per the state and event and return the next state of the finite state machine
            next_state = (*fsm[next_state].event_handler)();
		}
        else
		{
			printf("--- invalid input ---\n\n");
		}
	}

	return(0);
}
