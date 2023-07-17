#include "../Library/Standard_Types.h"
#include "../Library/Macros.h"
#include <avr/delay.h>
#define  Buzz	4
#define  Led_1	5
#define  Led_2	6
#define  Led_3	7
#define  PORTD 			(*(volatile u8 *)(0x12+0x20))
#define  DDRD 			(*(volatile u8 *)(0x11+0x20))
#define  PIND 			(*(volatile u8 *)(0x10+0x20))
u8 Pins[4]={Led_1,Led_2,Led_3,Buzz};
int main(void)
{
	//set pin direction 1 output
	for(u8 i=0;i<4;i++)Set_Bit(DDRD,Pins[i]);
	while(1)
	{
		for(u8 i=0;i<4;i++)
		{
			Set_Bit(PORTD,Pins[i]);
			_delay_ms(1000);
			Clear_Bit(PORTD,Pins[i]);
			_delay_ms(1000);
		}
	}
}

