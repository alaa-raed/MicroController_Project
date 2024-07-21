#define F_CPU 16000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include"lcd.h"
#include "flex_sensor.h"
#include "adc.h"
#include "gpio.h"
#include <util/delay.h>
#define F_CPU 16000000UL
int main()
{
	DDRA&=~(1<<0);	//PA0 input
	DDRD|=(1<<0);	//PD0 output
	
	while(1)
	{
		if(PINA&(1<<0)==1)
		{
			PORTD|=(1<<0);
			//_delay_ms(25);
		}
		else{
			PORTD&=~(1<<0);
			//_delay_ms(25);
		}


	}
}
