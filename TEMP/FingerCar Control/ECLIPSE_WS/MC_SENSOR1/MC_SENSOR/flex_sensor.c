/******************************************************************************
 *
 * Module: Flex sensor
 *
 * File Name: flex_sensor.c
 *
 * Description: source file for Flex sensor
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#include "adc.h"
#include "common_macros.h"
#include "flex_sensor.h"
#include <util/delay.h>
#include <avr/io.h>
void flex_sensor_start(uint8 pin_no,flex_parameters  * config_Ptr,uint16 constResistance)
{
	float32 flexADC = ADC_readChannel(pin_no);
	float32 flexV =(flexADC/(1023/5));
	uint16 flexR = constResistance / (5 /flexV - 1.0);
	//(5*constResistance/0.1)-constResistance;
	// constResistance * (5 /flexV - 1.0);
	config_Ptr->out_voltage=flexV;
	config_Ptr->res=flexR;
}
