/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Mohamed Waleed
 */

#include "STD_Types.h"
#include "utilss.h"
#include "DIO.h"
#include "Timer1.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "lcd.h"

//FAST PWM for servo motor

int main (void)
{

	TIMER1_voidInit();
	LCD_Init();
	DIO_voidSetPinDirection(DIO_u8PinD5,DIO_u8PinOp); //OC1A
		while(1)
		{
			//OCR1AL=82;
			Gotoxy(1,1);
			LCD_String("Go to Ang : 0 ");
			TIMER1_u8GotoAng(0);
			_delay_ms(2000);
LCD_Command(0x01);
			LCD_String("Go to Ang : 60 ");
			TIMER1_u8GotoAng(60);
			_delay_ms(2000);
LCD_Command(0x01);
			LCD_String("Go to Ang : 90 ");
			TIMER1_u8GotoAng(90);
			_delay_ms(2000);
			LCD_Command(0x01);
						LCD_String("Go to Ang : 120 ");
						TIMER1_u8GotoAng(120);
						_delay_ms(2000);
LCD_Command(0x01);
						LCD_String("Go to Ang : 180 ");
						TIMER1_u8GotoAng(180);
						_delay_ms(2000);
						LCD_Command(0x01);



		}


	return -1;
}
