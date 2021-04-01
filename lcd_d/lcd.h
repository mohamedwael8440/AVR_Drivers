/*
 * lcd.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#ifndef LCD_H_
#define LCD_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position



void LCD_vidInit(void);

void lcd_vidWriteCommand(u8 command);
void lcd_vidWriteData(u8 data);
void lcd_vidInit(void);
void lcd_write_string(char *string);
u8 return_ASCII(u8 symbol);
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);
void Gotoxy (u8 Y,u8 X);
void LCD_vidPrintINT(u16 INT ,u8 digit);

#endif /* LCD_H_ */
