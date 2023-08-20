/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  RCC_Private.h
 *  Module:  MCAL/RCC
 *  Description:  Reset And Clock Control Module For STM32F103 Private File
*******************************************************************/
#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_
/********************************************************************/
/*---------- Base Addresses -------------*/
#define RCC_BASE    (0x40021000)
/*---------- Offset Address -------------*/
#define RCC_APB2ENR_Offset    (0x18)
/*****************************************
---------------   Bits    ---------------
*****************************************/
/*---------   RCC_APB2ENR    -----------*/
#define AFIOEN Bit_0
#define IOPAEN Bit_2
/*****************************************
------------   Registers    -------------
*****************************************/
#define RCC_APB2ENR (*((volatile Regester_t *)(RCC_BASE+RCC_APB2ENR_Offset)))
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum RCC_Modules_t
{
     RCC_GPIOA,RCC_GPIOB,RCC_GPIOC,RCC_AFIO
}RCC_Modules_t;

/*----------- Functins To Use ---------*/

/********************************************************************
 *  END OF FILE:  RCC_Private.h
********************************************************************/
#endif