/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Mohamed Waleed
 */

#include "STD_Types.h"
#include "utilss.h"
#include "DIO.h"
#include "Timer0.h"


int main (void)
{

	Timer0_voidInit();
	DIO_voidSetPinDirection(DIO_u8PinA0,DIO_u8PinOp);
		while(1)
		{

		}


	return -1;
}
