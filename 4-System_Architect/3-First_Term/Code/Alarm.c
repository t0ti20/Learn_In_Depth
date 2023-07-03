/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Alarm.c
 *  Brief:  Alarm Driver File
 *  Description:  C File Implementation Of Alarm Driver
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Alarm.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void Start_Alarm(void)
* Description     : Busy Wait Function To Turn Alarm
* Parameters (in) : None
* Parameters (out): None
* Return value:   : void
********************************************************************/
void Start_Alarm(void)
{
     while(1)
     {
          Set_Alarm_actuator(1);
          Delay(100000);
          Set_Alarm_actuator(0);
          Delay(100000);
     }
}