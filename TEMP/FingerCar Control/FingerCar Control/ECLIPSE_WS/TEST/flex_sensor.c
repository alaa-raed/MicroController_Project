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
void flex_sensor_start(uint8 pin_no,flex_parameters  * config_Ptr,float64 constResistance)
{
	float32 flexADC = ADC_readChannel(pin_no);
	float32 flexV =(flexADC/(1023/5));
	float32 flexR = constResistance / (5 /flexV - 1.0);
	//R_DIV * (VCC / Vflex - 1.0);
			//constResistance / (5 /flexV - 1.0);
			//(5*constResistance/0.1)-constResistance;
	// constResistance * (5 /flexV - 1.0);
//	if(flexR<30950)
//	{
//		config_Ptr->movDirect=BACKWARD;
//
//	}
//	else
//	{
//		config_Ptr->movDirect=FORWARD;
//	}
	config_Ptr->movDirect=flexADC;
	config_Ptr->out_voltage=flexV;
	config_Ptr->res=flexR;
}
