#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "ADC.h"
#include "lcd.h"
#include <avr/delay.h>

u16 digital_read;
u16 digital_read2;

void main(void)
{
 LCD_Init();
  ADC_init();

  while(1)
  {
	  digital_read=ADC_u16Read(0);
	  digital_read2=ADC_u16Read(1);

//	  DIO_vidWritePortValue(c,digital_read);
	  u16 Ang=((digital_read*500)/1023);
	  u16 Ang2=((digital_read2)/4);
	  Gotoxy(1,1);
	  LCD_String("temperature  ");
	  LCD_vidWriteInteger(Ang);
	  Gotoxy(2,1);
	  LCD_String("light '");
	  LCD_vidWriteInteger(Ang2);
	  _delay_ms(1000);


  }


}

