/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.c
 *  Module:  ./Application
 *  Description:  Entrance Gate Control Unit ECU Main Application
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Application.h"
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{
     Application_VidSystem_Initialization();
     //HAL_Buzzer_Start();
     while (1)
     {
          HAL_LED_ID_State(1);
          delay_ms(1000);
          HAL_LED_ID_State(0);
          delay_ms(1000);
          // OCR0=125;
          // OCR0=250;
          // delay_ms(3000);
     }
}
/********************************************************************
* Syntax          : void Application_VidSystem_Initialization(void)
* Description     : Initialize the entire system for application execution.
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : None
* Parameters (out): None
* Return value    : Void
********************************************************************/
void Application_VidSystem_Initialization(void)
{
     HAL_LED_Initialization();
     //HAL_Buzzer_Initialization();
     //Timer_0_VidInitialization(Fast_PWM,255,Disable_CM,Disable_OF,Timer_Pre_Scalar_64);
     // UART_VidInitialization(Transmit_Recive,Rx_Enable,Tx_Disable);
     // UART_VidReceive_Function(Application_VidUART_Receiving_ISR);
     //SPI_VidInitialization(SPI_Master,SPI_Interrupt_Disable);
}
/********************************************************************
* Syntax          : void Application_VidUART_Receiving_ISR(void)
* Description     : Interrupt service routine for UART reception.
                    Upon receiving data via UART, it immediately sends the received data back via UART.
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : None
* Parameters (out): None
* Return value    : Void
********************************************************************/
void Application_VidUART_Receiving_ISR(u8 *Received_Data)
{
     UART_VidSend_Receive(Send,Received_Data);
     SPI_VidSend_Receive(Received_Data);
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
