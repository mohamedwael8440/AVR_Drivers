/*
 * lcd.h
 *
 *  Created on: Sep 15, 2019
 *      Author: Wael
 */

#ifndef LCD_H_
#define LCD_H_


#define LCD_Dir  DDRB			/* Define LCD data port direction */
#define LCD_Port PORTB			/* Define LCD data port */
#define RS PB0				/* Define Register Select pin */
#define EN PB1 				/* Define Enable signal pin */

void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
void LCD_Gotoxy (char Y,char X);
void LCD_vidWriteInteger(u32 m);






#endif /* LCD_H_ */
