/*
                * calculator.c
 *
 *  Created on: Aug 27, 2019
 *      Author: Wael
 */
#include "registers.h"
#include "utils.h"
#include "standardtypes.h"
#include "DIO.h"
#include "lcd.h"
#include "Keypad.h"
#include <avr/delay.h>

u8 result;
extern u8 Pressedkey;
u8 currentvalue;
extern u8 count;
u8 loop=0,result;
///getno1 get op get no2 calc//
void Keypad_getn1Vid(void)
{
if(loop==0 && Pressedkey!='+' && Pressedkey!='-' && Pressedkey!='*' && Pressedkey!='/' )
{  u8 num1,num2,num3;
    loop++;
	if(loop==1)
	{	 num1=Pressedkey;
	}
	if(loop==2)
		{ num2=num1*10+Pressedkey;
		}
	if(loop==3)
		{ num3=num1*100+num2*10+Pressedkey;
		}
	}
}
}
