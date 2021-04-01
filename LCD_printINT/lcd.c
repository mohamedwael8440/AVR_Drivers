/*
 * lcd.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#define F_CPU 8000000
#include "standardtypes.h"
#include "util/delay.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "lcd_cfg.h"
#include "lcd.h"



#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	 DIO_vidWritePinValue(controlport, 2, 0);

	/* Set R/W to LOW */
	 DIO_vidWritePinValue(controlport, 1, 0);

	/* Set E to HIGH  */
	 DIO_vidWritePinValue(controlport, 0, 1);

	/* Load Command on Data bus */
	DIO_vidWritePortValue(dataport, u8CmdCpy);

	/* Set E to LOW */
	 DIO_vidWritePinValue(controlport, 0, 0);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	 DIO_vidWritePinValue(controlport, 0, 1);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_vidWritePinValue(controlport, 2, 1);

	/* Set R/W to LOW */
	DIO_vidWritePinValue(controlport, 1, 0);

	/* Set E to HIGH */
	DIO_vidWritePinValue(controlport, 0, 1);

	/* Load Command on Data bus */
	DIO_vidWritePortValue(dataport, u8DataCpy);

	/* Set E to LOW */
	DIO_vidWritePinValue(controlport, 0, 0);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_vidWritePinValue(controlport, 0, 1);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{

//	/* Local loop index */
//	u8 u8Index = 0;
	u8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidSendCommand(X+127);
		    break;
		    case 2:
		    	LCD_vidSendCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

