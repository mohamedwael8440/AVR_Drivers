
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "stepper.h"
#include "lcd.h"
#define F_CPU 8000000UL
#include "avr/delay.h"


void main(void)
{
  STEPPER_vidInit();
  LCD_Init();
  Gotoxy(1,2);
   LCD_String(" 360 degree ");
  while(1)
	{
	  Gotoxy(1,2);
	   LCD_String(" 360 degree ");
    for(u16 i=0 ; i<512 ;i++)
   {
    	STEPPER_vidFULLstepCW();

    }

	}

}
