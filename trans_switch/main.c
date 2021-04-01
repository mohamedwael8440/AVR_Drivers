#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "utils.h"
#include <avr/delay.h>
#define F_CPU 8000000

void main(void)
{
	DIO_vidSetPinDir(a,pin0,output);
while(1)
{
	DIO_vidWritePinValue(a,pin0,high);
	// _delay_ms(2000);
//	DIO_vidWritePinValue(a,pin0,low);
//	_delay_ms(2000);
}

}
