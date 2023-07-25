/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  EXTI_Interface.h
 *  Module:  MCAL/EXTI
 *  Description:  External Interrupt Device Driver Program File
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "EXTI_Interface.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
static void NVIC_Initialize(NVIC_Config_t Interrupt)
{
     /*Enable Disable Interrupt*/
     if(Interrupt.State==Enable)Set_Bit(NVIC.ISERX[Interrupt.Interrupt_Number/32].Register,(Interrupt.Interrupt_Number%32));
     else Set_Bit(NVIC.ICERX[Interrupt.Interrupt_Number/32].Register,(Interrupt.Interrupt_Number%32));
}
static void (*volatile EXTI0_IRQ_Call_Back_Function[15])(void)={NULL};
/********************************************************************
* Syntax          : MCAL_GPIO_Lock_Pin(GPIOX_t *Port,GPIO_Pin_t Pin)
* Description     : Lock State For Specific Pin
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To The Port "GPIOX->X=A,B,C,D,E"),(Copy To Pin Number "Pin_Number_t")
* Parameters (out): None
* Return value:   : Void
********************************************************************/
void EXTI_Initilization(EXTI_Config_t Configure)
{
	NVIC_Config_t External_Interrupt;
     GPIO_Pin_Config_t EXTI_Pin={Pin_0,Alternate_Input,Input};
     u8 External_Interrupt_Map[16]=EXTI_Pins_Victor_Map;
     /*Enable GPIO And AFIO Clock*/
     RCC_Pheripheral_Enable(APB2ENR,AFIOEN);
     /*Configure GPIO As Input */
     EXTI_Pin.Pin_Number=Configure.Pin;
     MCAL_GPIO_Initialize(Configure.Port,EXTI_Pin);
     /*External Interrupt Configuration Register*/
     AFIO.EXTICRX[((Configure.Pin)/FOUR)].Register&=(u32)~((0xF)<<(((Configure.Pin)%FOUR)*FOUR));
     AFIO.EXTICRX[((Configure.Pin)/FOUR)].Register|=(u32)((Configure.Port)<<(((Configure.Pin)%FOUR)*FOUR));
     /*Rising Edge Configure*/
     switch (Configure.Sensing_Edge)
     {
          case Faling_Edge:Set_Bit(EXTI.FTSR.Register,Configure.Pin);Clear_Bit(EXTI.RTSR.Register,Configure.Pin);break;
          case Rising_Edge:Set_Bit(EXTI.RTSR.Register,Configure.Pin);Clear_Bit(EXTI.FTSR.Register,Configure.Pin);break;
          case Faling_Rising:Set_Bit(EXTI.RTSR.Register,Configure.Pin);Set_Bit(EXTI.FTSR.Register,Configure.Pin);break;
     }
     /*Configure Interrupts*/
     if(Configure.Interrupt==Enable)Set_Bit(EXTI.IMR.Register,Configure.Pin);
     else Clear_Bit(EXTI.IMR.Register,Configure.Pin);
     /*Configure Event*/
     if(Configure.Event==Enable)Set_Bit(EXTI.EMR.Register,Configure.Pin);
     else Clear_Bit(EXTI.EMR.Register,Configure.Pin);
     /*Configure Call Back Function*/
     EXTI0_IRQ_Call_Back_Function[Configure.Pin]=Configure.Ptr_Function;
     /*Enable NVIC Mask*/
     External_Interrupt.Interrupt_Number=External_Interrupt_Map[Configure.Pin];
     External_Interrupt.State=Enable;
     NVIC_Initialize(External_Interrupt);
}
/********************************************************************
* Syntax          : MCAL_GPIO_Lock_Pin(GPIOX_t *Port,GPIO_Pin_t Pin)
* Description     : Lock State For Specific Pin
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To The Port "GPIOX->X=A,B,C,D,E"),(Copy To Pin Number "Pin_Number_t")
* Parameters (out): None
* Return value:   : Void
********************************************************************/
extern void EXTI0_IRQHandler(void);
extern void EXTI0_IRQHandler(void)
{
     /*Execute ISR*/
     EXTI0_IRQ_Call_Back_Function[0]();
     /*Clear Flag*/
     EXTI.PR.Bits.Bit_0=HI;
}
extern void EXTI1_IRQHandler(void);
extern void EXTI1_IRQHandler(void)
{
     /*Execute ISR*/
     EXTI0_IRQ_Call_Back_Function[1]();
     /*Clear Flag*/
     EXTI.PR.Bits.Bit_1=HI;
}
extern void EXTI2_IRQHandler(void);
extern void EXTI2_IRQHandler(void)
{
     /*Execute ISR*/
     EXTI0_IRQ_Call_Back_Function[2]();
     /*Clear Flag*/
     EXTI.PR.Bits.Bit_2=HI;
}
extern void EXTI3_IRQHandler(void);
extern void EXTI3_IRQHandler(void)
{
     /*Execute ISR*/
     EXTI0_IRQ_Call_Back_Function[3]();
     /*Clear Flag*/
     EXTI.PR.Bits.Bit_3=HI;
}
extern void EXTI4_IRQHandler(void);
extern void EXTI4_IRQHandler(void)
{
     /*Execute ISR*/
     EXTI0_IRQ_Call_Back_Function[4]();
     /*Clear Flag*/
     EXTI.PR.Bits.Bit_4=HI;
}
extern void EXTI9_5_IRQHandler(void);
extern void EXTI9_5_IRQHandler(void)
{
     /*Get Interrupt Source And Clear Flag*/
     if(EXTI.PR.Bits.Bit_5){EXTI0_IRQ_Call_Back_Function[5]();EXTI.PR.Bits.Bit_5=HI;}
     if(EXTI.PR.Bits.Bit_6){EXTI0_IRQ_Call_Back_Function[6]();EXTI.PR.Bits.Bit_6=HI;}
     if(EXTI.PR.Bits.Bit_7){EXTI0_IRQ_Call_Back_Function[7]();EXTI.PR.Bits.Bit_7=HI;}
     if(EXTI.PR.Bits.Bit_8){EXTI0_IRQ_Call_Back_Function[8]();EXTI.PR.Bits.Bit_8=HI;}
     if(EXTI.PR.Bits.Bit_9){EXTI0_IRQ_Call_Back_Function[9]();EXTI.PR.Bits.Bit_9=HI;}
}
extern void EXTI15_10_IRQHandler(void);
extern void EXTI15_10_IRQHandler(void)
{
     /*Get Interrupt Source And Clear Flag*/
     if(EXTI.PR.Bits.Bit_10){EXTI0_IRQ_Call_Back_Function[5]();EXTI.PR.Bits.Bit_10=HI;}
     if(EXTI.PR.Bits.Bit_12){EXTI0_IRQ_Call_Back_Function[6]();EXTI.PR.Bits.Bit_12=HI;}
     if(EXTI.PR.Bits.Bit_13){EXTI0_IRQ_Call_Back_Function[7]();EXTI.PR.Bits.Bit_13=HI;}
     if(EXTI.PR.Bits.Bit_14){EXTI0_IRQ_Call_Back_Function[8]();EXTI.PR.Bits.Bit_14=HI;}
     if(EXTI.PR.Bits.Bit_15){EXTI0_IRQ_Call_Back_Function[9]();EXTI.PR.Bits.Bit_15=HI;}
}
/********************************************************************
 *  END OF FILE:  EXTI_Program.c
********************************************************************/
