/*
 *	eeprom.h
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

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _eeprom_h_
#define _eeprom_h_

#include <stdint.h>
#include <stdbool.h>

/** Function to write a byte to the EEPROM
 *  @param adr 8 bit address in EEPROM
 *  @param dat byte to write
 */
extern void eeprom_byte_write(uint8_t adr, uint8_t dat);

/** Function to write n bytes to the EEPROM
 *  @param adr 8 bit address in EEPROM
 *  @param *src pointer to bytes to write
 *  @param n number of bytes to write
 */
extern void eeprom_bytes_write(uint8_t adr, uint8_t *src, uint8_t n);

/** Function to read a byte from the EEPROM
 *  @param adr 8 bit address in EEPROM
 *  @return the byte read
 */
extern void eeprom_byte_read(uint8_t adr, uint8_t *dst);

/** Function to read n bytes from the EEPROM
 *  @param adr 8 bit address in EEPROM
 *  @param *dst pointer to bytes to write
 *  @param n number of bytes to read
 */
extern void eeprom_bytes_read(uint8_t adr, uint8_t *dst, uint8_t n);
#endif
