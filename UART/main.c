
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "UART.h"

void main(void)
{ u8 value=0;
DIO_vidSetPinDir(a,pin0,output);
USART_vidInit();
while(1)
{
	value=USART_u8Receive();
	if(value=='1')
	{
		DIO_vidWritePinValue(a,pin0,high);
	}
}

}
