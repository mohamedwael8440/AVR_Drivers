/*
 * LED.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */


#include "reg.h"
#include "std.h"
#include "utilites.h"
#include "dio.h"

void color (u8 color)
{
	dio_vidSetPortDir(1,1);  // LIGHT TRAFFIC DDRB = 0xff;

	switch(color)
	{
	  case(0) :
		dio_vidWritePinDir(1,0,1);  // turn on red PORTB=0b00000001;
	    break;
	  case(1) :
	    dio_vidWritePinDir(1,1,1);  // turn on yellow PORTB=0b00000010;
	    break;
	  case(2) :
		dio_vidWritePinDir(1,2,1);  // turn on green PORTB=0b00000100;
	   break;
	}
}
