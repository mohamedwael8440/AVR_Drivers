/*
 * lcd.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#ifndef LCD_H_
#define LCD_H_

#define lcd_Clear           0x01

void lcd_vidWriteCommand(u8 command);
void lcd_vidWriteData(u8 data);
void lcd_vidInit(void);
void lcd_write_string(char *string);
u8 return_ASCII(u8 symbol);
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);
void Gotoxy (u8 Y,u8 X);


#endif /* LCD_H_ */
