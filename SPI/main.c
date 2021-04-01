#define F_CPU 8000000
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include "utils.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "spi.h"


void main(void)
{ PORTB &= ~(1<<SS);			/* Define Slave enable */
	LCD_init();
SPI_vidMasterInit();
LCD_writestring("MASTER ");


u8 x=SPI_u8MasterReceive();
LCD_setposition(1,1);
LCD_writedata(SPI_u8MasterReceive());
//if(x==5)
//{
//	LCD_writestring("CORRECT");
//}
while(1)
{
	}


}
