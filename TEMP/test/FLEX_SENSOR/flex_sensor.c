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
void flex_sensor_start(uint8 pin_no,flex_parameters  * config_Ptr)
{
	uint16 outVolt,res_value;
	uint16 adcOut=ADC_readChannel(pin_no);
	outVolt = (adcOut*5)/1023;
	res_value =51000* (5 / outVolt - 1.0);
	config_Ptr->movDirect=FORWARD;
	config_Ptr->out_voltage=outVolt;
	config_Ptr->res=res_value;
}
