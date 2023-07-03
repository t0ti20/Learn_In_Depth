/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Pressure_Detection.c
 *  Brief:  Main Algorithm File
 *  Description:  Logic C File Implementation Of Pressure Detection System
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Pressure_Detection.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : void Main_Algorithm(void)
* Description     : Main Algorithm For The Project
* Parameters (in) : None
* Parameters (out): None
* Return value:   : void
********************************************************************/
/////////////////////////////////

// Define the base address of GPIO Port B
#define GPIOB_BASE_ADDRESS 0x40010C00

// Registers' offsets
#define GPIOx_CRL_OFFSET 0x00
#define GPIOx_CRH_OFFSET 0x04
#define GPIOx_ODR_OFFSET 0x0C

// GPIO Pin Modes (Output: 0b0011)
#define GPIO_MODE_OUTPUT 0x03

// GPIO Pin Speed (High: 0b11)
#define GPIO_SPEED_HIGH 0x03

/////////////////////////////////
void Main_Algorithm(void)
{
     //////////////////////
      // Enable GPIOB clock
    *((unsigned int*)(0x40021018)) |= 1 << 3;

    // Configure all pins of Port B as output
    *((unsigned int*)(GPIOB_BASE_ADDRESS + GPIOx_CRL_OFFSET)) = (GPIO_MODE_OUTPUT << 0) | (GPIO_MODE_OUTPUT << 4) |
                                                               (GPIO_MODE_OUTPUT << 8) | (GPIO_MODE_OUTPUT << 12) |
                                                               (GPIO_MODE_OUTPUT << 16) | (GPIO_MODE_OUTPUT << 20) |
                                                               (GPIO_MODE_OUTPUT << 24) | (GPIO_MODE_OUTPUT << 28);

    *((unsigned int*)(GPIOB_BASE_ADDRESS + GPIOx_CRH_OFFSET)) = (GPIO_MODE_OUTPUT << 0) | (GPIO_MODE_OUTPUT << 4) |
                                                               (GPIO_MODE_OUTPUT << 8) | (GPIO_MODE_OUTPUT << 12);

    // Set GPIO speed to high for all pins of Port B
    *((unsigned int*)(GPIOB_BASE_ADDRESS + GPIOx_CRL_OFFSET)) |= (GPIO_SPEED_HIGH << 2) | (GPIO_SPEED_HIGH << 6) |
                                                                (GPIO_SPEED_HIGH << 10) | (GPIO_SPEED_HIGH << 14) |
                                                                (GPIO_SPEED_HIGH << 18) | (GPIO_SPEED_HIGH << 22) |
                                                                (GPIO_SPEED_HIGH << 26) | (GPIO_SPEED_HIGH << 30);

    *((unsigned int*)(GPIOB_BASE_ADDRESS + GPIOx_CRH_OFFSET)) |= (GPIO_SPEED_HIGH << 2) | (GPIO_SPEED_HIGH << 6) |
                                                                (GPIO_SPEED_HIGH << 10) | (GPIO_SPEED_HIGH << 14);
     //////////////////////
     int Pressure=0;
     while (True)
     {
          Pressure=(GPIOA_IDR & 0xFF);
          *((unsigned int*)(GPIOB_BASE_ADDRESS + GPIOx_ODR_OFFSET)) ^= Pressure;
          if(Pressure>=20)
          {
               
               Set_Alarm_actuator(1);
          }
          else 
          {    
               Set_Alarm_actuator(0);
          }
     }
}