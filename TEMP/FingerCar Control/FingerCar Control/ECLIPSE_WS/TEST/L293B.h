 /******************************************************************************
 *
 * Module: L293B chip module
 *
 * File Name: L293B.h
 *
 * Description: L293B driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/
#ifndef L293B_H_
#define L293B_H_
#define L293B_PORT_ID PORTC_ID
#define L293B_CHIP_ENABLE_1 PIN0_ID
#define L293B_CHIP_ENABLE_2 PIN1_ID
#define L293B_INPUT_1_PIN_ID PIN2_ID
#define L293B_INPUT_2_PIN_ID PIN3_ID
#define L293B_INPUT_3_PIN_ID PIN4_ID
#define L293B_INPUT_4_PIN_ID PIN5_ID

void configureL293B();



#endif /* L293B_H_ */
