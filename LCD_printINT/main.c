/*
 * main.c
 *
 *  Created on: Sep 2, 2019
 *      Author: Wael
 */


#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include <avr/delay.h>
#include "lcd_cfg.h"
#include "lcd.h"

void main(void)
{
	LCD_vidInit();

LCD_vidWriteCharctr('M');
}
