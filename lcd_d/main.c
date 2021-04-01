/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include <avr/delay.h>
#include "lcd_cfg.h"
#include "lcd.h"


void main (void)

{

lcd_vidInit();

//lcd_write_string("WAEL");
//LCD_vidPrintINT(765,3);
while(1)
{
Gotoxy(2,1);
lcd_write_string("WAEL");
}




}


