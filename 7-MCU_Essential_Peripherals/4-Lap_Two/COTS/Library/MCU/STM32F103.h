/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  STM32F103.h
 *  Module:  Library/MCU
 *  Description:  Headder File For MCU "STM32F103x6"
*******************************************************************/
#ifndef _STM32F103_H_
#define _STM32F103_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
/*****************************************
------    Memory Base Addresses    -------
*****************************************/
#define ROM_BASE                        (0x08000000UL)
#define RAM_BASE                        (0x20000000UL)
#define System_BASE                     (0x1FFFF000UL)
#define Pheriphals_BASE                 (0x40000000UL)
#define Internal_Pheriphals_BASE        (0xE0000000UL)
/*****************************************
------   Pheriphal Base Addresses  -------
*****************************************/
/*--------------------------------------*/
/* 0x40000000 >>>>>>>>>>>>>> 0x4000FFFF */
/*--------------- APB1 -----------------*/
#define TIM2_Offset                     (0x0UL)
/*--------------------------------------*/
/* 0x40010000 >>>>>>>>>>>>>> 0x40017FFF */
/*--------------- APB2 -----------------*/
#define AFIO_Offset                     (0x10000UL)
#define EXTI_Offset                     (0x10400UL)
#define GBIOA_Offset                    (0x10800UL)
#define GBIOB_Offset                    (0x10C00UL)
#define GBIOC_Offset                    (0x11000UL)
#define GBIOD_Offset                    (0x11400UL)
#define GBIOE_Offset                    (0x11800UL)
/*--------------------------------------*/
/* 0x40018000 >>>>>>>>>>>>>> 0xA0000FFF */
/*---------------- AHB -----------------*/
#define RCC_Offset                      (0x21000UL)
/****************************************
 *          Generic Macros              *
*****************************************/
/*------------- BitField -------------*/
typedef struct Bits_t
{
     volatile u32 Bit_0:ONE;volatile u32 Bit_1:ONE;volatile u32 Bit_2:ONE;
     volatile u32 Bit_3:ONE;volatile u32 Bit_4:ONE;volatile u32 Bit_5:ONE;
     volatile u32 Bit_6:ONE;volatile u32 Bit_7:ONE;volatile u32 Bit_8:ONE;
     volatile u32 Bit_9:ONE;volatile u32 Bit_10:ONE;volatile u32 Bit_11:ONE;
     volatile u32 Bit_12:ONE;volatile u32 Bit_13:ONE;volatile u32 Bit_14:ONE;
     volatile u32 Bit_15:ONE;volatile u32 Bit_16:ONE;volatile u32 Bit_17:ONE;
     volatile u32 Bit_18:ONE;volatile u32 Bit_19:ONE;volatile u32 Bit_20:ONE;
     volatile u32 Bit_21:ONE;volatile u32 Bit_22:ONE;volatile u32 Bit_23:ONE;
     volatile u32 Bit_24:ONE;volatile u32 Bit_25:ONE;volatile u32 Bit_26:ONE;
     volatile u32 Bit_27:ONE;volatile u32 Bit_28:ONE;volatile u32 Bit_29:ONE;
     volatile u32 Bit_30:ONE;volatile u32 Bit_31:ONE;
}Bits_t;
typedef union Register_t
{
     volatile u32 Register;
     Bits_t Bits;
}Register_t;
/****************************************
 *        Pheripheral Registers         *
*****************************************/
/*---------------- EXTI ----------------*/
typedef struct EXTI_t
{
     Register_t IMR;                  /*0x00*/
     Register_t EMR;                  /*0x04*/
     Register_t RTSR;                 /*0x08*/
     Register_t FTSR;                 /*0x0C*/
     Register_t SWIER;                /*0x10*/
     Register_t PR;                   /*0x14*/    
}EXTI_t;
/*---------------- GPIO ----------------*/
typedef struct GPIOX_t
{
     Register_t CRL;                  /*0x00*/
     Register_t CRH;                  /*0x04*/
     Register_t IDR;                  /*0x08*/
     Register_t ODR;                  /*0x0C*/
     Register_t BSRR;                 /*0x10*/
     Register_t BRR;                  /*0x14*/  
     Register_t LCKR;                 /*0x18*/
}GPIOX_t;
/*---------------- AFIO ----------------*/
typedef struct AFIO_t
{
     Register_t EVCR;                 /*0x00*/
     Register_t MAPR;                 /*0x04*/
     Register_t EXTICR1;              /*0x08*/
     Register_t EXTICR2;              /*0x0C*/ 
     Register_t EXTICR3;              /*0x10*/
     Register_t EXTICR4;              /*0x14*/
     Register_t Reserved;             /*0x18*/
     Register_t AFIO_MAPR2;           /*0x1C*/
}AFIO_t;
/*---------------- RCC ----------------*/
typedef struct RCC_t
{
     Register_t CR;                   /*0x00*/
     Register_t CFGR;                 /*0x04*/
     Register_t CIR;                  /*0x08*/
     Register_t APB2RSTR;             /*0x0C*/
     Register_t APB1RSTR;             /*0x10*/
     Register_t AHBENR;               /*0x14*/
     Register_t APB2ENR;              /*0x18*/
     Register_t APB1ENR;              /*0x1C*/
     Register_t BDCR;                 /*0x20*/
     Register_t CSR;                  /*0x24*/
     Register_t AHBSTR;               /*0x28*/
     Register_t CFGR2;                /*0x2C*/
}RCC_t;
/****************************************
 *         Pheripheral Instants         *
*****************************************/
#define RCC                             (*((RCC_t *)(Pheriphals_BASE + RCC_Offset)))
#define AFIO                            (*((AFIO_t *)(Pheriphals_BASE + AFIO_Offset)))
#define EXTI                            (*((EXTI_t *)(Pheriphals_BASE + EXTI_Offset)))
#define GPIOA                           (((GPIOX_t *)(Pheriphals_BASE + GBIOA_Offset)))
#define GPIOB                           (((GPIOX_t *)(Pheriphals_BASE + GBIOB_Offset)))
#define GPIOC                           (((GPIOX_t *)(Pheriphals_BASE + GBIOC_Offset)))
#define GPIOD                           (((GPIOX_t *)(Pheriphals_BASE + GBIOD_Offset)))
#define GPIOE                           (((GPIOX_t *)(Pheriphals_BASE + GBIOE_Offset)))
/****************************************
 *         Clock Enable Macros          *
*****************************************/
#define RCC_Pheripheral_Enable(Pheripheral,Module)        Set_Bit(RCC.Pheripheral.Register,Module)
#define RCC_Pheripheral_Disable(Pheripheral,Module)       Clear_Bit(RCC.Pheripheral.Register,Module)
/*------------- RCC_AHBENR -------------*/
#define DMA1EN                          (0)       /*DMA1 clock enable*/
#define DMA2EN                          (1)       /*DMA2 clock enable*/
#define SRAMEN                          (2)       /*SRAM interface clock enable*/
#define FLITFEN                         (4)       /*FLITF clock enable*/
/*------------- RCC_APB2ENR ------------*/
#define AFIOEN                          (0)       /*Alternate function IO clock enable*/
#define IOPAEN                          (2)       /*IO port A clock enable*/
#define IOPBEN                          (3)       /*IO port B clock enable*/
#define IOPCEN                          (4)       /*IO port C clock enable*/
#define IOPDEN                          (5)       /*IO port D clock enable*/
#define IOPEEN                          (6)       /*IO port E clock enable*/
/********************************************************************
 *  END OF FILE: STM32F103.h
********************************************************************/
#endif
