#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "utils.h"
#include <avr/delay.h>
#define F_CPU 8000000

void main(void)
{

	DIO_vidSetPinDir(a,pin1,output);
	DIO_vidSetPinDir(a,pin2,output);
	DIO_vidSetPinDir(a,pin0,output);
	DIO_vidSetPinDir(a,pin3,output);



while(1)
{

	DIO_vidWritePinValue(a,pin0,high); //cw
	DIO_vidWritePinValue(a,pin3,low);
	DIO_vidWritePinValue(a,pin2,high);
	DIO_vidWritePinValue(a,pin1,low);

_delay_ms(2000);

	    DIO_vidWritePinValue(a,pin0,low); /// off
		DIO_vidWritePinValue(a,pin3,low);
		DIO_vidWritePinValue(a,pin1,low);
		DIO_vidWritePinValue(a,pin2,low);

		_delay_ms(2000);


	DIO_vidWritePinValue(a,pin1,high);  //ccw
	DIO_vidWritePinValue(a,pin2,low);
	DIO_vidWritePinValue(a,pin0,low);
	DIO_vidWritePinValue(a,pin3,high);

	_delay_ms(2000);






}

}
