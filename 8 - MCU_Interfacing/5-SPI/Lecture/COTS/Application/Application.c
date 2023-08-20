#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "EXTI_Interface.h"
#include "RCC_Interface.h"
#include "Seven_Segment_Interface.h"
#include "USART_Interface.h"
#include "SPI_Interface.h"
#define MASTER
//#define SLAVE
#ifdef MASTER
static GPIO_Pin_Config_t SS={Pin_4,Output_Push_Pull,Output_10};
static USART_Config_t USART_ONE=UART_Interrupt_Example;
static SPI_Config_t SPI_ONE;
void Function(u16* Data);
void Function(u16* Data)
{
	USART_Transmit(&USART_ONE,*Data);
    MCAL_GPIO_Write_Pin(GPIO_A,Pin_4,LOW);
    SPI_Send_Data(&SPI_ONE,*Data);
    MCAL_GPIO_Write_Pin(GPIO_A,Pin_4,HI);
}
int main(void) 
{
    MCAL_GPIO_Initialize(GPIO_A,SS);
    MCAL_GPIO_Write_Pin(GPIO_A,Pin_4,HI);
    USART_ONE.Call_Back_Function=Function;
    SPI_ONE.SPI_Number=SPI_1;
    SPI_ONE.Phase=SPI_Idle_Hi_Second_Edge;
    SPI_ONE.Size=SPI_8_Bit;
    SPI_ONE.Frame=SPI_MSBF;
    SPI_ONE.Mode=SPI_Master;
    SPI_ONE.Prescalar=SPI_Prescalar_8;
    SPI_ONE.Communication=SPI_Tx_Rx_Two_Line;
    SPI_ONE.Interrupt=SPI_Disable_Interrupt;
    SPI_ONE.Slave_Select=SPI_Software_Enable; 
    SPI_ONE.Call_Back_Function=NULL;
    SPI_Initialization(&SPI_ONE);
    USART_Initialization(&USART_ONE);
    while (1)
    {
        delay_ms(100)
    }
}
#endif
#ifdef SLAVE
static USART_Config_t USART_ONE=UART_Example;
static SPI_Config_t SPI_ONE;
void Function(void);
void Function(void)
{
    u16 Data;
	SPI_Receive_Data(&SPI_ONE,&Data);
    USART_Transmit(&USART_ONE,Data);
}
int main(void) 
{
    SPI_ONE.Call_Back_Function=Function;
    SPI_ONE.SPI_Number=SPI_1;
    SPI_ONE.Phase=SPI_Idle_Hi_Second_Edge;
    SPI_ONE.Size=SPI_8_Bit;
    SPI_ONE.Frame=SPI_MSBF;
    SPI_ONE.Mode=SPI_Slave;
    SPI_ONE.Prescalar=SPI_Prescalar_8;
    SPI_ONE.Communication=SPI_Tx_Rx_Two_Line;
    SPI_ONE.Interrupt=SPI_Rx_Interrupt;
    SPI_ONE.Slave_Select=SPI_Hardware_Slave; 
    SPI_Initialization(&SPI_ONE);
    USART_Initialization(&USART_ONE);
    while (1)
    {
    }
}
#endif
