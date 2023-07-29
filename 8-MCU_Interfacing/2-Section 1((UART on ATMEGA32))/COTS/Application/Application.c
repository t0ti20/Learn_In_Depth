#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
int main(void)
{
	u8 Data[10];
	UART_VidInitialization(Transmit_Recive,Rx_Disable,Tx_Disable);
	LCD_VidInitialization();
	while(1)
	{
		UART_VidReceive_String(Data);
		UART_VidSend_String(Data);
		LCD_VidSend_String(Data);
		delay_ms(1000);
/* 		LCD_VidSend_String(String);
		LCD_VidSet_Position(1,1);
		LCD_VidSend_String(String);
		delay_ms(1000);
		LCD_VidClear(); */
	}
}