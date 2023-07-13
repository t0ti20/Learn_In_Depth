/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Macros.h
 *  Module:  Library
 *  Description:  Common Macros Needed In Any Project
*******************************************************************/
#ifndef _MACROS_H_
#define _MACROS_H_
/********************************************************************/
/*---------- Include Files -------------*/
#include "./Standard_Types.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Logic -------------*/
#ifndef False
#define False 0
#endif
#ifndef True
#define True 1
#endif
#ifndef Disable
#define Disable 0
#endif
#ifndef Enable
#define Enable 1
#endif
/*------------- Magic_Numbers -------------*/
typedef enum{ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHTH,NINE,TEN}numbers_t;
/*------------- Null -------------*/
#ifndef NULL
#define NULL   	               ((void*) 0 )                  /* NULL Pointer */
#endif
/*------------- Bit Math -------------*/
#define Set_Bit(Reg,Bit_Num)       (Reg|=1<<Bit_Num)			/* Set Bit */
#define Clear_Bit(Reg,Bit_Num)     (Reg&=~(1<<Bit_Num))		/* Clear Bit */
#define Toggle_Bit(Reg,Bit_Num)    (Reg^=(1<<Bit_Num))		     /* Toggle Bit */
#define Get_Bit(Reg,Bit_Num)       ((Reg>>Bit_Num)&1)		     /* Get_Bit */
/*------------- Max-Min -------------*/
#define Max(x,y)                   (x>y)?(x):(y)                 /* Max Of Two Digits */
#define Min(x,y)                   (x>y)?(y):(x)                 /* Min Of Two Digits */
/*------------- BitField -------------*/
typedef struct Bits_t
{
     u32 Bit_0:ONE;u32 Bit_1:ONE;u32 Bit_2:ONE;u32 Bit_3:ONE;u32 Bit_4:ONE;u32 Bit_5:ONE;
     u32 Bit_6:ONE;u32 Bit_7:ONE;u32 Bit_8:ONE;u32 Bit_9:ONE;u32 Bit_10:ONE;u32 Bit_11:ONE;
     u32 Bit_12:ONE;u32 Bit_13:ONE;u32 Bit_14:ONE;u32 Bit_15:ONE;u32 Bit_16:ONE;u32 Bit_17:ONE;
     u32 Bit_18:ONE;u32 Bit_19:ONE;u32 Bit_20:ONE;u32 Bit_21:ONE;u32 Bit_22:ONE;u32 Bit_23:ONE;
     u32 Bit_24:ONE;u32 Bit_25:ONE;u32 Bit_26:ONE;u32 Bit_27:ONE;u32 Bit_28:ONE;u32 Bit_29:ONE;
     u32 Bit_30:ONE;u32 Bit_31:ONE;u32 Bit_32:ONE;
}Bits_t;
typedef union Regester_t
{
     u32 Regester;
     Bits_t Bits;
}Regester_t;
/********************************************************************
 *  END OF FILE: Macros.h
********************************************************************/
#endif
