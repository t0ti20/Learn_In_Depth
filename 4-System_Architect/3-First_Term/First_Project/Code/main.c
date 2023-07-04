#include <stdint.h>
#include <stdio.h>
#include "./driver.h"
#include "Pressure_Detection.h"
int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
		//Implement your Design 
		Main_Algorithm();
	}
}