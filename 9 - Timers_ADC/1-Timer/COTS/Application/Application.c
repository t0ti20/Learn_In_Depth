#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"
#include "EXTI_Interface.h"
#include "TMR_Interface.h"
int main(void)
{	
     DIO_VidSet_Pin_Direction(Port_B,Pin_3,OUTPUT);
     TMR_0_VidInitialization(Fast_PWM,255,Disable_CM,Disable_OF,TMR_Pre_Scalar_0);
     while (1)
     {
          for(u8 i=0;i<100;i++)
          {
               TMR_VidPwm_Duty_Cycle(Timer_0,i);
               delay_ms(200);
          }
     }
     
     
	
}