/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Pressure_Sensor.c
 *  Brief:  Pressure Sensor Driver
 *  Description:  Logic C File Implementation Driver For Pressure Sensor
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Pressure_Sensor.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : float Get_Pressure(void)
* Description     : Call The Sensor For The Pressure
* Parameters (in) : None
* Parameters (out): Pressure
* Return value:   : int
********************************************************************/
int Get_Pressure(void)
{
     return ((int)getPressureVal());
}
