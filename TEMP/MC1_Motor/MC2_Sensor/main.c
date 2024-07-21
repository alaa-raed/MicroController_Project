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
#include "lcd.h"
#define CONST_RESISTANCE 14000
int main()
{	
	LCD_init();
	int vReal,vImg;
	uint16 rPart1,rPart2,rPart3,temp,resAll;
	/* UART config */
	UART_ConfigType UART_Config = {CHARACTER_SIZE_8,Even,UART_STOP_1BIT_SELECT,9600};
	UART_init(&UART_Config);
	ADC_ConfigType currentConfig;
	currentConfig.prescaler=PRESCALER_128;
	currentConfig.reference_mode=AVCC_MODE;
	ADC_init(&currentConfig);
	flex_parameters flexParameters;
	while(1)
	{
		flex_sensor_start(PIN0_ID,&flexParameters,CONST_RESISTANCE);
		vReal=flexParameters.out_voltage;
		vImg=(int)((flexParameters.out_voltage*100))%100;
		rPart1=flexParameters.res %100;
		temp=flexParameters.res /100;
		rPart2=(temp%100);
		rPart3=temp/100;
		resAll=(rPart3*10000)+(rPart2*100)+rPart3;
		LCD_displayStringRowColumn(0,0,"V =");
		LCD_displayChar(' ');
		LCD_intgerToString(vReal);
		LCD_displayChar('.');
		LCD_intgerToString(vImg);
		LCD_displayChar(' ');
		LCD_displayStringRowColumn(1,0,"Res");
		LCD_displayChar(' ');
		LCD_intgerToString(resAll);
		LCD_displayStringRowColumn(1,9," ");
		UART_sendByte(vReal);
		UART_sendByte(vImg);
		UART_sendByte(rPart1);
		UART_sendByte(rPart2);
		UART_sendByte(rPart3);
		UART_sendByte(flexParameters.movDirect);

	}
}
