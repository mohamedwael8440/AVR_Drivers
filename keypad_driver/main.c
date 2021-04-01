/*
 * main.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Wael
 */
#include "registers.h"
#include "utils.h"
#include "std_types.h"
#include "dio.h"
#include "keypad.h"
#include "keypad_cfg.h"


extern u8 pressed_key;

void main(void)
{
	keypad_vidInit();
	dio_vidSetPinDir(d,0,output);

	while(1)
	{
	 keypad_vidGetpressedKey();
	 if(pressed_key==3)
	 {
    	 dio_vidWritePin(d,0,high);

	 }
	}
}

