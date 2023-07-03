/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Pressure_Detection.c
 *  Brief:  Main Algorithm File
 *  Description:  Logic C File Implementation Of Pressure Detection System
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Pressure_Detection.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void Main_Algorithm(void)
* Description     : Main Algorithm For The Project
* Parameters (in) : None
* Parameters (out): None
* Return value:   : void
********************************************************************/
int Pressure=0;
void Main_Algorithm(void)
{
     while (True)
     {
          Pressure=getPressureVal();
          if(Pressure>=20)Set_Alarm_actuator(0);
          else Set_Alarm_actuator(1);
     }
}
