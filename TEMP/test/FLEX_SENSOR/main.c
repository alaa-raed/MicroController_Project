/******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include"lcd.h"
#include "flex_sensor.h"
#include "adc.h"
#include "gpio.h"
#include <util/delay.h>
int main()
{
	LCD_init();
	ADC_ConfigType currentConfig;
	currentConfig.prescaler=PRESCALER_128;
	currentConfig.reference_mode=AVCC_MODE;
	ADC_init(&currentConfig);
	flex_parameters flexDirect;

	while(1)
	{
		flex_sensor_start(PIN0_ID,&flexDirect);
		//		LCD_displayString("Direction : ");
		//		LCD_intgerToString(flexDirect.movDirect);
		//		LCD_moveCursor(1,0);
		LCD_displayStringRowColumn(0,0," volt");
		LCD_displayChar(' ');
		LCD_intgerToString(flexDirect.out_voltage);
		//LCD_moveCursor(2,0);
		LCD_displayStringRowColumn(1,0," Res");
		LCD_displayChar(' ');
		LCD_intgerToString(flexDirect.res);


	}
}
