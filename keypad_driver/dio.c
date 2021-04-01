/*
 * dio.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#include "std_types.h"
#include "utils.h"
#include "registers.h"
#include "dio.h"

void dio_vidSetPinDir(u8 port,u8 pin,u8 dir)
{
	switch(port)
	{
	case a:
		if(dir==input)
			clr_bit(DDRA,pin);
		if(dir==output)
					set_bit(DDRA,pin);
		break;

	case b:
		if(dir==input)
			clr_bit(DDRB,pin);
		if(dir==output)
					set_bit(DDRB,pin);
		break;
	case c:
			if(dir==input)
				clr_bit(DDRC,pin);
			if(dir==output)
						set_bit(DDRC,pin);
			break;
	case d:
			if(dir==input)
				clr_bit(DDRD,pin);
			if(dir==output)
						set_bit(DDRD,pin);
			break;


	}
}

void dio_vidWritePin(u8 port,u8 pin,u8 value)
{
	switch(port)
	{
	case a:
		if(value==low)
			clr_bit(PORTA,pin);
		if(value==high)
					set_bit(PORTA,pin);
		break;

	case b:
		if(value==low)
			clr_bit(PORTB,pin);
		if(value==high)
					set_bit(PORTB,pin);
		break;
	case c:
			if(value==low)
				clr_bit(PORTC,pin);
			if(value==high)
						set_bit(PORTC,pin);
			break;
	case d:
			if(value==low)
				clr_bit(PORTD,pin);
			if(value==high)
						set_bit(PORTD,pin);
			break;


	}
}

u8  dio_u8ReadPinValue(u8 port,u8 pin)
{
	switch(port)
	{
	case a:
		   return get_bit(PINA,pin);
	    break;
	case b:
			return get_bit(PINB,pin);
		break;
	case c:
			return get_bit(PINC,pin);
		break;
	case d:
			return get_bit(PIND,pin);
		break;

	default :
	        return port;
	    break;

	}
}

void dio_vidPortDir(u8 port,u8 dir)
{
	switch(port)
	{
	case a:
		DDRA=dir ;
		break ;

	case b:
			DDRB=dir;
		break;
	case c:

			DDRC=dir;
			break ;
	case d:

			DDRD=dir;
			break ;

	}
}

void dio_vidSetPortValue(u8 port,u8 value)
{
	switch(port)
	{
	case a:

		PORTA=value;
		break;

	case b:
			PORTB=value;
			break;

	case c:

			PORTC=value;
			break;
	case d:

			PORTD=value;
			break;

	}
}

