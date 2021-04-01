#define F_CPU 8000000
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include "DIO.h"
#include "LCD.h"
#include "I2c.h"

u8 x=11,v;
int main(void)
{
	//master read
	LCD_init();
	i2c_init_master();
//	_delay_ms(2000);

	LCD_writestring("connecting");

	i2c_start();

	LCD_writestring("....");


	i2c_send_slave_address_with_read_req(0x00);
	x=i2c_read_byte();
LCD_setposition(1,1);
	LCD_writestring("found");
  LCDWriteInt(i2c_read_byte());
   if(x==5)
   {
	   LCD_setposition(1,7);
		LCD_writestring("r");


   }
   // i2c_stop();


//LCDWriteInt(x);
	while (1)
	{

	}
}
