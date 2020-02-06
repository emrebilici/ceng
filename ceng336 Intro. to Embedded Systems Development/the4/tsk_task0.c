#include "common.h"

/**********************************************************************
 * ----------------------- GLOBAL VARIABLES ---------------------------
 **********************************************************************/


/**********************************************************************
 * ----------------------- LOCAL FUNCTIONS ----------------------------
 **********************************************************************/

char announcement[30] = "$R:";
char deneme[5] = "emre";
char signal[3];
unsigned int mov_counter = 0;
/**********************************************************************
 * ------------------------------ TASK0 -------------------------------
 * 
 * Important announcement every 5secs :)
 * 
 **********************************************************************/
TASK(TASK0) 
{
    
    PIE1bits.RCIE = 1;
    while(1){
        WaitEvent(ACTIVE_EVENT);
        ClearEvent(ACTIVE_EVENT);
        SetRelAlarm(ALARM_TSK0, 100, 70);
        while(1) {
            WaitEvent(MOVEMENT_EVENT);
            ClearEvent(MOVEMENT_EVENT);
            dir = findMov();
            
            if(dir == 1){
                if(turn_count%turn90Count == 0){
                    signal = "$R:";
                transmitBuffer_push(signal,3);
                if(turn_count == 0){
                    SetEvent(TASK0_ID, RECEIVE_EVENT);
                    WaitEvent(RESPONSE_EVENT);
                    ClearEvent(RESPONSE_EVENT);
                    turnDegree = encoder_Turn;
                }
                
                turn_count++;
                
                
                }
                else if(turn_count%turn90Count != 0){
                    signal = "$R:";
                    transmitBuffer_push(signal,3);
                    turn_count++;
                    if(turn_count%turn90Count == 0)move
                }
                
                
            }
            
            
            if(mov_counter == 0){
                signal = "$S:";
                transmitBuffer_push(signal,3);
                mov_counter++;
                SetEvent(TASK0_ID, RECEIVE_EVENT);
                
            }
            else if(mov_counter != 0){
                
            }
            transmitBuffer_push(announcement,29);
        }
    }
    
	TerminateTask();
}


unsgined findMov(){
    
}

/* End of File : tsk_task0.c */