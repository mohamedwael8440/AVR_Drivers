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
#include "scheduler.h"
#include "timer.h"

 u32 counter=0;


void timer_vidInit(void)
{
   	OCR0=125;  // value to compare
	TCCR0=0b00001011; //timer control
	Set_Bit(TIMSK,1); //ENABLE INT bit0 or bit1(compare)
	Set_Bit(SREG,7);  //global INT

}

void __vector_10(void)  __attribute__((signal,__INTR_ATTRS));
void __vector_10(void)
{
   counter++;
   os_vidScheduler();
}
