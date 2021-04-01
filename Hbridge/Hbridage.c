/*
 * transistor.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "utils.h"
#include <avr/delay.h>
#define F_CPU 8000000


void TRANS_vidBlank(void)
{
	DIO_vidWritePinValue(a,pin0,high);
	_delay_ms(200);
	DIO_vidWritePinValue(a,pin0,low);
	_delay_ms(200);
}

