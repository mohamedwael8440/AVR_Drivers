/*
 * main.c
 *
 *  Created on: Jan 12, 2020
 *      Author: M_WA
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "i2c.h"
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"

int main()
{
	LCD_init();
	I2C_Init();
	LCD_writestring("I2C MASTER INIT");
	{
		I2C_Start();
		_delay_ms(10);
		I2C_Write_ADD(0x30);
		_delay_ms(10);
		I2C_WriteData(60);
		LCD_setposition(1,1);
		LCD_writestring("SEND '60' ");
		_delay_ms(10);
         I2C_Stop();


	}

}


