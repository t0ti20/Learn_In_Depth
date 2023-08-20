#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"
#define MASTER
//#define SLAVE
#ifdef SLAVE
int main(void)
{
	u8 Data;
	SPI_VidInitialization(Slave,SPI_Interrupt_Disable);
	while(1)
	{
		SPI_VidSend_Receive(SPI_Receive,&Data);
		DIO_VidSet_Port_Value(Port_C,Data);
	}
}
#endif
#ifdef MASTER
void Send_Segment(u8 Location,u8 Data)
{
	/*Enable Chip*/
	DIO_VidSet_Pin_Value(Port_B,Pin_4,LOW);
	/*Send Command*/
	SPI_VidSend_Receive(SPI_Send,&Location);
	/*Send Data*/
	SPI_VidSend_Receive(SPI_Send,&Data);
	/*Disable Chip*/
	DIO_VidSet_Pin_Value(Port_B,Pin_4,HI);
}
int main(void)
{
	SPI_VidInitialization(Master,SPI_Interrupt_Disable);
	DIO_VidSet_Pin_Direction(Port_B,Pin_4,OUTPUT);
	DIO_VidSet_Pin_Value(Port_B,Pin_4,HI);
	DIO_VidSet_Whole_Port_Direction(Port_C,OUTPUT);
	//Normal Operation
	Send_Segment(0x0C,1);
	//Decode-Mode Register
	Send_Segment(0x09,0xff);
	//Intensity Register Format
	Send_Segment(0x0A,0x0f);
	//Scan-Limit Register Format
	Send_Segment(0x0B,0X07);
	u32 Counter=0,Temp;
	while(++Counter)
	{
		Temp=Counter;
		for (u8 i=1;i<9;i++)
		{
			if((Temp&0xf)>9){Counter+=5;break;}
			Send_Segment(i,Temp&0xf);
			Temp>>=4;
		}
		delay_ms(2000);
/* 		SPI_VidSend_Receive(SPI_Send,&Data);
		DIO_VidSet_Pin_Value(Port_B,Pin_4,HI);
		DIO_VidSet_Port_Value(Port_C,Data);
		delay_ms(5000); */
	}
}
#endif