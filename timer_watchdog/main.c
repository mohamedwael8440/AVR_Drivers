
#include "standardtypes.h"
#define F_CPU 8000000
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "avr/delay.h"

#include "watchdog.h"

void main(void)
{
  WDT_vidinit();
  DIO_vidSetPinDir(a,pin0,output);
  _delay_ms(400);
DIO_vidWritePinValue(a,pin0,high);
  while(1)
	{
//WDT_vidRefresh();

	}

}
