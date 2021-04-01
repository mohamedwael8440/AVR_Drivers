/*
 * LED.c
 *
 *  Created on: Sep 3, 2019
 *      Author: Wael
 */

#define F_CPU 8000000
#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "LED.h"
#include <util/delay.h>

void LED_vidInit(u8 port , u8 pin,u8 dir ) /// Select port and pin
{
	DIO_vidSetPinDir(port,pin,dir);
}


void LED_vidONOF(u8 port,u8 pin ,u8 status )

{ switch(status)
{
    case on :
	DIO_vidWritePinValue(port,pin,high);
    break;
    case of :
	DIO_vidWritePinValue(port,pin,low);
    break;
}
}

void LED_vidBlink(u8 port,u8 pin , u8 delay)

{
	DIO_vidWritePinValue(port,pin,high);
	_delay_ms(delay);
	DIO_vidWritePinValue(port,pin,low);
	_delay_ms(delay);

}

void LED_vidFeature(u8 port , u8 pin ,u8 feature , u8 delay)
{
	switch (feature)
	{
	case blink :
		DIO_vidWritePinValue(port,pin,high);
		_delay_ms(delay);
		DIO_vidWritePinValue(port,pin,low);
		_delay_ms(delay);
		break;
	case on :
		DIO_vidWritePinValue(port,pin,high);
        break;
	case of :
		DIO_vidWritePinValue(port,pin,low);
	    break;

	}
}

