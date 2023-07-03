#include <stdint.h>
#include <stdio.h>
#include "./driver.h"
#include "Pressure_Detection.h"
void Intery_Function (){
	GPIO_INITIALIZATION();
	while (1)
	{
		//Implement your Design 
		Main_Algorithm();
	}
}