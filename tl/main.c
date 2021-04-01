/*
 * main.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */
#include "std.h"


void main (void)
{
	// switch on or of for the system
	 dio_vidSetPinDir(2,0,0);    // make PIN 0 of PORTA input
	dio_vidWritePinDir(2,0,1);  // enable the pull up of PIN 0  on PORTA
while(1)
{

    u8 flag=1;
	while( flag == 1)

{       u8 status = dio_u8ReadPinValue(2,0);
		if(status==0)
		{
			flag=0;
		}

		else
		{
		   color(0);                    // turn on red
		   count();
		   dio_vidWritePort(1,0);        // turn of
		   color(1);                   // turn on yellow PORTB=0b00000010;
		   count();
		   dio_vidWritePort(1,0);      // turn of
		   color(2);                    // turn on green PORTB=0b00000100;
		   count();
		   dio_vidWritePort(1,0);

		}
}
	dio_vidWritePort(1,0);        // turn of

}
}

