/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  EXTI_Interface.h
 *  Module:  MCAL/EXTI
 *  Description:  External Interrupt Device Driver Interface File
*******************************************************************/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "GPIO_Interface.h"
typedef struct NVIC_Config_t
{
     NVIC_Interrupt_Numbers_t Interrupt_Number;
     logic_t State;
}NVIC_Config_t;
/*****************************************
--------    Type  Definitions    ---------
*****************************************/
typedef enum EXTI_Sense_t
{
     Faling_Edge         =1,
     Rising_Edge         =2,
     Faling_Rising       =3
}EXTI_Sense_t;
/*----------- EXTI Config -------------*/
typedef struct __attribute__((packed)) EXTI_Config_t
{
     GPIO_Port_t Port;
     GPIO_Pin_Number_t Pin;
     EXTI_Sense_t Sensing_Edge;
     logic_t Interrupt;
     logic_t Event;
     void(*volatile Ptr_Function)(void);
}EXTI_Config_t;
/*****************************************
---------    Configure Macros    ---------
*****************************************/
#define EXTI_Pins_Victor_Map            {EXTI0_IRQ,EXTI1_IRQ,EXTI2_IRQ,EXTI3_IRQ,EXTI4_IRQ,EXTI5_IRQ,EXTI6_IRQ,EXTI7_IRQ,EXTI8_IRQ,\
                                        EXTI9_IRQ,EXTI10_IRQ,EXTI11_IRQ,EXTI12_IRQ,EXTI13_IRQ,EXTI14_IRQ,EXTI15_IRQ}
/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
* Syntax          : MCAL_GPIO_Lock_Pin(GPIOX_t *Port,GPIO_Pin_t Pin)
* Description     : Lock State For Specific Pin
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To The Port "GPIOX->X=A,B,C,D,E"),(Copy To Pin Number "Pin_Number_t")
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void EXTI_Initilization(EXTI_Config_t Configure);
/********************************************************************
 *  END OF FILE:  EXTI_Interface.h
********************************************************************/
#endif
