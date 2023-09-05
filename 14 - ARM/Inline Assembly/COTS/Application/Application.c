#include "EXTI_Interface.h"
#include "GPIO_Interface.h"
u8 static Flag=0;
void isr(void);
void isr(void)
{
	int IPSR_Register;
	/*__asm("ISA_Command Operant_1,%(Input_Output_Number)" :"=r" (Output_Value) :"r" (Input_Value));*/
	/*Write Inline Assembly Function To Add Two Numbers*/
	// __asm
	// (
	// 	"add %[Result],%[Operand_1],%[Operand_2]"
	// 	/*Output Paramiters*/
	// 	:[Result] "=r"(Number_1)
	// 	/*Inputs Paramiters*/
	// 	:[Operand_1]"r"(Number_1),
	// 	 [Operand_2]"r"(Number_2)
	// );
	/*Read IPSR And Store It In IPSR_Register*/
	__asm
	(
		"MRS R0,IPSR \n\t MOV %[Register],R0"
		:[Register] "=r"(IPSR_Register)
	);
	Flag^=1;
}
int main(void) 
 {
	int Control_Register;
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
		/*Read CONTROL And Store It In Control_Register*/
		__asm
		(
			"MRS R0,CONTROL \n\t MOV %[Register],R0"
			:[Register] "=r"(Control_Register)
		);
		if(Flag)MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_1);
	}
}
