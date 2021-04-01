/*
 * SEG_HAL.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */

#define F_CPU 8000000
#include "avr/delay.h"
#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "SEG_CFG.h"

void SEG_vidInit(void)
{
	DIO_vidSetPortDir(port1,0xff); // SEG 1 DDRA = 0xff;
  	DIO_vidSetPortDir(port2,0xff); // SEG2  DDRD = 0xff;
}


void SEG_vidDisplayNO(u8 number1_seg1)
{
 u8 numbers[11]={0b00000011,0b10011111,0b00100101,0b00001101,0b10011001,0b01001001,0b01000001,0b00011111,0b00000001,0b00001001};


 DIO_vidWritePortValue(port1,numbers[number1_seg1]);


}

void SEG_vidCount (u8 start1,u8 start2 ,u8 seg1_stop,u8 seg2_stop)
{
	 u8 numbers[11]={0b00000011,0b10011111,0b00100101,0b00001101,0b10011001,0b01001001,0b01000001,0b00011111,0b00000001,0b00001001};
     u8 i,j;
	for(i=start1;i<10;i++)
	       {
	    	   DIO_vidWritePortValue(port1,numbers[i]);

	    	   for(j=start2;j<10;j++)
	    	   {
		    	   DIO_vidWritePortValue (port2,numbers[j]);
	    		   _delay_ms(1000);

	    		   if(i==seg1_stop && j==seg2_stop) //write count you want to stop at
	    		   {
	    			  i=9; //get out of loop 1
	    		      break; // get out of loop 2
	    		   }
	    		   start1=0;
	    		   start2=0;
	    	   }


	       }
}
