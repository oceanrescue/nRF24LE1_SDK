/*
 *	serial.c
 *	https://github.com/oceanrescue/nRF24LE1_SDK
 *
 * 	Date:		18/12/14
 * 	Author: 	OceanRescue
 * 	Email:		ocean[ dot ]rescue[ at ]yahoo[ dot ]com
 *	Copyright (c) 2014 OceanRescue. All rights reserved.
 *
 *	The author provides no guarantees, warantees, or promises, implied or
 *  otherwise.  By using this software you agree to indemnify the author
 *  of any damages incurred by using it.
 */


#include <stdio.h>
#include "reg24le1.h"
#include "serial.h"


#pragma mark - Declaration
void nrf_uart_putchar(uint8_t ch);
bool nrf_uart_tx_complete();
uint8_t nrf_uart_getchar(void);


// Cusomization of low level stdio function. Used by for example printf().
//char putchar(char c)
void putchar(char c)
{
	nrf_uart_putchar((uint8_t)c);
}

// Cusomization of low level stdio function. Used by for example gets().
char getchar(void)
{
	return (char)nrf_uart_getchar();
}

char serial_getchar(void) {
	return (char)nrf_uart_getchar();
}
char serial_putchar(char c) {
	nrf_uart_putchar((uint8_t)c);
}

// Repeated putchar to print a string
void serial_putstring(char *s)
{
	while(*s != 0)
		putchar(*s++);
}

void serial_stop(void)
{
	IEN0 &= ~(1 << 4);
	S0CON &= ~(1<<4);
}
void serial_begin(void)
{
	uint16_t temp = 972; //0x03CC; // boud rate 9600

	P0DIR &= ~(1<<3); // P0.3 - output = 0
	P0DIR |= (1<<4); // P0.4 - input = 1

	IEN0 &= ~(1 << 4);

	S0CON |= (1<<4);

//	1 1: Mode 3 – 9 bit UART.
	S0CON |= (1<<6);
	S0CON |= (1<<7);
	
	
	PCON |= 0x80;                 // SMOD = 1
	ADCON |= 0x80;                // Select internal baud rate generator, not timer 1
	
	S0RELL = (uint8_t)temp;
	S0RELH = (uint8_t)(temp >> 8);
	
	S0CON |= (1<<1);
	
	// Enable UART0 interrupt
	IEN0 |= (1<<4);

	// Enable global interrupts
	IEN0 |= (1<<7);
}

void nrf_uart_putchar(uint8_t ch)
{
	while (!S0CON_SB_TI0) ;
	IEN0 &= ~(1<<4);
	S0CON_SB_TI0 = 0;
	S0BUF = ch;
	IEN0 |= (1<<4);
}


uint8_t uart_chars_available(void)
{
	return S0CON_SB_RI0;
}

bool nrf_uart_tx_complete()
{
	if(S0CON_SB_TI0 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

uint8_t nrf_uart_getchar(void)
{
	uint8_t ch;
	
	// Wait until a character is available:
	while(S0CON_SB_RI0 == 0)
	{}
	IEN0 &= ~(1<<4);
	ch = S0BUF;
	S0CON_SB_RI0 = 0;
	IEN0 |= (1<<4);
	return ch;
}
