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

void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	lcd_vidWriteCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	lcd_vidWriteCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	lcd_vidWriteCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	lcd_vidWriteCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	lcd_vidWriteCommand(lcd_EntryMode);
	_delay_ms(2);

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
	        _delay_us(100);							  // 40 uS delay (min)
	    }
	}


u8 return_ASCII(u8 number)
{
	if(number==0)
	{
	return 0b00110000;
	}
	else if(number==1)
	{
		return 0b00110001;
	}
	else if(number==2)
	{
		return 0b00110010;}
	else if(number==3)
	{
		return 0b00110011;}
	else if(number==4)
	{
		return 0b00110100;
	}
	else if(number==5)
	{
		return 0b00110101;
	}
	else if(number==6)
	{
		return 0b00110110;
	}
	else if(number==7)
	{
		return 0b00110111;
	}
	else if(number==8)
	{
		return 0b00111000;
	}
	else if(number==9)
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

void LCD_vidPrintINT(u16 INT ,u8 digit)
{ u16 RES;
	switch(digit)
	{
	case 1 :
		_delay_us(200);
		lcd_vidWriteData(return_ASCII(INT));
		break;
	case 2 :
		RES=(INT/10)%10;
		_delay_us(200);
		lcd_vidWriteData(return_ASCII(RES));
	   	RES=INT%10;
		_delay_us(200);
		lcd_vidWriteData(return_ASCII(RES));
		break;
	case 3 :
		RES=(INT/100)%10;
		_delay_us(200);
	    lcd_vidWriteData(return_ASCII(RES));
		RES=(INT/10)%10;
		_delay_us(200);
		lcd_vidWriteData(return_ASCII(RES));
		RES=INT%10;
		_delay_us(200);
		lcd_vidWriteData(return_ASCII(RES));
		break;
//	case 4 :
//		RES=(INT/1000)%10;
//		_delay_us(200);
//	    lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/100)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/10)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=INT%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		break;
//	case 5 :
//		RES=(INT/10000)%10;
//		_delay_us(200);
//		 lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/1000)%10;
//		_delay_us(200);
//	    lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/100)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/10)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=INT%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		break;
//	case 6 :
//		RES=(INT/100000)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/10000)%10;
//		_delay_us(200);
//		 lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/1000)%10;
//		_delay_us(200);
//	    lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/100)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=(INT/10)%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		RES=INT%10;
//		_delay_us(200);
//		lcd_vidWriteData(return_ASCII(RES));
//		break;

	}
}

