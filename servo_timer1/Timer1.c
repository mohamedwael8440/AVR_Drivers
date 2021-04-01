/*
 * Timer1.c
 *
 *  Created on: Feb 15, 2018
 *      Author: Mohamed Waleed
 */

#include "utilss.h"
#include "STD_Types.h"
#include "Timer1.h"


#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)
#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)


u16 y=0;


extern void TIMER1_voidInit(void)
{
	TCCR1A |=0b10000010;
	TCCR1B |=0b00011100;
	ICR1L=625;

}
extern void TIMER1_u8GotoAng(u8 ang)
{
	if(ang>=0 && ang<181)
	{
	       u16 y=11+0.34*ang;
			OCR1AL= y; // to keep it in  range of 11 and 82 which corresponds to 0 and 180 from calibration 82=11+factor(180)

	}
}

