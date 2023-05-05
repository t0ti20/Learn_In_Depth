/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author:  Khaled El-Sayed (@t0ti20)
 *  Created:  05.02.2023
 *  File:  Linker_Script.ld
 *  Module:  Global
 *  Description:  Linker Script For ARM Cortex-M3
******************************************************************/
ENTRY(_RESET_)				/*Define Entre Point For ELF File*/
/******************************************************************/
/******************************************************************/
MEMORY						/*Define All Memories*/
{
	ROM (rwx) : ORIGIN = 0X08000000, LENGTH = 128k
	RAM (rx)  : ORIGIN = 0X20000000, LENGTH = 20k
}
/******************************************************************/
/******************************************************************/
SECTIONS
{
	.text : 				/*Code Section*/
	{
		_START_VECTORS_ = . ;
		*(.vectors*)
		_END_VECTORS_ = . ;
		_START_TEXT_ = . ;
		*(.text*)
		. = ALIGN(4) ;
		_END_TEXT_ = . ;
		_START_LMA_DATA_ = . ;
	}> ROM
	.data :					/*Global-Const Initialized*/
	{
		_START_VMA_DATA_ = . ;
		*(.data)
		*(.rodara)
		. = ALIGN(4) ;
		_END_VMA_DATA_ = . ;
		_END_LMA_DATA_ = ( ( _END_VMA_DATA_ - _START_VMA_DATA_ ) + _START_LMA_DATA_ ) ;
	}> RAM AT> ROM
	.bss :					/*Global-Const Uninitialized*/
	{
		_START_BSS_ = . ;
		*(.bss)
		. = ALIGN(4) ;
		_END_BSS_ = . ;
	}> RAM
}
/******************************************************************/
/******************************************************************/