/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  RCC_Program.c
 *  Module:  MCAL/RCC
 *  Description:  Reset And Clock Control Module For STM32F103 Program File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./RCC_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void MCAL_RCC_Enable_Clock();
* Description     : Enable Clock To Phereferal 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Module Name
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void MCAL_RCC_Enable_Clock(RCC_Modules_t Module)
{
     switch (Module)
     {
          case RCC_GPIOA:RCC_APB2ENR.Bits.IOPAEN=Enable;break;
          case RCC_AFIO:RCC_APB2ENR.Bits.AFIOEN=Enable;break;
          default:break;
     }
}
/********************************************************************
 *  END OF FILE:  RCC_Program.c
********************************************************************/