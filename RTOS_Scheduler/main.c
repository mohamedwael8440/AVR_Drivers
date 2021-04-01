
#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include "timer.h"
#include "scheduler.h"

void LED1(void)
{
	toggle_Bit(PORTA,0);
}
void LED2(void)
{
	toggle_Bit(PORTA,1);
}

void main(void)
{
	os_vidCreateTask(0,1000,LED1);
	os_vidCreateTask(1,500,LED2);
    os_vidStartScheduler();
    DIO_vidSetPinDir(a,pin0,output);
    DIO_vidSetPinDir(a,pin1,output);

	while(1)
	{

	}

}
