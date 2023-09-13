#include "EXTI_Interface.h"
#include "GPIO_Interface.h"
/*--------------------------------*/
#define SET_PSP(Task_Address)				__asm volatile	("MOV r0,%0\n\tMSR PSP,r0"::"r"(Task_Address))
#define Switch_PSP						__asm volatile	("MRS R0,CONTROL\n\tORR R0,R0,#2\n\tMSR CONTROL,R0")
#define Switch_MSP						__asm volatile	("MRS R0,CONTROL\n\tBFC R0,#1,#1\n\tMSR CONTROL,R0")
#define Switch_Privileged				__asm volatile ("MRS R0,CONTROL\n\tBFC R0,#0,#1\n\tMSR CONTROL,R0")
#define Switch_Unprivileged				__asm volatile ("MRS R0,CONTROL\n\tORR R0,R0,#1\n\tMSR CONTROL,R0")
#define Supervisor_Call					__asm volatile	("SVC #3")
/*--------------------------------*/
typedef enum Services_t
{
	Add				=(1UL),
	Multiply			=(2UL),
	Subtraction		=(3UL)
}Services_t;
/*--------------------------------*/
static int Flag=0;
u32 OS_Service(u32 Argument_1,u32 Argument_2,Services_t Service_ID);
void SVC_Number(u32*Stack_Pointer);
void SVC_Handler(void);
void isr(void);
/*--------------------------------*/
void SVC_Number (u32*Stack_Pointer)
{
	/*Stack_Pointer_Frame*/
	/*	
		[7]		->		XPSR		(Core_Register_Interrupt_number)
		[6]		->		PC		(Program_Counter)
		[5]		->		LR		(Linkk Register "MSP-PSP Return Info")
		[4]		->		r12		()
		[3]		->		r3		()
		[2]		->		r2		(Argument_3)
		[1]		->		r1		(Argument_2)
		[0]		->		r0		(Argument_1,Return Value)
	*/
	switch((((u8*)(Stack_Pointer[6]))[-2]))
	{
		case Add:Stack_Pointer[0]=Stack_Pointer[1]+Stack_Pointer[2];break;
		case Multiply:Stack_Pointer[0]=Stack_Pointer[1]*Stack_Pointer[2];break;
		case Subtraction:Stack_Pointer[0]=Stack_Pointer[1]/Stack_Pointer[2];break;
	}
}
__attribute ((naked)) void SVC_Handler(void)
{
	__asm("TST LR,#4\n\tITE EQ\n\tMRSEQ r0,MSP\n\tMRSNE r0,PSP\n\tB SVC_Number");
}
/*--------------------------------*/
u32 OS_Service(u32 Argument_1,u32 Argument_2,Services_t Service_ID)
{
	u32 Result=0;
	switch (Service_ID)
	{
		case Add:__asm("SVC #1");break;
		case Multiply:__asm("SVC #2");break;
		case Subtraction:__asm("SVC #3");break;
	}
	return Result;
}
/*--------------------------------*/
void isr(void)
{
	Flag^=1;
}
/*--------------------------------*/
int main(void) 
 {
	u32 Result=100;
	EXTI_Config_t EXTI_1={GPIO_A,Pin_0,Faling_Rising,Enable,Disable,isr};
	GPIO_Pin_Config_t Pin={Pin_1,Output_Push_Pull,Output_10};
/*--------------------------------*/
	EXTI_Initilization(EXTI_1);
	MCAL_GPIO_Initialize(GPIO_A,Pin);
/*--------------------------------*/
	while (1)
	{
		Result=OS_Service(10,20,Subtraction);
		if(Flag)MCAL_GPIO_Toggle_Pin(GPIO_A,Pin_1);
	}
}
