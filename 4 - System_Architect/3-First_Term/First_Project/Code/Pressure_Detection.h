/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Pressure_Detection.h
 *  Module:  Learn In Depth Project
 *  Description:  Pressure Detection Project To Detect Hi Pressure
*******************************************************************/
#ifndef _PRESSURE_DETECTION_
#define _PRESSURE_DETECTION_
/*---------- Include Files -------------*/
#include "./Pressure_Sensor.h"
#include "./Alarm.h"
/*----------    Define     -------------*/
#define Theshold    (int)(20)
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum Logic{False,True}Logic;
/*----------- Functins To Use ---------*/
void Main_Algorithm(void);
/********************************************************************
 *  END OF FILE:  Pressure_Detection.h
********************************************************************/
#endif