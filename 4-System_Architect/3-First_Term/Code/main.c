#include <stdint.h>
#include <stdio.h>
#include "./driver.h"
#include "Pressure_Detection.h"
int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
		Set_Alarm_actuator(1);
		Delay(10000);
		Set_Alarm_actuator(0);
		Delay(10000);
		//Implement your Design 
		//Main_Algorithm();
	}
}