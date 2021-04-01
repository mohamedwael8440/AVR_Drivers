/*
 * timer.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Wael
 */


#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"

void __vector_11(void)  __attribute__((signal,__INTR_ATTRS));
 u32 counter=0;


void timer_vidInit(void)
{
//	OCR0=99;  // value to compare
	TCCR0=0b00000010; //timer control
	Set_Bit(TIMSK,0); //ENABLE INT bit0 or bit1(compare)
	Set_Bit(SREG,7);  //global INT

}


void __vector_11(void)
{
   counter++;
//   if(counter==80000)
//   {
//	   toggle_Bit(PORTA,0);
//	   counter=0;
//   }
}
