/*
 * switch.c
 *
 *  Created on: Sep 3, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"


void SWITCH_vidInit(u8 port ,u8 pin )

{
	DIO_vidSetPinDir(port,pin,input);
	DIO_vidWritePinValue(port,pin,high); //active pullup
}

u8 SWITCH_u8Readswitch(u8 port ,u8 pin)
{
	return DIO_u8ReadPinValue(port,pin);
}
