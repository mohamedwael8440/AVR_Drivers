/*
 * clk.c
 *
 *  Created on: Sep 23, 2019
 *      Author: Wael
 */
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "timer.h"
#include "lcd.h"
#include "SEG_HAL.h"

extern u32 counter;
extern u32 overflow ;
extern u32 min;
extern u32 hr;

void CLK_vidInit(void)
{
	    timer_vidInit();
	    LCD_Gotoxy(1,1);
	    LCD_String("hr");
	    LCD_Gotoxy(1,6);
	    LCD_String("min");
	    LCD_Gotoxy(1,11);
	    LCD_String("sec") ;

	    LCD_Gotoxy(2,1);
	    LCD_String("   :    :   ");
	    LCD_Gotoxy(2,11);
	    LCD_vidWriteInteger(overflow);
	    LCD_Gotoxy(2,6);
	   	LCD_vidWriteInteger(min);
	   	LCD_Gotoxy(2,1);
	   	LCD_vidWriteInteger(hr);
}

void CLK_vidStart(void)
{
	//		 if(counter==3906 && overflow<10)
	//			  {  SEG_vidDisplayNO(overflow);
    //	             overflow++ ;
	//
	//				counter=0;
	//			  }
	//		 if(overflow==10)
	//		 {
	//			 overflow=0;
	//		 }
			 if(counter==3906 && overflow<60)
			   { overflow++ ;
				 LCD_Gotoxy(2,11);
				 LCD_vidWriteInteger(overflow);


			   counter=0;
		      }
			 if(overflow==60 && min<60)
			 {   LCD_Gotoxy(2,11);
			     LCD_String("  ");
				 overflow=0;
				 min++;
				 LCD_Gotoxy(2,6);
				 LCD_vidWriteInteger(min);
			 }
			 if(min==60 && hr<12)
				 {   LCD_Gotoxy(2,6);
				     LCD_String("  ");
					 min=0;
					 hr++;
					 LCD_Gotoxy(2,1);
					 LCD_vidWriteInteger(hr);
				 }
	         if(hr==12 && min==59 && overflow==59)
	         {
	        	 hr=0;
	        	 LCD_Gotoxy(2,1);
	        	 LCD_String("  ");

	         }


}
