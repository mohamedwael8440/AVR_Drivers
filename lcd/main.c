#define F_CPU 8000000UL    //crystal 8MHz
#include "lcd_lib.h"

void main(void)
{
	DDRC = 0xFF;
	DDRB = 0xFF;
	LCD_init();
	LCD_gotoxy(1,1);
	LCD_write_string("Mohammad");
	LCD_gotoxy(2, 9);
	LCD_write_string("Khaled");

	while(1)
	{
		// No Thing HERE !!!
	}
}

