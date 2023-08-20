/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author:  Khaled El-Sayed (@t0ti20)
 *  Created:  05.02.2023
 *  File:  Startup.c
 *  Module:  Global
 *  Description:  Startup in C File For ARM Cortex-M3
******************************************************************/
#include "../Macros.h"
#include "../Standard_Types.h"
#define _STACK_SIZE_			(0x3E8)
#define BSS_Initial_Value		(0xFF)
/******************************************************************/
/******************************************************************/
extern u32 _START_LMA_DATA_;
extern u32 _START_VMA_DATA_;
extern u32 _END_VMA_DATA_;
extern u32 _START_BSS_;
extern u32 _END_BSS_;
/******************************************************************/
/******************************************************************/
extern void Intery_Function();
void _RESET_(void);
void NMI_Handler(void)__attribute__((weak,alias("_RESET_")));
void Hard_Fault_Handler(void)__attribute__((weak,alias("_RESET_")));
void Memory_Manage_Handler(void)__attribute__((weak,alias("_RESET_")));
void Bus_Fault_Handler(void)__attribute__((weak,alias("_RESET_")));
void Usage_Fault_Handler(void)__attribute__((weak,alias("_RESET_")));
void SVC_Handler(void)__attribute__((weak,alias("_RESET_")));
void DebugMon_Handler(void)__attribute__((weak,alias("_RESET_")));
void PendSV_Handler(void)__attribute__((weak,alias("_RESET_")));
void SysTick_Handler(void)__attribute__((weak,alias("_RESET_")));
void WWDG_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void PVD_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void TAMPER_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void RTC_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void FLASH_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void RCC_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
void EXTI0_IRQHandler(void)__attribute__((weak,alias("_RESET_")));
/******************************************************************/
/******************************************************************/
u32 _VECTORS_[50] __attribute__((section(".vectors")))=
{
	(u32)(((u32)(&_END_BSS_))+_STACK_SIZE_),
	(u32)&_RESET_,
	(u32)&NMI_Handler,
	(u32)&Hard_Fault_Handler,
	(u32)&Memory_Manage_Handler,
	(u32)&Bus_Fault_Handler,
	(u32)&Usage_Fault_Handler,
	(u32)NULL,(u32)NULL,(u32)NULL,(u32)NULL,
	(u32)&SVC_Handler,
	(u32)&DebugMon_Handler,
	(u32)NULL,
	(u32)&PendSV_Handler,
	(u32)&SysTick_Handler,
	(u32)&WWDG_IRQHandler,
	(u32)&PVD_IRQHandler,
	(u32)&TAMPER_IRQHandler,
	(u32)&RTC_IRQHandler,
	(u32)&FLASH_IRQHandler,
	(u32)&RCC_IRQHandler,
	(u32)&EXTI0_IRQHandler,
};
/******************************************************************/
/******************************************************************/
void _RESET_(void)
{
	u32 SECTION_SIZE;
	u8 *SOURCE_POINTER,*DISTINATION_POINTER;
	/*-----------------------------------------*/
	/*   Copy Data Section From Flash To Ram   */
	/*-----------------------------------------*/
	SECTION_SIZE=(u8*)&_END_VMA_DATA_-(u8*)&_START_VMA_DATA_;
	SOURCE_POINTER=((u8*)(&_START_LMA_DATA_));
	DISTINATION_POINTER=((u8*)(&_START_VMA_DATA_));
	while(SECTION_SIZE--)*((u8 *)DISTINATION_POINTER++)=*((u8 *)SOURCE_POINTER++);
	/*-----------------------------------------*/
	/*      Initialize BSS Section In RAM      */
	/*-----------------------------------------*/
	SECTION_SIZE=(u8*)&_END_BSS_-(u8*)&_START_BSS_;
	DISTINATION_POINTER=((u8*)(&_START_BSS_));
	while(SECTION_SIZE--)*((u8 *)DISTINATION_POINTER++)=(u8)(BSS_Initial_Value);
	/*-----------------------------------------*/
	/*      	Jump To Main Program	       */
	/*-----------------------------------------*/
	while(1)Intery_Function();
}
/******************************************************************/
/******************************************************************/
