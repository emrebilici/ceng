#ifndef _COMMON_H
#define COMMON_H

#include "device.h"

/***********************************************************************
 * ------------------------ Timer settings -----------------------------
 **********************************************************************/
#define _10MHZ	63320
#define _16MHZ	61768
#define _20MHZ	60768
#define _32MHZ	57768
#define _40MHZ 	55768

/***********************************************************************
 * ----------------------------- Events --------------------------------
 **********************************************************************/
#define ALARM_EVENT       0x80
#define LCD_EVENT         0x01
#define MOVEMENT_EVENT         0x02
#define ACTIVE_EVENT         0x04
#define RECEIVE_EVENT         0x08
/***********************************************************************
 * ----------------------------- Task ID -------------------------------
 **********************************************************************/
/* Info about the tasks:
 * TASK0: USART
 * TASK1: USART
 */
#define TASK0_ID             1
#define TASK1_ID             2
#define LCD_ID              3

/* Priorities of the tasks */
#define TASK0_PRIO           8
#define TASK1_PRIO           8
#define LCD_PRIO            8

#define ALARM_TSK0           0
#define ALARM_TSK1           1
#define LCD_ALARM_ID         2       /* Alarm ID (index) in tascdesc.c */


/**********************************************************************
 * ----------------------- GLOBAL DEFINITIONS -------------------------
 **********************************************************************/

/* System States */
#define _WAITING	0		// waiting state
#define _OPERATING      3

#define SIZE_TM_BUF 100
#define SIZE_RC_BUF 100


/**********************************************************************
 * ----------------------- FUNCTION PROTOTYPES ------------------------
 **********************************************************************/
 /* transmits data using serial communication */
void transmitData();
/* Invoked when receive interrupt occurs; meaning that data is received */
void dataReceived();

void transmitBuffer_push(char *str,unsigned char size);

unsigned char receiveBuffer_pop(char *str);
extern char deneme[5];
#endif

/* End of File : common.h */
