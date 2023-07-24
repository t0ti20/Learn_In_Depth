#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "Seven_Segment_Interface.h"
int main(void) 
{
    RCC_Pheripheral_Enable(APB2ENR,IOPAEN);
    RCC_Pheripheral_Enable(APB2ENR,IOPBEN);
	Seven_Segment_t  NEW={GPIOB,Common_Cathode,{Pin_8,Pin_9,Pin_10,Pin_11,Pin_12,Pin_13,Pin_14,Pin_15},Pin_7};
    HAL_LCD_Initialization();
    HAL_Keypad_Initialization();
    Seven_Segment_Initialization(NEW);
    while(1)
    {
        u8 i;
        for(i=0;i<10;i++)
        {
            HAL_LCD_Send_Number(i);
            //Seven_Segment_Send_Digit(NEW,i);
            delay_ms(500)
        }
        HAL_LCD_Clear();
        HAL_LCD_Send_String("Enter Any Digit :");
        HAL_LCD_Set_Courser(1,0);
        while(1)
        {
            i=HAL_Keypad_Wait_For_Input();
            HAL_LCD_Send_Data(i);
        }
    }
}
