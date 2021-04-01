/*
 * dio.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */


#include "reg.h"
#include "std.h"
#include "utilites.h"
#include "dio.h"


void dio_vidSetPinDir(u8 port,u8 pin,u8 dir)
{
	switch(port)
	{
	case 0:
		if(dir==0)
			clr_bit(DDRA,pin);
		if(dir==1)
					set_bit(DDRA,pin);
		break;

	case 1:
		if(dir==0)
			clr_bit(DDRB,pin);
		if(dir==1)
					set_bit(DDRB,pin);
		break;
	case 2:
			if(dir==0)
				clr_bit(DDRC,pin);
			if(dir==1)
						set_bit(DDRC,pin);
			break;
	case 3:
			if(dir==0)
				clr_bit(DDRD,pin);
			if(dir==1)
						set_bit(DDRD,pin);
			break;


	}
}

void dio_vidWritePinDir(u8 port,u8 pin,u8 value)
{
	switch(port)
	{
	case 0:
		if(value==0)
			clr_bit(PORTA,pin);
		if(value==1)
					set_bit(PORTA,pin);
		break;

	case 1:
		if(value==0)
			clr_bit(PORTB,pin);
		if(value==1)
					set_bit(PORTB,pin);
		break;
	case 2:
			if(value==0)
				clr_bit(PORTC,pin);
			if(value==1)
						set_bit(PORTC,pin);
			break;
	case 3:
			if(value==0)
				clr_bit(PORTD,pin);
			if(value==1)
						set_bit(PORTD,pin);
			break;


	}
}

u8  dio_u8ReadPinValue(u8 port,u8 pin)
{
	switch(port)
	{
	case 0:
		return get_bit(PINA,pin);
	break;
	case 1:
			return get_bit(PINB,pin);
		break;
	case 2:
			return get_bit(PINC,pin);
		break;
	case 3:
			return get_bit(PIND,pin);
		break;

	default :
	        return 0;

	}
}


void dio_vidSetPortDir(u8 port,u8 dir)
{
	switch(port)
	{
	case 0:
		if(dir==0)
			clr_port(DDRA);
		if(dir==1)
					set_port(DDRA);
		break;

	case 1:
		if(dir==0)
			clr_port(DDRB);
		if(dir==1)
					set_port(DDRB);
		break;
	case 2:
			if(dir==0)
				clr_port(DDRC);
			if(dir==1)
						set_port(DDRC);
			break;
	case 3:
			if(dir==0)
				clr_port(DDRD);
			if(dir==1)
						set_port(DDRD);
			break;


	}
}

void dio_vidWritePort(u8 port,u8 value)
{
	switch(port)
	{
	case 0:
		if(value==0)
			clr_port(PORTA);
		if(value==1)
					set_port(PORTA);
		break;

	case 1:
		if(value==0)
			clr_port(PORTB);
		if(value==1)
					set_port(PORTB);
		break;
	case 2:
			if(value==0)
				clr_port(PORTC);
			if(value==1)
						set_port(PORTC);
			break;
	case 3:
			if(value==0)
				clr_port(PORTD);
			if(value==1)
						set_port(PORTD);
			break;


	}
}

