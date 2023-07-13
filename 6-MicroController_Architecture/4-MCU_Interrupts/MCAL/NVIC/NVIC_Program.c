/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  NVIC_Program.c
 *  Module:  MCAL/NVIC
 *  Description:  Nested Victor Interrupt Controller 
                  Module For STM32F103 Program File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./NVIC_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void MCAL_NVIC_Enable_Clock();
* Description     : Enable Clock To Phereferal 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Module Name
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void MCAL_EXTI_Configure_Line(EXIT_Lines_t Line_Number)
{
     //enable line number 0-19
     Set_Bit(EXTI_IMR.Regester,Line_Number);
     //configure rising edge if wanted
     Set_Bit(EXTI_RTSR.Regester,Line_Number);
     //configure falling edge if wanted
     Set_Bit(EXTI_FTSR.Regester,Line_Number);
     //software interrupt/event generator from EXTI_SWIER
     //pending interrupt/event to check from EXTI_PR
}

/********************************************************************
* Syntax          : EXTI_0_ISR_Function(void (*ISR_Function)(void))
* Description     : ISR Function API For External Interrupt
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Pointer To ISR Function
* Parameters (out): None
* Return value:   : Void
********************************************************************/
static void (*Pointer_ISR_Function)(void)=NULL;
void MCAL_EXTI_0_ISR_Function(void (*ISR_Function)(void))
{
     if(ISR_Function)
     {
          Pointer_ISR_Function=ISR_Function;
     }
}
void EXTI0_IRQHandler(void)
{
     //jump to isr
     Pointer_ISR_Function();
     //clear flag
     Set_Bit(EXTI_PR.Regester,ZERO);
}
/********************************************************************
 *  END OF FILE:  NVIC_Program.c
********************************************************************/