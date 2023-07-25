#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "EXTI_Interface.h"
#include "Seven_Segment_Interface.h"
void mu_fun (void);
static int x=0;
static EXTI_Config_t EXTIPIN={GPIO_B,Pin_9,Rising_Edge,Enable,Disable,mu_fun};
int main(void) 
{
/*     GPIO_Pin_Config_t PIN;
    PIN.Pin_Mode=Output_Push_Pull;
    PIN.Pin_Speed=Output_10;
    PIN.Pin_Number=Pin_0; */
    HAL_LCD_Initialization();
    EXTI_Initilization(EXTIPIN);
    while (1)
    {
        HAL_LCD_Send_Number(x);
        delay_ms(200);
        HAL_LCD_Clear();
    }
}
__attribute__((noreturn)) void mu_fun (void)
{
    x++;
}
