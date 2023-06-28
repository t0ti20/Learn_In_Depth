/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  System Design Design
 *  Description:  Collision Detector System
*******************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/*---------- Include Files -------------*/
#include"Ultra_Sonic.h"
#include"DC_Motor.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Cut_Off 30
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
static int Speed=0,Distance=0;
/*----------- Functions To Use ---------*/
void Application(void);
/********************************************************************
 *  END OF FILE: Application.h
********************************************************************/
#endif

