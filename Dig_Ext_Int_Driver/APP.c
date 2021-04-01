/*
 * main.c
 *
 *  Created on: Sep 16, 2017
 *      Author: Mohamed Waleed
 */


#include "Types.h"
#include "utilss.h"
#include "DIO.h"
#include "DigExtInt.h"


int main (void)
{

	DEI_voidInit();

	DIO_voidSetDirection(DIO_u8PinA0,DIO_u8PinOp);

	DIO_voidWritePIN(DIO_u8PinD2,DIO_u8HIGH);
	DIO_voidWritePIN(DIO_u8PinD3,DIO_u8HIGH);


	while (1)
	{

	}
	return 0;
}
