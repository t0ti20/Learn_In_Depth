/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  System Design Design
 *  Description:  Collision Detector System
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include"Application.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void Application(void)
* Description     : Main Application Logic Function
********************************************************************/
void Application(void)
{
	printf("-Main Application \n");
	Ultra_Sonic_Get_Distance(&Distance);
	if(Distance>=Cut_Off)Speed=30;
	else Speed=0;
	DC_Motor_Set_Speed(Speed);
	for(int i=0;i<(1<<7);i++);
}
