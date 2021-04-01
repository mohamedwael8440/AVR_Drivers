/*
 * DEI.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Wael
 */
#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"



void DEI_vidInit()
{
	Set_Bit(SREG,7);  // enable gi

	Set_Bit(MCUCR,1);// Trigger mode
	Clr_Bit(MCUCR,0); // Trigger mode
	Set_Bit(GICR,6); // Enable PIE of DEI INT 0

	Set_Bit(MCUCR,3);// Trigger mode
	Clr_Bit(MCUCR,2); // Trigger mode
	Set_Bit(GICR,7); // Enable PIE of DEi INT1

}

void __vector_1(void)  __attribute__((signal,__INTR_ATTRS));
void __vector_1(void)
{
	DIO_vidWritePinValue(a,pin0,high);
}


void __vector_2(void)  __attribute__((signal,__INTR_ATTRS));
void __vector_2(void)
{
	DIO_vidWritePinValue(a,pin0,low);
}
