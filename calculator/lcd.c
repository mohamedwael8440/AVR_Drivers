/*
 * lcd.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include <avr/delay.h>
#include "lcd_cfg.h"
#include "lcd.h"
#define F_CPU 8000000


void lcd_vidWriteCommand(u8 command)
{
	//RW=0
  DIO_vidWritePinValue(controlport,rw_pin,low);
  //RS=0
  DIO_vidWritePinValue(controlport,rs_pin,low);
//dataport
  DIO_vidWritePortValue(dataport,command);
  //E=1
  DIO_vidWritePinValue(controlport,EN_pin,high);
  _delay_ms(2);
  DIO_vidWritePinValue(controlport,EN_pin,low);
 }

void lcd_vidInit(void)
{
  DIO_vidSetPinDir(controlport,rs_pin,output);
  DIO_vidSetPinDir(controlport,rw_pin,output);
  DIO_vidSetPinDir(controlport,EN_pin,output);
  DIO_vidSetPortDir(dataport,0xff);

   _delay_ms(50);
   lcd_vidWriteCommand(0b00111100);
   _delay_ms(1);
   lcd_vidWriteCommand(0b00001111);
   _delay_ms(1);
   lcd_vidWriteCommand(0b00000001);
   _delay_ms(1);
}


void lcd_vidWriteData(u8 data)
{
	//RW=0
 DIO_vidWritePinValue(controlport,rw_pin,low);

	//RS=1  display
 DIO_vidWritePinValue(controlport,rs_pin,high);

//DATA PORT
 DIO_vidWritePortValue(dataport, data);

 //E=1

 DIO_vidWritePinValue(controlport,EN_pin,high);
 _delay_ms(2);
 DIO_vidWritePinValue(controlport,EN_pin,low);

 }



void lcd_write_string(char *string)
	{
		char i = 0;									  // character counter*/
	    while (string[i] != '\0')
	    {
	        lcd_vidWriteData(string[i]);
	        i++;
	        _delay_us(80);							  // 40 uS delay (min)
	    }
	}


u8 return_ASCII(u8 symbol)
{
	if(symbol==0)
	{
	return 0b00110000;
	}
	else if(symbol==1)
	{
		return 0b00110001;
	}
	else if(symbol==2)
	{
		return 0b00110010;}
	else if(symbol==3)
	{
		return 0b00110011;}
	else if(symbol==4)
	{
		return 0b00110100;
	}
	else if(symbol==5)
	{
		return 0b00110101;
	}
	else if(symbol==6)
	{
		return 0b00110110;
	}
	else if(symbol==7)
	{
		return 0b00110111;
	}
	else if(symbol==8)
	{
		return 0b00111000;
	}
	else if(symbol==9)
	{
		return 0b00111001;}

}

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{

//	/* Local loop index */
//	u8 u8Index = 0;
	u8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
	lcd_vidWriteData(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}



void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	lcd_vidWriteCommand(X+127);
		    break;
		    case 2:
		    	lcd_vidWriteCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

