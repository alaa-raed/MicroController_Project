 /******************************************************************************
 *
 * Module: L293B chip module
 *
 * File Name: L293B.c
 *
 * Description: L293B driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#include"L293B.h"
#include"gpio.h"
#include "std_types.h"

void configureL293B()
{
	GPIO_setupPortDirection(L293B_PORT_ID,PORT_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_CHIP_ENABLE_1,PIN_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_CHIP_ENABLE_2,PIN_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_INPUT_1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_INPUT_2_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_INPUT_3_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(L293B_PORT_ID,L293B_INPUT_4_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(L293B_PORT_ID,L293B_CHIP_ENABLE_1,LOGIC_HIGH);
	GPIO_writePin(L293B_PORT_ID,L293B_CHIP_ENABLE_2,LOGIC_HIGH);
	GPIO_writePin(L293B_PORT_ID,L293B_INPUT_1_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(L293B_PORT_ID,L293B_INPUT_2_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(L293B_PORT_ID,L293B_INPUT_3_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(L293B_PORT_ID,L293B_INPUT_4_PIN_ID,LOGIC_HIGH);

}
