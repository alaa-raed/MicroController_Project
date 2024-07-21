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
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "lcd.h"
#include "L293B.h"
void MoveMotorForward(void);
void MoveMotorBackward(void);
void StopMotor(void);

int main(void)
{
    DDRC = 0XFF;
    DDRD = 0XF0;
	//DDRD &= ~(1<<0);
	DDRB &= ~(1<<0);
	int count=0;
	LCD_init();
	UART_ConfigType UART_Config = {CHARACTER_SIZE_8,Even,UART_STOP_1BIT_SELECT,9600};
	UART_init(&UART_Config);
	uint8 vREAL,vImg,direction;
    while (1) 
    {      vREAL=UART_recieveByte();
		   vImg=UART_recieveByte();
		   direction= UART_recieveByte();
			LCD_displayString("V= ");
			 LCD_intgerToString(vREAL);
			   LCD_displayChar('.');
			   LCD_intgerToString(vImg);
			  // LCD_displayStringRowColumn(1,7,"RES");
			   //LCD_intgerToString(resAll);
			   if(direction == 0)
			   {
				   MoveMotorForward();
				   _delay_ms(1000);
				   LCD_displayStringRowColumn(1,0," Forward ");
			   }
			   else if (direction == 1)
			   {
				   MoveMotorBackward();
				   _delay_ms(1000);
				   LCD_displayStringRowColumn(1,0," Backward ");
			   }
		  
		   }
		   
}
// Rotates Motor in Anticlockwise (forward)
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

