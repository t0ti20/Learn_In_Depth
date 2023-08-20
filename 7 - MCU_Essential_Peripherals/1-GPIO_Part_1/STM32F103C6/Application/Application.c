#include "../MCAL/RCC/RCC_Interface.h"
typedef volatile struct GPIOx_CRL_t
{
    volatile u32 Pin_0:4;volatile u32 Pin_1:4;volatile u32 Pin_2:4;volatile u32 Pin_3:4;volatile u32 Pin_4:4;
    volatile u32 Pin_5:4;volatile u32 Pin_6:4;volatile u32 Pin_7:4;
}GPIOx_CRL_t;
#define GPIOA_BASE      0x40010800
#define GPIOB_BASE      0x40010C00
#define GPIOx_CRL       0x00
#define GPIOx_CRH       0x04
#define GPIOx_IDR       0x08
#define GPIOx_ODR       0x0C
//outputs
#define GPIOB_ODR       (*((volatile Regester_t*)(GPIOB_BASE + GPIOx_ODR)))
#define GPIOB_CRL       (*((volatile GPIOx_CRL_t*)(GPIOB_BASE + GPIOx_CRL)))
#define GPIOB_CRH       (*((volatile GPIOx_CRL_t*)(GPIOB_BASE + GPIOx_CRH)))
//inputs
#define GPIOA_CRL       (*((volatile GPIOx_CRL_t*)(GPIOA_BASE + GPIOx_CRL)))
#define GPIOA_CRH       (*((volatile GPIOx_CRL_t*)(GPIOA_BASE + GPIOx_CRH)))
#define GPIOA_IDR       (*((volatile u32*)(GPIOA_BASE + GPIOx_IDR)))
int Intery_Function(void) 
{
    //configure gpio
    MCAL_RCC_Enable_Clock(RCC_GPIOA);//enable clock to port a
    MCAL_RCC_Enable_Clock(RCC_GPIOB);//enable clock to port b
    GPIOA_CRL.Pin_1=0b0100;//set A1 Floating Input- Input
    GPIOA_CRH.Pin_5=0b0100;//set A13 Floating Input- Input

    GPIOB_CRL.Pin_1=0b0001;//Set B1 output pushpull speed 10mhz
    GPIOB_CRH.Pin_5=0b0001;//Set B13 output pushpull speed 10mhz
    GPIOB_ODR.Bits.Bit_1=1;
    GPIOB_ODR.Bits.Bit_13=1;
    while (1) {
        if(!Get_Bit(GPIOA_IDR,1))
        {
            GPIOB_ODR.Bits.Bit_1=0;
            for(int i=0;i<100000;i++);
            GPIOB_ODR.Bits.Bit_1=1;
            for(int i=0;i<100000;i++);
            while(!Get_Bit(GPIOA_IDR,1));
        }
        while(Get_Bit(GPIOA_IDR,13))
        {
            GPIOB_ODR.Bits.Bit_13=0;
            for(int i=0;i<100000;i++);
            GPIOB_ODR.Bits.Bit_13=1;
            for(int i=0;i<100000;i++);
        }
    }
}
