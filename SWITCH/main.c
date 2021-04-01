
#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "switch.h"
#include <util/delay.h>



void main(void)
{
SWITCH_vidInit(c,pin7 );
DIO_vidSetPinDir(a,pin0,output);
while(1)
{
if(SWITCH_u8Readswitch(c,pin7)==0)  //check for switch
{
	DIO_vidWritePinValue(a,pin0,high);
}
else
{
	DIO_vidWritePinValue(a,pin0,low);
}

}
}
