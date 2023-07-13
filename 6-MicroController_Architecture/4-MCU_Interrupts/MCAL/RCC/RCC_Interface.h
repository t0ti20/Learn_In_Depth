/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  RCC_Interface.h
 *  Module:  MCAL/RCC
 *  Description:  Reset And Control Module For STM32F103 Interface File
*******************************************************************/
#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
/********************************************************************/
/*---------- Include Files -------------*/
#include "./RCC_Private.h"
#include "./RCC_Config.h"
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/

/*----------- Functins To Use ---------*/
extern void MCAL_RCC_Enable_Clock(RCC_Modules_t Module);
/********************************************************************
 *  END OF FILE:  RCC_Interface.h
********************************************************************/
#endif