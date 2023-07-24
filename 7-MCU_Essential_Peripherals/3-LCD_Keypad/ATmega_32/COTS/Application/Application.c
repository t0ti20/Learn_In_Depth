#include "DIO_Interface.h"
int main(void)
{
	DIO_VidSet_Whole_Port_Direction(Port_A,OUTPUT);
	DIO_VidSet_Whole_Port_Direction(Port_B,OUTPUT);
	DIO_VidSet_Whole_Port_Direction(Port_C,OUTPUT);
	DIO_VidSet_Whole_Port_Direction(Port_D,OUTPUT);
	while(1)
	{
		for(int i=0;i<8;i++)
		{
			DIO_VidSet_Pin_Value(Port_A,i,HI);
			delay_ms(500);
			DIO_VidSet_Pin_Value(Port_A,i,LOW);
			delay_ms(500);
		}

	}
}