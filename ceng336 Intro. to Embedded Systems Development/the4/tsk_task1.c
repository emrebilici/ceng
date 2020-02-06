#include "common.h"

/**********************************************************************
 * ----------------------- GLOBAL VARIABLES ---------------------------
 **********************************************************************/

char data[40];
char data2[5];
char data_size;
char encoderN = 0;
/**********************************************************************
 * ----------------------- LOCAL FUNCTIONS ----------------------------
 **********************************************************************/


/**********************************************************************
 * ------------------------------ TASK1 -------------------------------
 *
 * Basic echo function test. Type $hello: in cutecom and receive hello
 *
 **********************************************************************/
TASK(TASK1) 
{
    TRISAbits.TRISA1 = 0;
    LATAbits.LATA1= 0;
    TRISAbits.TRISA2 = 0;
    LATAbits.LATA2= 0;
    
    
    PIE1bits.RCIE = 1;
    
    SetRelAlarm(ALARM_TSK1, 10, 50);
        while(1){
            WaitEvent(ALARM_EVENT);
            ClearEvent(ALARM_EVENT);
            data_size = receiveBuffer_pop(data);
            if(data_size == 0)
                continue;
            else if(data[0] == 'G'){
                SetEvent(TASK0_ID, ACTIVE_EVENT);
                break;
            }
        }
    cancelAlarm(1);
    while(1){
        
        
        WaitEvent(RECEIVE_EVENT);
        ClearEvent(RECEIVE_EVENT);
        SetRelAlarm(ALARM_TSK1, 10, 50);
        while(1){
            WaitEvent(ALARM_EVENT);
            ClearEvent(ALARM_EVENT);
            data_size = receiveBuffer_pop(data);
            if(data_size == 0)
                continue;
            else if(data[0] == 'D'){
                xVal = data[1];
                yVal = data[2];
                zVal = data[3];
                tVal = data[4];
                SetEvent(TASK1_ID, ACTIVE_EVENT);
                break;
            }
            else if(data[0] == 'E'){
                encoderN = data[1];
                if(dir == 3){
                    move1BlockCount = 50 / encoderN;
                }
                else{
                    turn90Count = 90 / encoderN;
                }
                
                SetEvent(TASK1_ID, ACTIVE_EVENT);
               
                break;
            }
            
        }
    }
    
    
    
    while(1){
        WaitEvent(ALARM_EVENT);
        ClearEvent(ALARM_EVENT);
        
        
    }
    
    
    
    
    SetRelAlarm(ALARM_TSK1, 10, 50);
	while(1) {
        WaitEvent(ALARM_EVENT);
        ClearEvent(ALARM_EVENT);
        
        data_size = receiveBuffer_pop(data);
        if(data_size == 0)continue;
        else if(data[0] == 'G'){
        SetEvent(TASK0_ID, ACTIVE_EVENT);   
        }
        else if(data[0] == 'G'){
            
        }
        else if(data[0] == 'G'){
            
        }
        data2[0] = '$';
        data2[1] = 'F';
        data2[2] = ':';


        if(data_size >0 )
        {
            transmitBuffer_push(data2,3);
//            transmitBuffer_push(data,data_size);
        }
        if(data[1] >0){
            LATAbits.LATA1= 1;
        }
        if(data[1] == 9){
            LATAbits.LATA2= 1;
        }
	}
	TerminateTask();
}

/* End of File : tsk_task1.c */