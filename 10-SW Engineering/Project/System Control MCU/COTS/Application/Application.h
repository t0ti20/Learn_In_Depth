/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.h
 *  Module:  ./Application
 *  Description:  Application Headder File
*******************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "SPI_Interface.h"
/*****************************************
--------    Type  Definitions    ---------
*****************************************/
/*----------- Pins Numbers -------------*/
/*****************************************
---------    Configure Macros    ---------
*****************************************/
/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
* Syntax          : GPIO_VidInternal_Pin_Bull_Up(u8 Copy_u8Port, u8 Copy_u8Pin)
* Description     : Set the internal pull-up for a specific GPIO pin.
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Copy_u8Port (Port identifier), Copy_u8Pin (Pin number)
* Parameters (out): None
* Return value    : Void
********************************************************************/
void Application_VidSystem_Initialization(void);
/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
