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
     u8 Data=0xf0;
     Application_VidSystem_Initialization();
     while (1)
     {
          for(u8 Count=0;Count<255;Count++)
          {
               Data=Count;
               SPI_VidSend_Receive(&Data);
               UART_VidSend_Receive(Send,&Data);
          }
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
     GPIO_VidSet_Whole_Port_Direction(Port_A,OUTPUT);
     UART_VidInitialization(Transmit_Recive,Rx_Disable,Tx_Disable);
     SPI_VidInitialization(SPI_Slave,SPI_Interrupt_Disable);
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
