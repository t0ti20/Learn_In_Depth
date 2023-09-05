#include "EXTI_Interface.h"
#include "GPIO_Interface.h"
u8 static Flag=0;
void isr(void);
void isr(void)
{
	Flag^=1;
}
int main(void) 
{
	EXTI_Config_t EXTI_1;
	GPIO_Pin_Config_t Pin;
	
/*--------------------------------*/
	Pin.Pin_Mode=Output_Push_Pull;
	Pin.Pin_Number=Pin_1;
	Pin.Pin_Speed=Output_10;
/*--------------------------------*/
	EXTI_1.Port=GPIO_A;
	EXTI_1.Pin=Pin_0;
	EXTI_1.Sensing_Edge=Faling_Rising;
	EXTI_1.Interrupt=Enable;
	EXTI_1.Event=Disable;
	EXTI_1.Ptr_Function=isr;
/*--------------------------------*/
	EXTI_Initilization(EXTI_1);
	MCAL_GPIO_Initialize(GPIO_A,Pin);
	while (1)
	{
		if(Flag)MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_1);
	}
}
