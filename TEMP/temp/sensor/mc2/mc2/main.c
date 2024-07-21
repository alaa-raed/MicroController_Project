/******************************************************************************
 *
 * Module: main file
 *
 * File Name: main.c
 *
 * Description: Project main file
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include "flex_sensor.h"
#include "adc.h"
#include "gpio.h"
#include <util/delay.h>
#include "uart.h"
#define CONST_RESISTANCE 14000
int main()
{	
int vReal,vImg;
/* UART config */
UART_ConfigType UART_Config = {CHARACTER_SIZE_8,Even,UART_STOP_1BIT_SELECT,9600};
UART_init(&UART_Config);
ADC_ConfigType currentConfig;
currentConfig.prescaler=PRESCALER_128;
currentConfig.reference_mode=AVCC_MODE;
ADC_init(&currentConfig);
DDRA&=~(1<<0);
DDRC|=(1<<0);
while(1)
{
	if(PINA&(1<<0)==1)
	{
		PORTC|=(1<<0);
		vReal=3;
		vImg=3;
		//_delay_ms(25);
		UART_sendByte(vReal);
		UART_sendByte(vImg);
		UART_sendByte(0);
		
	}
	else{
		PORTC&=~(1<<0);
		vReal=3;
		vImg=3;
		//_delay_ms(25);
		UART_sendByte(vReal);
		UART_sendByte(vImg);
		UART_sendByte(1);
		
	}
		
}
}
