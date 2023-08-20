#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
int main(void)
{
	DIO_VidSet_Pin_Direction(Port_A,Pin_0,OUTPUT);
	u8 Arr[15];
	UART_VidInitialization(Transmit_Recive,Rx_Enable,Tx_Disable);	
	UART_VidReceive_String(Arr);
	while(1)
	{
		DIO_VidToggle_Pin_Value(Port_A,Pin_0);
		delay_ms(1000);
	}
}