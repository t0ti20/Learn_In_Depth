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
DataBase_t DataBase[Max_ID]={{'1'},{'2'},{'3'},{'4'}}; 
u8 Garage_Clients=ZERO,DataBase_Index=FOUR,Admin_Passowrd[5]=Admin_Password;
EXTI_Config_t EXTI_Entrance=
{
    ECU_Port,
    Entrance_Pin,
    Rising_Edge,
    ENABLE,
    Disable,
    EXTI_Entrance_ISR
};
SPI_Config_t SPI=
{
    NULL,
    SPI_1,
    SPI_Master,
    SPI_Tx_Rx_Two_Line,
    SPI_MSBF,
    SPI_8_Bit,
    SPI_Idle_Hi_Second_Edge,
    SPI_Prescalar_8,
    SPI_Disable_Interrupt,
    SPI_Software_Disable
};
GPIO_Pin_Config_t A0=
{
    Pin_0,
    Output_Push_Pull,
    Output_10
};
GPIO_Pin_Config_t B15=
{
    Pin_15,
    Input_Floating,
    Input
};
Seven_Segment_t Segment=
{
    Seven_Segment_Port,
    Common_Cathode,
    Seven_Segment_Pins,
    Seven_Segment_Enable
};
/*****************************************
----------- Main Application  ------------
*****************************************/
int main(void)
{   
    Application_VidSystem_Initialization();
    while(TRUE)
    {
        u8 Input_Flag=Keypad_Not_Pressed;
        /*Update Seven Segment*/
        Seven_Segment_Send_One_Digit(&Segment,(THREE-Garage_Clients));
        /* Input From Admin */
        HAL_LCD_Set_Courser(1,0);
        HAL_LCD_Send_String("(Enter Password)");
        Input_Flag=HAL_Keypad_Get_Key();
        if(Input_Flag!=Keypad_Not_Pressed)Admin_Panel(Input_Flag);
    }   
}
void Admin_Panel(u8 Input_Key)
{
    if(Password_Check(Input_Key))
    {
        HAL_LCD_Clear();
        HAL_LCD_Set_Courser(2,0);
        HAL_LCD_Send_String("-Enter ID : ");
        Input_Key=HAL_Keypad_Wait_For_Input();
        HAL_LCD_Send_Data(Input_Key);
        HAL_LCD_Set_Courser(3,0);
        DataBase[DataBase_Index++].Valid_ID=Input_Key;
        HAL_LCD_Send_String("Done  ");
        HAL_LCD_Clear();
    }
    else
    {
        HAL_LCD_Clear();
        HAL_LCD_Set_Courser(2,0);
        HAL_LCD_Send_String("---xxxxxxxxxx---");
    }
}
u8 Password_Check(u8 First_Char)
{
    /*Check For Password*/
    u8 Password_Flag=ZERO;
    HAL_LCD_Set_Courser(3,6);
    HAL_LCD_Send_Data('*');
    if(First_Char==Admin_Passowrd[0])Password_Flag++;
    for(u8 Counter=ONE;Counter<FOUR;Counter++)
    {
        First_Char=HAL_Keypad_Wait_For_Input();HAL_LCD_Send_Data('*');
        if(Admin_Passowrd[Counter]==First_Char)Password_Flag++;
    }
    return Password_Flag==4?ONE:ZERO;
}
void EXTI_Entrance_ISR(void)
{
    u16 Data='X';
    /*Enable Slave*/
    MCAL_GPIO_Write_Pin(SS_Port,Entrance_SS,LOW);
    /*Read Data*/
    SPI_Send_Receive_Data(&SPI,&Data);
    /*Inform Admin*/
    HAL_LCD_Clear();
    //HAL_LCD_Send_String("----ENTRANCE----");
    //HAL_LCD_Set_Courser(1,0);
    HAL_LCD_Send_String("Client ID : ");
    HAL_LCD_Send_Data(Data);
    /*Check Data*/
    u16 ID_Found_Flag='0',Counter;
    for(Counter=ZERO;Counter<DataBase_Index;Counter++)
    {
        if(DataBase[Counter].Valid_ID==Data)
        {
            Garage_Clients++;
            ID_Found_Flag=Garage_Clients<3?'1':'2';
            break;
        }
    }
    /*Inform Admin With State*/
    HAL_LCD_Set_Courser(3,0);
    HAL_LCD_Send_String(ID_Found_Flag=='1'?"Valid":"Not Valid !");
    /*Send Result*/
    SPI_Send_Receive_Data(&SPI,&ID_Found_Flag);
    /*Disable Slave*/
    MCAL_GPIO_Write_Pin(SS_Port,Entrance_SS,HI);
    /*Clear Screen*/
    HAL_LCD_Clear();
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
    /*Initialize Keypad*/
    HAL_Keypad_Initialization();
    /*Initialize LCD*/
    HAL_LCD_Initialization();
    /*Initialize SS_Entrance*/
    MCAL_GPIO_Initialize(SS_Port,A0);
    MCAL_GPIO_Write_Pin(SS_Port,Entrance_SS,HI);
    /*Initialize SPI*/
    SPI_Initialization(&SPI);
    /*Initialize External Interrupt*/
    EXTI_Initilization(EXTI_Entrance);
    /*Initialize 7-Segment*/
    Seven_Segment_Initialization(&Segment);
}
/********************************************************************
 *  END OF FILE:  Application.c
********************************************************************/
