/*
 *	eeprom.c
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
#include "eeprom.h"
#include "memory.h"
#include "reg24le1.h"


#define PAGE_0_XDATA 	0xFA00
#define PAGE_1_XDATA 	0xFB00
#define EEPROM_END		0xFBFF

void eeprom_byte_write(uint8_t adr, uint8_t dat)
{
	__xdata uint8_t buffer[512];

	if (PAGE_0_XDATA + adr > EEPROM_END) {
		return;
	}
	
	memory_flash_write_bytes_smart(PAGE_0_XDATA+adr, 1, &dat, buffer);
}

void eeprom_byte_read(uint8_t adr, uint8_t *dst)
{
	if (dst == NULL) {
		return;
	}
	if (PAGE_0_XDATA+adr > EEPROM_END) {
		return;
	}
	memory_flash_read_byte(PAGE_0_XDATA+adr, dst);
}

void eeprom_bytes_write(uint8_t adr, uint8_t *src, uint8_t n)
{
	__xdata uint8_t buffer[512];
	if (PAGE_0_XDATA + adr > EEPROM_END) {
		return;
	}
	memory_flash_write_bytes_smart(PAGE_0_XDATA+adr, n, src, buffer);
}

void eeprom_bytes_read(uint8_t adr, uint8_t *dst, uint8_t n)
{
	if (dst == NULL) {
		return;
	}
	if (PAGE_0_XDATA+adr+n > EEPROM_END) {
		return;
	}
	memory_flash_read_bytes(PAGE_0_XDATA+adr, n, dst);
}

