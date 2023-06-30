/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  DC_Motor.c
 *  Module:  System Design Design
 *  Description:  DC_Motor Driver
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include"Ultra_Sonic.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void DC_Motor_Set_Speed(INT Speed)
* Description     : Set Speed Of The Motor
********************************************************************/
int Random(int min, int max)
{
   return min + rand() % (max - min);
}
void Ultra_Sonic_Get_Distance(int *Distance)
{
	*Distance=Random(0, 100);
	printf("-Distance Is Set To : %d\n",*Distance);
}

