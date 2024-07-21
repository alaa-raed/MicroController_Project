 /******************************************************************************
 *
 * Module: Flex sensor
 *
 * File Name: flex_sensor.h
 *
 * Description: header file for Flex sensor
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/

#ifndef FLEX_SENSOR_H_
#define FLEX_SENSOR_H_
#include"std_types.h"
typedef enum
{
	FORWARD,BACKWARD
}movement_direction;

typedef struct
{
	uint16 res;
	float32  out_voltage;
	movement_direction movDirect;

}flex_parameters;

void flex_sensor_start(uint8 pin_no,flex_parameters  * config_Ptr,float64 constResistance);
#endif /* FLEX_SENSOR_H_ */
