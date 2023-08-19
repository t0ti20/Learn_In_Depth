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
u8 Flag=False;
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{
     Application_VidSystem_Initialization();
     while(True)
     {
          HAL_Gate_Close();
          LCD_VidClear();
          // LCD_VidSet_Position(1,3);
          // LCD_VidSend_String((u8 const *)"- WELCOME -");
          // LCD_VidSet_Position(2,3);
          // LCD_VidSend_String((u8 const *)"-----------");
          LCD_VidSet_Position(3,0);
          LCD_VidSend_String((u8 const *)"Please Scan ID :");
          while(!Flag);
          if(Flag=='1')
          {
               LCD_VidClear();
               LCD_VidSet_Position(1,2);
               HAL_LED_ID_State(ONE);
               LCD_VidSend_String((u8 const *)"Gate  Opened");
               HAL_Gate_Open();
               while (HAL_Motion_Sensor_Get_State());
               Flag=0;
          }
          else
          {
               LCD_VidClear();
               LCD_VidSet_Position(1,2);
               HAL_LED_ID_State(ZERO);
               LCD_VidSend_String((u8 const *)"Invalid ID !");
               HAL_Buzzer_Start();
               Flag=0;
          }
          // while(!Flag);
          // Flag=False;
          // LCD_VidClear();
          // SPI_VidSend_Receive(&TEMP);
          // HAL_Buzzer_Start();
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
     /* Initialize LCD */
     LCD_VidInitialization();
     /* Initialize LED */
     HAL_LED_Initialization();
     /* Initialize Buzzer */
     HAL_Buzzer_Initialization();
     /* Initialize Gate */
     HAL_Gate_Initialization();
     /* Initialize Motion Sensor */
     HAL_Motion_Sensor_Initialization();
     /* Initialize Communication Module */
     HAL_Communication_Initialization();
     /* Initialize RFID Module */
     UART_VidInitialization(Transmit_Recive,Rx_Enable,Tx_Disable);
     UART_VidReceive_Function(Application_VidUART_Receiving_ISR);
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
     UART_VidSend_String((u8*)"ID Scaned = ");
     UART_VidSend_Receive(Send,Received_Data);
     Flag=HAL_Communication_ID_Check(*Received_Data);
     UART_VidSend_String((u8*)"\r------------------\r");
     //
     UART_VidSend_Receive(Send,&Flag);
     //
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
