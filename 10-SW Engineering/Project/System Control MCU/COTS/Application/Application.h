/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Application.h
 *  Module:  ./Application
 *  Description:  Application Headder File
*******************************************************************/
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/********************************************************************/
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "EXTI_Interface.h"
#include "Seven_Segment_Interface.h"
#include "Keypad_Interface.h"
#include "SPI_Interface.h"
/*****************************************
--------    Type  Definitions    ---------
*****************************************/
typedef struct DataBase_t
{
    u8 Valid_ID;
}DataBase_t;
/*****************************************
---------    Configure Macros    ---------
*****************************************/
/*-------------- ECU Pins --------------*/
#define ECU_Port                        (GPIO_A)
#define Entrance_Pin                    (Pin_3)
#define Exit_Pin                        (Pin_4)
/*------------ ECU SS Pins -------------*/
#define SS_Port                         (GPIO_A)
#define Entrance_SS                     (Pin_0)
#define Exit_SS                         (Pin_1)
/*------------ ECU SS Pins -------------*/
#define Seven_Segment_Port              (GPIO_B)
#define Seven_Segment_Pins              {Pin_7,Pin_8,Pin_9,Pin_10,Pin_11,Pin_12,Pin_13,Pin_14}
#define Seven_Segment_Enable            (Pin_15)
/*------------ Application -------------*/
#define Max_ID                          (10)
#define Admin_Password                  "1234"


/*****************************************
---  Application Programming Interface  --
*****************************************/
/********************************************************************
* Syntax          : GPIO_VidInternal_Pin_Bull_Up(u8 Copy_u8Port, u8 Copy_u8Pin)
* Description     : Set the internal pull-up for a specific GPIO pin.
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : Copy_u8Port (Port identifier), Copy_u8Pin (Pin number)
* Parameters (out): None
* Return value    : Void
********************************************************************/
void Application_VidSystem_Initialization(void);
void EXTI_Entrance_ISR(void);
u8 Password_Check(u8 First_Char);
/********************************************************************
 *  END OF FILE:  Application.h
********************************************************************/
#endif
