/*
 * SEG_HAL.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */

#include "reg.h"
#include "std.h"
#include "utilites.h"
#include "dio.h"
#include "avr/delay.h"
#define F_CPU 8000000


void count (void)

{  	dio_vidSetPortDir(0,1); // SEG 1 DDRA = 0xff;
    dio_vidSetPortDir(3,1); // SEG2  DDRD = 0xff;
	 u8 seg[11]={0b00000011,0b10011111,0b00100101,0b00001101,0b10011001,0b01001001,0b01000001,0b00011111,0b00000001,0b00001001};
     u8 i,j;
	for(i=0;i<10;i++)
	       {
	    	   PORTA=seg[i];

	    	   for(j=0;j<10;j++)
	    	   {
	    		   PORTB=seg[j];
	    		   _delay_ms(1000);

	    		   if(i==1 && j==2) //write count you want to stop at
	    		   {
	    			  i=9;
	    		      break;
	    		   }
	    	   }


	       }
}
