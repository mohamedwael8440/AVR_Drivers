
#include "registers.h"
#include "utils.h"
#include "standardtypes.h"
#include "DIO.h"
#include "lcd.h"
#include "Keypad.h"
#include "KeypadConfig.h"
#include <avr/delay.h>



extern u8 LOC_u8Retrun;


void main(void)
{  lcd_vidInit();
	 Keypad_vidInit();
	 DIO_vidSetPinDir(b,0,output);
while(1)
	 {
	KPD_u8GetPressedKey();

	 }

}
