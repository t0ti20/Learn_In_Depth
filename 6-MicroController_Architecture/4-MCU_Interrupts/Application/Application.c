#define GPIOA_BASE      0x40010800
#define GPIOA_CRH       (*((volatile unsigned int*)(GPIOA_BASE + 0x04)))
#define GPIOA_ODR       (*((volatile unsigned int*)(GPIOA_BASE + 0x0C)))
#define GPIOA_CRL       (*((volatile unsigned int*)(GPIOA_BASE + 0x00)))
#define AFIO_BASE       0x40010000
#define AFIO_EXTICR1    (*((volatile unsigned int*)(GPIOA_BASE + 0x08)))
#define NVIC_EXTIE0     (*((volatile unsigned int*)(0xE000E100)))
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/NVIC/NVIC_Interface.h"
void isr()
{
    GPIOA_ODR^=(1<<13);//toggle pin 13
}
int Intery_Function(void) 
{
    //configure gpio
    MCAL_RCC_Enable_Clock(RCC_AFIO);//enable clock to Altrnative Module
    MCAL_RCC_Enable_Clock(RCC_GPIOA);//enable clock to port a
    GPIOA_CRH &= 0xFF0FFFFF;  // Clear bits 21-22 for pin 13
    GPIOA_CRH |= 0x00200000;  // Set mode bits 21-22 for pin 13 (output, push-pull)
    GPIOA_CRL |= (1<<2);//set pin 0 input floating
    AFIO_EXTICR1=0;//SET ALTERNATE FUNCTION
    //configure interrupt
    NVIC_EXTIE0|=(1<<6);//enable nvic exit 0 interrupt from core phereferal
    MCAL_EXTI_Configure_Line(Line_0);//setup line 0 interrupt sensing
    MCAL_EXTI_0_ISR_Function(isr);//pass isr function to jump
    while (1) {
        // GPIOA_ODR ^= (1 << 13);
    }
}
