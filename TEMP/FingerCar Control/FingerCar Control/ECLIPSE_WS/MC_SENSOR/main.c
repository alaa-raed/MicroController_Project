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
#include"L293B.h"
#define CONST_RESISTANCE 14000
void MoveMotorForward(void);
void MoveMotorBackward(void);
void StopMotor(void);
int main()
{
	LCD_init();
	//DDRD &= ~(1<<0);
	DDRB &= ~(1<<0);
	uint16 vReal,vImg,resAll;
	configureL293B();
	ADC_ConfigType currentConfig;
	ADC_init(&currentConfig);
	currentConfig.prescaler=PRESCALER_128;
	currentConfig.reference_mode=AVCC_MODE;
	flex_parameters flexParameters;
	while(1)
	{

		flex_sensor_start(PIN0_ID,&flexParameters,CONST_RESISTANCE);
		vReal=flexParameters.out_voltage;
		vImg=(int)((flexParameters.out_voltage*100))%100;
		/*Dividing Resistance*/
		resAll=flexParameters.res;
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
		if(flexParameters.out_voltage<3)
		{
			MoveMotorBackward();
			LCD_displayStringRowColumn(1,10," B    ");

		}
		else
		{
			MoveMotorForward();
			LCD_displayStringRowColumn(1,10," F    ");
		}
		if(!(PINB&(1<<0)))
		{
			StopMotor();
			LCD_displayStringRowColumn(1,10," Stop ");
			while (!(PINB&(1<<0)));
		}

	}


}
void MoveMotorForward(void){
	PORTC = 0x0A;
	PORTD = 0xA0;
}

// Rotates Motor in clockwise (backward)
void MoveMotorBackward(void){
	PORTC = 0x05;
	PORTD = 0x50;
}

//stop motor
void StopMotor(void)
{
	PORTC = 0x00;
	PORTD = 0x00;
}
