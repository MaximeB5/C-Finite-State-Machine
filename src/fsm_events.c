// My Includes
#include "../inc/fsm_events.h"
    
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines
#define LINE_SIZE 3
#define NB_OF_VAL 1

eSystemEvent read_event(void)
{
    printf("Enter the number of the event :\n\t0 -> Card_Insert_Event\n\t1 -> Pin_Enter_Event\n\t2 -> Option_Selection_Event\n\t3 -> Amount_Enter_Event\n\t4 -> Amount_Dispatch_Event\n\tother -> STOP\n");

    char line[LINE_SIZE];

    if( fgets(line, LINE_SIZE, stdin) == NULL )
    {
        printf("\t\t--- ERROR EOF STDIN (1) in read_event ---");
        return last_Event;
    }

    char format[LINE_SIZE];
    sprintf(format, "%%d");

    int user_input;
    if( sscanf(line, format, &user_input) != NB_OF_VAL)
    {
        printf("\t\t--- ERROR Invalid User Input in read_event ---");
        return last_Event;
    }

    // If the input line is too long
    if( (strlen(line) == LINE_SIZE - 1) && (line[LINE_SIZE-2] != '\n') )
    {
        char c;
        do { c =getchar(); } while(c != '\n');
    }

    if( feof(stdin) )
    {
        printf("\t\t--- ERROR EOF STDIN (2) in read_event ---");
        return last_Event;
    }

    switch (user_input)
    {
    case 0:
        return Card_Insert_Event;
        break;
    
    case 1:
        return Pin_Enter_Event;
        break;
    
    case 2:
        return Option_Selection_Event;
        break;
    case 3:
        return Amount_Enter_Event;
        break;

    case 4:
        return Amount_Dispatch_Event;
        break;
    
    default:
        return last_Event;
        break;
    }
}