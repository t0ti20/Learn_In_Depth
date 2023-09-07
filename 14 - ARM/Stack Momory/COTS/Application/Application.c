#include "EXTI_Interface.h"
#include "GPIO_Interface.h"
/*--------------------------------*/
#define SET_PSP(Task_Address)		__asm volatile	("MOV r0,%0\n\tMSR PSP,r0"::"r"(Task_Address))
#define Switch_PSP					__asm volatile	("MRS R0,CONTROL\n\tORR R0,R0,#2\n\tMSR CONTROL,R0")
#define Switch_MSP					__asm volatile	("MRS R0,CONTROL\n\tBFC R0,#1,#1\n\tMSR CONTROL,R0")
#define Switch_Privileged			__asm volatile  ("MRS R0,CONTROL\n\tBFC R0,#0,#1\n\tMSR CONTROL,R0")
#define Switch_Unprivileged			__asm volatile  ("MRS R0,CONTROL\n\tORR R0,R0,#1\n\tMSR CONTROL,R0")
#define Supervisor_Call				__asm volatile	("SVC #3")
/*--------------------------------*/
void OS_Initialization(void);
int Task_B(int X,int Y);
int Task_A(int X,int Y);
void SVC_Handler(void);
void isr(void);
extern int Top_Of_Stack;
extern int Base_Of_Stack;
u8 static Flag_A=0,Flag_B=0;
/*--------------------------------*/
#define  Task_A_Stack_Size		50
#define  Task_B_Stack_Size		50
/*--------------------------------*/
static u32 _Start_MSP_=(u32)&Top_Of_Stack;
static u32 _End_MSP_=(u32)&Top_Of_Stack;
/*--------------------------------*/
static u32 _Task_A_Start_PSP_;
static u32 _Task_A_End_PSP_;
/*--------------------------------*/
static u32 _Task_B_Start_PSP_;
static u32 _Task_B_End_PSP_;
/*--------------------------------*/
int Task_A(int X,int Y)
{
	return X+Y;
}
/*--------------------------------*/
int Task_B(int X,int Y)
{
	return X-Y;
}
/*--------------------------------*/
void SVC_Handler (void)
{
	Switch_Privileged;
}
/*--------------------------------*/
void isr(void)
{
	static int Scheduler=0;
	if(Scheduler%3==1){Flag_A=1;Flag_B=0;}
	else if(Scheduler%3==2){Flag_A=0;Flag_B=1;}
	else{Flag_A=0;Flag_B=0;}
	Scheduler++;
}
/*--------------------------------*/
void OS_Initialization(void)
{
	_End_MSP_-=512;
	_Task_A_Start_PSP_=_End_MSP_-8;
	_Task_A_End_PSP_=_Task_A_Start_PSP_-Task_A_Stack_Size;
	_Task_B_Start_PSP_=_Task_A_End_PSP_-8;
	_Task_B_End_PSP_=_Task_B_Start_PSP_-Task_B_Stack_Size;
}
/*--------------------------------*/
int main(void) 
 {
	int volatile Result=0;
	EXTI_Config_t EXTI_1;
	OS_Initialization();
	if(_Start_MSP_){}
	if(_End_MSP_){}
	if(_Task_A_Start_PSP_){}
	if(_Task_A_End_PSP_){}
	if(_Task_B_Start_PSP_){}
	if(_Task_B_End_PSP_){}
/*--------------------------------*/
	EXTI_1.Port=GPIO_A;
	EXTI_1.Pin=Pin_0;
	EXTI_1.Sensing_Edge=Faling_Rising;
	EXTI_1.Interrupt=Enable;
	EXTI_1.Event=Disable;
	EXTI_1.Ptr_Function=isr;
/*--------------------------------*/
	EXTI_Initilization(EXTI_1);
/*--------------------------------*/
	while (1)
	{
		if(Flag_A)
		{
			/*Set PSP -> _Task_A_Start_PSP_*/
			SET_PSP(_Task_A_Start_PSP_);
			/*Set Sp -> PSP*/
			Switch_PSP;
			/*Turn Unprivallage*/
			Switch_Unprivileged;
			/*Run Task*/
			Result=Task_A(20,10);
			/*Return privallage*/
			Supervisor_Call;
			/*Set Sp -> MSP*/
			Switch_MSP;
			Flag_A=0;
		}
		else if(Flag_B)
		{
			/*Set PSP -> _Task_B_Start_PSP_*/
			SET_PSP(_Task_B_Start_PSP_);
			/*Set Sp -> PSP*/
			Switch_PSP;
			/*Turn Unprivallage*/
			Switch_Unprivileged;
			/*Run Task*/
			Result=Task_B(20,10);
			/*Return privallage*/
			Supervisor_Call;
			/*Set Sp -> MSP*/
			Switch_MSP;
			Flag_B=0;
		}
		else{}
		if(Result){}
	}
}
