/*
 * ATmega16_Master.c
 * http://www.electronicwings.com
 */ 

#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include "utils.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include Delay header file */
#include <stdio.h>
#include <string.h>
#include "SPI_Master_H_file.h"			/* Include SPI master header file */

int main(void)
{
	uint8_t count;
	char buffer[5];
	
	LCD_init();
	SPI_Init();

	LCD_setposition(0,10);
	LCD_writestring("master");
	LCD_setposition(0,0);
	LCD_writestring( "slave1:");
	LCD_setposition(1,0);
	LCD_writestring( "slave2:");

	count = 0;
	while (1)
	{
//		SPI_Write(count);
//		sprintf(buffer, "%d   ", count);
//		SS2_Disable;
//		SS_Enable;

//		LCD_writestring(buffer);
//		count++;
//		_delay_ms(500);
//		   LCD_setposition(0,8);
//		u8 x=SPI_u8MasterReceive();
//		if(x=='A')
//		{
//			LCD_writedata('A');
//			x=0;
//			SS_Disable;
//
//		}
		SS2_Enable;
		 u8 y=SPI_u8MasterReceive();
		LCD_setposition(1,8);
		if(y=='A')
				{
					LCD_writedata('A');
					SS2_Disable;
					y=0;

				}
				SS_Enable;

				   LCD_setposition(0,8);
				u8 x=SPI_u8MasterReceive();
				if(x=='B')
				{
					LCD_writedata('B');
					SS_Disable;

					x=0;

				}



//		if(x==2)
//		{
//			LCD_writestring("correct");
//		}
	}
		
}
