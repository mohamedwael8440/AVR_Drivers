#define F_CPU 8000000
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include "utils.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "I2c.h"
#include "SPI_Slave_H_file.h"
#include "eeprom.h"

u8 x,v;
int main(void)
{
	//master write master read
	EEpromInit();
	LCD_init();
	//KeybPadInit();
//	LCD_writestring("Last Saved");
//	_delay_ms(500);

//	EEpromWriteByte(1,'B');
//	_delay_ms(500);
//
//	EEpromWriteByte(2,70);
//	_delay_ms(500);


	u8 v1 = EEpromReadByte(1);
	//u8 v2 = EEpromReadByte(2);

	LCD_setposition(0, 0);
	LCDWriteInt(v1);
	LCD_setposition(0, 4);
	LCD_writestring("Ascaii_code");


	//LCD_setposition(1, 0);
	//LCDWriteInt(v2);

//	_delay_ms(1000);
//	i2c_stop();
//	i2c_init_slave(0x00);
//	i2c_slave_write_byte(5);

	SPI_Init();
	LCD_setposition(1,0);
			LCD_writestring ("Slave Device 1");
			LCD_setposition(1,3);
while(1){
		SPI_vidSlaveSend(v1);
		}

}
