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
#define L293B1_PORT_ID PORTC_ID
#define L293B1_INPUT_1_PIN_ID PIN0_ID
#define L293B1_INPUT_2_PIN_ID PIN1_ID
#define L293B1_INPUT_3_PIN_ID PIN2_ID
#define L293B1_INPUT_4_PIN_ID PIN3_ID

#define L293B2_PORT_ID PORTD_ID
#define L293B2_INPUT_1_PIN_ID PIN4_ID
#define L293B2_INPUT_2_PIN_ID PIN5_ID
#define L293B2_INPUT_3_PIN_ID PIN6_ID
#define L293B2_INPUT_4_PIN_ID PIN7_ID

void configureL293B();



#endif /* L293B_H_ */
