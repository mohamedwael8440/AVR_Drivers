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
	DIO_vidSetPinDir(a,pin1,output);
	DIO_vidSetPinDir(a,pin2,output);
	DIO_vidSetPinDir(a,pin3,output);

	DIO_vidSetPinDir(d,pin0,input);
	DIO_vidSetPinDir(d,pin1,input);
	DIO_vidWritePinValue(d,pin0,high);
	DIO_vidWritePinValue(d,pin1,high);

while(1)
//{  if(DIO_u8ReadPinValue(d,pin0)==0)
//
{
	DIO_vidWritePinValue(a,pin0,high); //cw
		DIO_vidWritePinValue(a,pin3,low);
		DIO_vidWritePinValue(a,pin2,high);
		DIO_vidWritePinValue(a,pin1,low);

//}
      _delay_ms(4000);


//else if(DIO_u8ReadPinValue(d,pin1)==0)
//{
	DIO_vidWritePinValue(a,pin1,high);  //ccw
	DIO_vidWritePinValue(a,pin2,low);
	DIO_vidWritePinValue(a,pin0,low);
	DIO_vidWritePinValue(a,pin3,high);
    _delay_ms(4000);

//}
//else{
	DIO_vidWritePinValue(a,pin0,low);
	DIO_vidWritePinValue(a,pin3,low);
	DIO_vidWritePinValue(a,pin1,low);
	DIO_vidWritePinValue(a,pin2,low);

//    }
    _delay_ms(4000);


}

}
