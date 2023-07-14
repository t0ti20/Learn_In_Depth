#include "../Library/Standard_Types.h"
#include "../Library/Macros.h"
#include <avr/delay.h>
#define  SREG 			(*(volatile u8 *)(0x3F+0x20))
#define  MCUCR 			(*(volatile u8 *)(0x35+0x20))
#define  GICR 			(*(volatile u8 *)(0x3B+0x20))
#define  DDRD		    (*(volatile u8 *)(0x11+0x20))
#define  PORTD			(*(volatile u8 *)(0x12+0x20))

int main(void)
{
	Set_Bit(DDRD,SEVEN);
	Clear_Bit(DDRD,TWO);
	//Bit 6 – INT0: External Interrupt Request 0 Enable
	Set_Bit(GICR,SIX);
	//Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	Set_Bit(MCUCR,ZERO);
	Clear_Bit(MCUCR,ONE);
	//Bit 6 – INTF0: External Interrupt Flag 0
	//Global Interrupt Enable
	Set_Bit(SREG,SEVEN);
	while(1);
}
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	Set_Bit(PORTD,SEVEN);
	_delay_ms(1000);
	Clear_Bit(PORTD,SEVEN);
	_delay_ms(1000);
}
