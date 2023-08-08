#include "GPIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "EXTI_Interface.h"
#include "RCC_Interface.h"
#include "Seven_Segment_Interface.h"
#include "USART_Interface.h"
#include "SPI_Interface.h"
#include "I2C_Interface.h"
#include "EEPROM_Interface.h"
int main(void) 
{
    u8 Data_Transmitted[5]={0x11,0x22,0x33,0x44,0x55},Data_Received[5]={0};
    EEPROM_Initialization();
    while (1)
    {
        EEPROM_Write(0x1234,Data_Transmitted,5);
        EEPROM_Read(0x1234,Data_Received,5);
        delay_ms(1000);
    }
}
