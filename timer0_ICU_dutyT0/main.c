
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "timer.h"
#include "ADC.h"



void main(void)
{   DIO_vidSetPinDir(b,pin3,output);

     ADC_init();
     timer0_vidInit();

	while(1)
	{
		OCR0=ADC_u16Read(0);

	}

}
