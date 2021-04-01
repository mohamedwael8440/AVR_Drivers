/*
 * main.c
 *
 *  Created on: Sep 4, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "SEG_CFG.h"
#include "avr/delay.h"

void main(void)
{
	 SEG_vidInit();

	 while(1)
	 {
	 SEG_vidDisplayNO(9);
//		 _delay_ms(2000);
		// SEG_vidCount(2,0,4,2);  // start count at 20 and stop count at 42

	 }
}
