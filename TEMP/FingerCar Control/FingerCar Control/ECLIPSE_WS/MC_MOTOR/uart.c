 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Mohamed Hassan
 *
 *******************************************************************************/

#include "uart.h"
#include "lcd.h"
#include "avr/io.h" /* To use the UART Registers */
#include "common_macros.h" /* To use the macros like SET_BIT */
#define F_CPU 16000000UL
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType *UART_Config)
{
	uint16 ubrr_value=0;
	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);
	UCSRB|=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL);


	if(UART_Config->parity==Even)
	{
		UCSRC|=(1<<UPM1);
	}
	else if(UART_Config->parity==Odd)
		UCSRC|=(1<<UPM1)|(1<<UPM0);

	if(UART_Config->stop_bit==UART_STOP_2BIT_SELECT)
	{
		UCSRC|=(1<<USBS);
	}
	else
	{

	}

	if(UART_Config->bit_data==CHARACTER_SIZE_5)
	{
		UCSRC&=~(1<<UCSZ0);
		UCSRC&=~(1<<UCSZ1);
		UCSRB&=~(1<<UCSZ2);
	}
	else if(UART_Config->bit_data==CHARACTER_SIZE_6)
	{
		UCSRC|=(1<<UCSZ0);
		UCSRC&=~(1<<UCSZ1);
		UCSRB&=~(1<<UCSZ2);
	}
	else if(UART_Config->bit_data==CHARACTER_SIZE_7)
	{
		UCSRC|=(1<<UCSZ1);
		UCSRC&=~(1<<UCSZ0);
		UCSRB&=~(1<<UCSZ2);
	}
	else if(UART_Config->bit_data==CHARACTER_SIZE_8)
	{
		UCSRC|=(1<<UCSZ0);
		UCSRC|=(1<<UCSZ1);
		UCSRB&=~(1<<UCSZ2);
	}
	else if(UART_Config->bit_data==CHARACTER_SIZE_9)
	{
		UCSRC|=(1<<UCSZ0);
		UCSRC|=(1<<UCSZ1);
		UCSRB|=(1<<UCSZ2);
	}
	/* Calculate the UBRR register value */
	ubrr_value = (uint16)(((F_CPU / ((UART_Config->baud_rate) * 8UL))) - 1);
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;

}


/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = data;

	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transmission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
    return UDR;		
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}		
	*******************************************************************/
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
