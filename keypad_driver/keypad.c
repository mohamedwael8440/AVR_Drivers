/*
 * keypad.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Wael
 */

#include "registers.h"
#include "utils.h"
#include "std_types.h"
#include "dio.h"
#include "keypad.h"
#include "keypad_cfg.h"


 u8 pressed_key = 99; // range out of 0 to 15

void keypad_vidInit(void)
{
	dio_vidPortDir(keypadport,0b11110000);
	dio_vidSetPortValue(keypadport,0b11111111);
}

void keypad_vidGetpressedKey (void)
	{
	     dio_vidWritePin(keypadport,r1,low);
	     dio_vidWritePin(keypadport,r2,high);
	     dio_vidWritePin(keypadport,r3,high);
	     dio_vidWritePin(keypadport,r4,high);

	     if(dio_u8ReadPinValue(keypadport,c1)==0)
	     {
	    	 pressed_key=0;
	    	// dio_vidWritePin(d,0,high);
	     }
	     else if(dio_u8ReadPinValue(keypadport,c2)==0)
	     {
	    	 pressed_key=1;
	    	// dio_vidWritePin(d,0,low);
	     }
	     else if(dio_u8ReadPinValue(keypadport,c3)==0)
	     {
	   	     pressed_key=2;
	   	 // dio_vidWritePin(d,0,high);
	     }
	     else if(dio_u8ReadPinValue(keypadport,c4)==0)
	     {
	   	     pressed_key=3;
	   	    // dio_vidWritePin(d,0,low);
	     }

	         dio_vidWritePin(keypadport,r1,high);
		     dio_vidWritePin(keypadport,r2,low);
		     dio_vidWritePin(keypadport,r3,high);
		     dio_vidWritePin(keypadport,r4,high);

		     if(dio_u8ReadPinValue(keypadport,c1)==0)
		     {
		    	 pressed_key=4;
		    	// dio_vidWritePin(d,0,high);
		     }
		     else if(dio_u8ReadPinValue(keypadport,c2)==0)
		     {
		    	 pressed_key=5;
		    	// dio_vidWritePin(d,0,low);
		     }
		     else if(dio_u8ReadPinValue(keypadport,c3)==0)
		     {
		   	     pressed_key=6;
		   	 // dio_vidWritePin(d,0,high);
		     }
		     else if(dio_u8ReadPinValue(keypadport,c4)==0)
		     {
		   	     pressed_key=7;
		   	 // dio_vidWritePin(d,0,low);
		     }

		         dio_vidWritePin(keypadport,r1,high);
			     dio_vidWritePin(keypadport,r2,high);
			     dio_vidWritePin(keypadport,r3,low);
			     dio_vidWritePin(keypadport,r4,high);

			     if(dio_u8ReadPinValue(keypadport,c1)==0)
			     {
			    	 pressed_key=8;
			    	// dio_vidWritePin(d,0,high);
			     }
			     else if(dio_u8ReadPinValue(keypadport,c2)==0)
			     {
			    	 pressed_key=9;
			    	// dio_vidWritePin(d,0,low);
			     }
			     else if(dio_u8ReadPinValue(keypadport,c3)==0)
			     {
			   	     pressed_key=10;
			   	 // dio_vidWritePin(d,0,high);
			     }
			     else if(dio_u8ReadPinValue(keypadport,c4)==0)
			     {
			   	     pressed_key=11;
			 //  	  dio_vidWritePin(d,0,low);
			     }

			         dio_vidWritePin(keypadport,r1,high);
				     dio_vidWritePin(keypadport,r2,high);
				     dio_vidWritePin(keypadport,r3,high);
				     dio_vidWritePin(keypadport,r4,low);

				     if(dio_u8ReadPinValue(keypadport,c1)==0)
				     {
				    	 pressed_key=12;
				    //	 dio_vidWritePin(d,0,high);
				     }
				     else if(dio_u8ReadPinValue(keypadport,c2)==0)
				     {
				    	 pressed_key=13;
				    //	 dio_vidWritePin(d,0,low);
				     }
				     else if(dio_u8ReadPinValue(keypadport,c3)==0)
				     {
				   	     pressed_key=14;
				   	//  dio_vidWritePin(d,0,high);
				     }
				     else if(dio_u8ReadPinValue(keypadport,c4)==0)
				     {
				   	     pressed_key=15;
				   	 // dio_vidWritePin(d,0,low);
				     }

	}
