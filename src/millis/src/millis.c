/*
 *	millis.c
 *	https://github.com/oceanrescue/nRF24LE1_SDK
 *
 * 	Date:		22/12/14
 * 	Author: 	OceanRescue
 * 	Email:		ocean[ dot ]rescue[ at ]yahoo[ dot ]com
 *	Copyright (c) 2014 OceanRescue. All rights reserved.
 *
 *	The author provides no guarantees, warantees, or promises, implied or
 *  otherwise.  By using this software you agree to indemnify the author
 *  of any damages incurred by using it.
 */



#include "millis.h"
#include <stdio.h>
#include "reg24le1.h"


unsigned long ml=0;
unsigned long ms=0;

uint8_t mcs=0;
uint8_t overflow=0;

#define TLSTART 33L //256-16000000/1000/12/6 // При 16мгц ровно 33.77(7)


void isr_t1() __interrupt 3 __critical
{
	if (mcs>=5) {
		
		ml++;
		mcs=0;
		if (ml>0xFFFFFFFE) {
			overflow++;
			ml=0;
		}
		if (ml % 1000) ms++;
	}
	mcs++;
}


void millis_begin(void)
{
	overflow = 0;
	mcs = 0;
	ml = 0;
	ms=0;

	IEN0 |= (1<<7); //global INT enable

	TMOD = (TMOD & ~0xF0) | (1<<5); //10 – Mode 2: 8-bit auto-reload timer
	
	//set timer value
	TH1 = (uint8_t)(TLSTART>>8);
	TL1 = (uint8_t)TLSTART;
	
	IEN0 |= (1<<3); // Timer1 INT enable

	TCON |= (1<<6); //timer1 start
}

int millis_overflow (void)
{
	return overflow;
}
void millis_stop(void)
{
	TCON &= ~(1<<6);
	ml = 0;
	ms = 0;
}

unsigned long millis(void)
{
	unsigned long m;
	IEN0 &= ~(1<<3);
	m = ml;
	IEN0 |= (1<<3);
	return m;
}
unsigned long micros(void)
{
	unsigned long m;
	IEN0 &= ~(1<<3);
	m = ml;
	IEN0 |= (1<<3);
	return m;
}

