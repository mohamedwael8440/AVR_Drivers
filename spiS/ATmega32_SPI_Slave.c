/*
 * ATmega32_SPI_Slave.c
 * http://www.electronicwings.com
 */ 


#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */
#include "std_types.h"
#include <util/delay.h>
#include "registers.h"
#include "utils.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include Delay header file */
#include <stdio.h>
#include <string.h>						/* Include string header file */
#include "SPI_Slave_H_file.h"			/* Include SPI slave header file */


int main(void)
{
	uint8_t count;
	char buffer[5];
	
	LCD_init();
	SPI_Init();
	
	LCD_writestring ("Slave Device");
	LCD_setposition(1,0);
	LCD_writestring( "send Data:    ");
	while (1)
	{
//		count = SPI_Receive();
//		sprintf(buffer, "%d   ", count);
//		LCD_setposition(1,13);
//		LCD_writestring(buffer);
		SPI_vidSlaveSend('A');
	}

}
