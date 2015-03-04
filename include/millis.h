/*
 *	millis.h
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


#ifndef __millis_h_
#define __millis_h_

#include <stdio.h>

int millis_overflow(void);
void millis_begin(void);
void millis_stop(void);
unsigned long millis(void);
unsigned long micros(void);
#endif /* defined(__millis_h_) */
