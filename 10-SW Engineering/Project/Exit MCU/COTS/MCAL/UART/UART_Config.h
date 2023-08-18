/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  USART_Config.h
 *  Module:  MCAL/USART
 *  Description:  Universal Synchronous Asynchronous Receive Transmit Driver Configuration File
*******************************************************************/
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/*****************************************
--Application PreProcessor Configuration--
*****************************************/
#define		End_String		'\r'
/* S_9600 -  */
#define		Baud_Rate		     S_9600
/* Normal_Speed - Double_Speed */
#define		Speed			Double_Speed
/* Even - Odd - Disabled */
#define		Parity_Mode		Disabled
/* _8_Bits */
#define		Character_Size		_8_Bits
/* Two_StopBits - One_StopBit */
#define		Stop_Bits		     One_StopBit
/* Tx_Rising - Tx_Falling */
#define		Clock_Polarity		Tx_Falling
#endif
/********************************************************************
 *  END OF FILE:  USART_Config.h
********************************************************************/
