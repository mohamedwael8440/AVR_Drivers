/*
 * Keypad.c
 *
 *  Created on: 24Aug.,2019
 *      Author: Fahim
 */
#include "registers.h"
#include "utils.h"
#include "standardtypes.h"
#include "DIO.h"
#include "Keypad.h"
#include "KeypadConfig.h"
#include "lcd.h"
#include <avr/delay.h>




u8 Pressedkey=0;
u8 count=0;


void Keypad_vidInit(void)
{
	DIO_vidSetPortDir(KeypadPort,0b11110000); // high nibble output high , while lower nibble input low //
	DIO_vidWritePortValue(KeypadPort,0b11111111);  // lower nibble input pullup so write high //
}

void Keypad_vidGetPressedKey(void)
{
	DIO_vidWritePinValue(KeypadPort,R1,low);
	DIO_vidWritePinValue(KeypadPort,R2,high);
	DIO_vidWritePinValue(KeypadPort,R3,high);
	DIO_vidWritePinValue(KeypadPort,R4,high);

	if(DIO_u8ReadPinValue(KeypadPort,C1)==0)
	{
		Pressedkey=1;
		//DIO_vidWritePinValue(b,0,high);
       //Gotoxy(1,1);
		//lcd_vidWriteData('1');
		count++;

	}
	else if (DIO_u8ReadPinValue(KeypadPort,C2)==0)
	{
		Pressedkey=2;
	    	//DIO_vidWritePinValue(b,0,low);
	    	count++;
		 //Gotoxy(1,1);
			//	lcd_vidWriteData('2');
	}
	else if (DIO_u8ReadPinValue(KeypadPort,C3)==0)
		{
			Pressedkey=3;
		//	DIO_vidWritePinValue(b,0,high);
			count++;
			 //Gotoxy(1,1);
			//lcd_vidWriteData('3');
		}
	else if (DIO_u8ReadPinValue(KeypadPort,C4)==0)
		{
		Pressedkey='/';
		//	DIO_vidWritePinValue(b,0,low);
			 //Gotoxy(1,1);
			//lcd_vidWriteData('/');
			count++;
		}



	DIO_vidWritePinValue(KeypadPort,R1,high);
		DIO_vidWritePinValue(KeypadPort,R2,low);
		DIO_vidWritePinValue(KeypadPort,R3,high);
		DIO_vidWritePinValue(KeypadPort,R4,high);

		if(DIO_u8ReadPinValue(KeypadPort,C1)==0)
		{
			Pressedkey=4;
			//DIO_vidWritePinValue(b,0,high);
			count++;
			 //Gotoxy(1,1);
		//	lcd_vidWriteData('4');
		}
		else if (DIO_u8ReadPinValue(KeypadPort,C2)==0)
		{
			Pressedkey=5;
			//DIO_vidWritePinValue(b,0,low);
			count++;
			 //Gotoxy(1,1);
			//lcd_vidWriteData('5');
		}
		else if (DIO_u8ReadPinValue(KeypadPort,C3)==0)
			{
				Pressedkey=6;
				//DIO_vidWritePinValue(b,0,high);
				//count++;
				 //Gotoxy(1,1);
				//lcd_vidWriteData('6');
			}
		else if (DIO_u8ReadPinValue(KeypadPort,C4)==0)
			{
			Pressedkey='*';
				//DIO_vidWritePinValue(b,0,low);
				count++;
				 //Gotoxy(1,1);
				//lcd_vidWriteData('*');
			}

		DIO_vidWritePinValue(KeypadPort,R1,high);
			DIO_vidWritePinValue(KeypadPort,R2,high);
			DIO_vidWritePinValue(KeypadPort,R3,low);
			DIO_vidWritePinValue(KeypadPort,R4,high);

			if(DIO_u8ReadPinValue(KeypadPort,C1)==0)
			{
				Pressedkey=7;
				//DIO_vidWritePinValue(b,0,high);
				count++;
				 //Gotoxy(1,1);
				//lcd_vidWriteData('7');
			}
			else if (DIO_u8ReadPinValue(KeypadPort,C2)==0)
			{
				Pressedkey=8;
				//DIO_vidWritePinValue(b,0,low);
				count++;
//				 //Gotoxy(1,1);
//				lcd_vidWriteData('8');
			}
			else if (DIO_u8ReadPinValue(KeypadPort,C3)==0)
				{
					Pressedkey=9;
					//DIO_vidWritePinValue(b,0,high);
					count++;
					 //Gotoxy(1,1);
					//lcd_vidWriteData('9');
				}
			else if (DIO_u8ReadPinValue(KeypadPort,C4)==0)
				{
				Pressedkey='-';
					//DIO_vidWritePinValue(b,0,low);
					count++;
					// Gotoxy(1,1);
					//lcd_vidWriteData('-');
				}

			DIO_vidWritePinValue(KeypadPort,R1,high);
				DIO_vidWritePinValue(KeypadPort,R2,high);
				DIO_vidWritePinValue(KeypadPort,R3,high);
				DIO_vidWritePinValue(KeypadPort,R4,low);

				if(DIO_u8ReadPinValue(KeypadPort,C1)==0)
				{
					Pressedkey='c';
					//DIO_vidWritePinValue(b,0,high);
					count++;
					 //Gotoxy(1,1);
					//lcd_write_string("on/of");
					//_delay_ms(1000);
					//lcd_vidWriteCommand(0x01);

				}
				else if (DIO_u8ReadPinValue(KeypadPort,C2)==0)
				{
					Pressedkey=0;
					//DIO_vidWritePinValue(b,0,low);
					count++;
					 //Gotoxy(1,1);
					//lcd_vidWriteData('0');

				}
				else if (DIO_u8ReadPinValue(KeypadPort,C3)==0)
					{
					Pressedkey ='=';
						//DIO_vidWritePinValue(b,0,high);
						count++;
						// Gotoxy(1,1);
						//lcd_vidWriteData('=');
					}
				else if (DIO_u8ReadPinValue(KeypadPort,C4)==0)
					{
					Pressedkey='+';
					count++;
					 //Gotoxy(1,1);
					//	DIO_vidWritePinValue(b,0,low);
//						lcd_vidWriteData('+');
					}



}
//void keypad_no of times sWitchPressed (void)
//
//{
//
//	   char buffer [100];
//
//     itoa (x,buffer,10);
//
//	    lcd_write_string(buffer);
//	    _delay_ms(200);
//
//}
