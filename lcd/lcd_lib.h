/*
 * lcd_lib.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Wael
 */

#define LCD_DATA PORTC
#define ctrl PORTD
#define rs 2
#define rw 1
#define en 0

#include <avr/io.h>
#include <util/delay.h>

void LCD_cmd(unsigned char);

void LCD_init();

void LCD_write(unsigned char);

void LCD_write_string(unsigned char*);
void LCD_clear();
void LCD_gotoxy(int, int);
