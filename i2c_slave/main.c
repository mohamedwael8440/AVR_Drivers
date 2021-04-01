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
	char x;
	LCD_init();
	I2C_slaveInit(0x30);
	LCD_writestring("i2c slave init");

	while(1)
	{ I2C_Match_ACK();
	x=I2C_ReadData();
	LCD_setposition(1,1);
	if(x==60)
	{
	LCD_writestring("all right ");
	LCDWriteInt(x);
	}

}}


