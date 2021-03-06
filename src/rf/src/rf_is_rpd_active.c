/////////////////////////////////////////////////////////////////////////////
//
// File: rf_is_rpd_active.c
//
// Copyright S. Brennen Ball, 2012
//
// The author provides no guarantees, warantees, or promises, implied or
//  otherwise.  By using this software you agree to indemnify the author
//  of any damages incurred by using it.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
/////////////////////////////////////////////////////////////////////////////

#include "rf.h"
#include "rf_src.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// bool rf_is_rpd_active()
//
// Description:
//  Returns whether or not the RPD bit is set
//
// Parameters:
//  None
//
// Return value:
//  bool - true if RPD bit is set, false otherwise
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool rf_is_rpd_active()
{
	uint8_t rpd;

	rf_read_register(RF_RPD, &rpd, 1);

	return (rpd & RF_RPD_RPD) ? true : false;
}
