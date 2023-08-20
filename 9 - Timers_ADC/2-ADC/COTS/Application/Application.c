#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"
#include "EXTI_Interface.h"
#include "TMR_Interface.h"
void itoa(u16 Data,u8 String[]);
int main(void)
{
     u8 Char[]=Heart;
     u16 Reading;
     u8 Array[16];
     LCD_VidInitialization();
     ADC_VidInitialization();
     LCD_VidSend_Special_Character(Char,0,1,0);
     LCD_VidClear();
     while (1)
     {
          ADC_VidAsync_Mapped_Reading(ADC_0,0,100,&Reading);
          itoa(Reading,Array);
          LCD_VidClear();
          LCD_VidSend_String(Array);
          ADC_VidAsync_Mapped_Reading(ADC_0,0,16,&Reading);
          LCD_VidSet_Position(1,0);
          for(u8 Count=0;Count<Reading;Count++)
          {
               LCD_VidSend_Data(0);
          }
          delay_ms(500);
     }
}
void itoa(u16 Data,u8 String[])
{
     u8 Digit=ZERO,Count;
     if(!Data)String[Digit++]='0';
     else for(;Data;Digit++,Data/=TEN)String[Digit]=(Data%TEN+'0');
     String[Digit]=ZERO;
     for(Count=ZERO;Count<(Digit>>ONE);Count++)
     {
          String[Count]^=String[Digit-Count-ONE];
          String[Digit-Count-ONE]^=String[Count];
          String[Count]^=String[Digit-Count-ONE];
     }
}