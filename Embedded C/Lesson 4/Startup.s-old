/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author:  Khaled El-Sayed (@t0ti20)
 *  Created:  05.02.2023
 *  File:  Startup.s
 *  Module:  Global
 *  Description:  Startup For ARM Cortex-M3
******************************************************************/
/*****************************************************************/
.thumb_func						/*Enable 16 Bit Thumb Instruction*/
.section .vectors				/*Create Vector Table Section*/
.word 0x20001000				/*Initialize Stack Pointer*/
.word _RESET_ 					/*1-Reset Address*/
.word _VECTOR_HANDLER_			/*2-Others Interrupt Address*/
.section .text					/*Create Text Section*/
/*****************************************************************/
.global _RESET_					/*Export Start Section*/
/*****************************************************************/
_RESET_:
	bl Intery_Function 			/*Branch Intery Function*/
	b .							/*Busy Wait*/
/*****************************************************************/
/*****************************************************************/
_VECTOR_HANDLER_:
	bl _RESET_					/*Branch Reset Section*/
/*****************************************************************/
/*****************************************************************/