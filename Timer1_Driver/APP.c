/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Mohamed Waleed
 */

#include "STD_Types.h"
#include "utilss.h"
#include "DIO.h"
#include "Timer1.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

//FAST PWM for servo motor

int main (void)
{

	TIMER1_voidInit();
	DIO_voidSetPinDirection(DIO_u8PinD5,DIO_u8PinOp); //OC1A
		while(1)
		{
			OCR1AL=81;
		//	_delay_ms(1000);
//			OCR1AL=60	;
//			_delay_ms(1000);
		}


	return -1;
}
