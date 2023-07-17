/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  NVIC_Interface.h
 *  Module:  MCAL/NVIC
 *  Description:  Nested Victor Interrupt Controller 
                  Module For STM32F103 Interface File
*******************************************************************/
#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_
/********************************************************************/
/*---------- Include Files -------------*/
#include "./NVIC_Private.h"
#include "./NVIC_Config.h"
#include "../RCC/RCC_Interface.h"
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/

/*----------- Functins To Use ---------*/
extern void MCAL_EXTI_Configure_Line(EXIT_Lines_t Line_Number);
extern void MCAL_EXTI_0_ISR_Function(void (*ISR_Function)(void));
/********************************************************************
 *  END OF FILE:  NVIC_Interface.h
********************************************************************/
#endif