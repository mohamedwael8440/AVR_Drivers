/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#include"lcd.h"
#include <util/delay.h>			/* Include Delay header file */


/*Hex value to create the pattern (Arrow)*/
unsigned char Pattern1[] = {0x00,0x00,0x00,0x00,0x00,0x0e,0x11,0x11};
/*Hex value to create the pattern (betel leaf)*/
unsigned char Pattern2[]= {0x0e,0x11,0x11,0x11,0x11,0x11,0x11,0x11};
unsigned char Pattern3[] = {0x11,0x11,0x11,0x1f,0x00,0x00,0x00,0x00};


void main(void)
{

	LCD_Init();			/* Initialization of LCD*/
	LCD_CreateCustomCharacter(Pattern1,0);
	LCD_CreateCustomCharacter(Pattern2,1);
	LCD_CreateCustomCharacter(Pattern3,2);


	while(1)
	{
  Gotoxy(1,4);
  LCD_String("say hello t'y");
  Gotoxy(2,4);
  LCD_String("little friend");
Gotoxy(1,1);
LCD_Char(0);
Gotoxy(1,3);
LCD_Char(0);
Gotoxy(2,1);
LCD_Char(2);
Gotoxy(2,2);
LCD_Char(2);
Gotoxy(2,3);
LCD_Char(2);


Gotoxy(1,2);
LCD_Char(0);
_delay_ms(250);
Gotoxy(1,2);
LCD_Char(1);
_delay_ms(250);



	}
}
