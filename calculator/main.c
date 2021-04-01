
#include "registers.h"
#include "utils.h"
#include "standardtypes.h"
#include "DIO.h"
#include "lcd.h"
#include "Keypad.h"
#include "KeypadConfig.h"
#include "calculator.h"
#include <avr/delay.h>



extern u8 Pressedkey;
extern u8 count;
u8 nums[4];
u8 result;

void main(void)
{  lcd_vidInit();
	 Keypad_vidInit();
		DIO_vidSetPinDir(b,0,output);
//while(1)
//{
		caal();
//}

}
