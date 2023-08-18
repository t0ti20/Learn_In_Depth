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
----------- Global Variables -------------
*****************************************/
GPIO_Pin_Config_t A0=
{
    Pin_0,
    Output_Push_Pull,
    Output_10
};
SPI_Config_t SPI=
{
    NULL,
    SPI_1,
    SPI_Master,
    SPI_Tx_Rx_Two_Line,
    SPI_MSBF,
    SPI_8_Bit,
    SPI_Idle_Low_First_Edge,
    SPI_Prescalar_8,
    SPI_Disable_Interrupt,
    SPI_Software_Disable
};
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{
    u16 Data=0xAA;
    u8 Counter=0;
    Application_VidSystem_Initialization();
    while (TRUE)
    {
        HAL_LCD_Send_Data(HAL_Keypad_Wait_For_Input());
        // for(Counter=0;Counter<255;Counter++)
        // {
        //     Data=Counter;
        //     SPI_Send_Receive_Data(&SPI,&Data);
        //     MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_0);
        //     HAL_LCD_Set_Courser(4,10);
        //     HAL_LCD_Send_Number(Data);
        // }
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
    HAL_Keypad_Initialization();
    HAL_LCD_Initialization();
    RCC_Clock(RCC_SPI1,Enable);
    RCC_Clock(RCC_GPIOA,Enable);
    MCAL_GPIO_Initialize(GPIO_A,A0);
    SPI_Initialization(&SPI);
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
