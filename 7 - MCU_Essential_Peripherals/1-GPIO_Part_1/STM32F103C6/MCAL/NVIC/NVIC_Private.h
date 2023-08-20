/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  NVIC_Private.h
 *  Module:  MCAL/NVIC
 *  Description:  Nested Victor Interrupt Controller 
                  Module For STM32F103 Private File
*******************************************************************/
#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_
/********************************************************************/
/*---------- Base Addresses -------------*/
#define EXTI_BASE             (0x40010400)
/*---------- Offset Address -------------*/
#define EXTI_IMR_Offset       (0x00)
#define EXTI_RTSR_Offset      (0x08)
#define EXTI_FTSR_Offset      (0x0C)
#define EXTI_SWIER_Offset     (0x10)
#define EXTI_PR_Offset        (0x14)
/*****************************************
------------   Registers    -------------
*****************************************/
#define EXTI_IMR    (*((volatile Regester_t *)(EXTI_BASE+EXTI_IMR_Offset)))
#define EXTI_RTSR   (*((volatile Regester_t *)(EXTI_BASE+EXTI_RTSR_Offset)))
#define EXTI_FTSR   (*((volatile Regester_t *)(EXTI_BASE+EXTI_FTSR_Offset)))
#define EXTI_SWIER  (*((volatile Regester_t *)(EXTI_BASE+EXTI_SWIER_Offset)))
#define EXTI_PR     (*((volatile Regester_t *)(EXTI_BASE+EXTI_PR_Offset)))
/*****************************************
---------------   Bits    ---------------
*****************************************/
/*-----------   EXTI_IMR    ------------*/
#define MR0                    Bit_0
#define MR1                    Bit_1
#define MR2                    Bit_2
/*-----------   EXTI_RTSR    -----------*/
#define TR0                    Bit_0
#define TR1                    Bit_1
#define TR2                    Bit_2
/*------------   EXTI_PR    ------------*/
#define PR0                    Bit_0
#define PR1                    Bit_1
#define PR2                    Bit_2
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum EXIT_Lines_t
{
     Line_0,Line_1,Line_2
}EXIT_Lines_t;

/*----------- Functins To Use ---------*/

/********************************************************************
 *  END OF FILE:  NVIC_Private.h
********************************************************************/
#endif