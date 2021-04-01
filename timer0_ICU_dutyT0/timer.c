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
#include "timer.h"
#include "ADC.h"

void __vector_6(void)  __attribute__((signal,__INTR_ATTRS));
void __vector_9(void)  __attribute__((signal,__INTR_ATTRS));


u32 counter=0,c1=0,c2=0,c3=0;
u8 flag=0;
u32 duty=0;

void timer0_vidInit(void)
{
  //  OCR0=64;  // value to compare dutycycle 25% of 256
	TCCR0=0b01101101; //timer control


}
void timer1_vidInit(void)
{
    TCCR1A=0b00000000;
    TCCR1B=0b01000001;
    Set_Bit(TIMSK,5); // icu int
    Set_Bit(TIMSK,2); //overflow int
    Set_Bit(SREG,7); // GI INT
    DIO_vidSetPinDir(d,pin6,input);

}

void __vector_6(void) //icu
{

   if(flag==0)
   {   c1=ICR1L;
	   counter=0;
	   Clr_Bit(TCCR1B,6);
   }
   if(flag==1)
     {   c2=ICR1L+(counter*65535);

  	   Set_Bit(TCCR1B,6);
     }
   if(flag==2)
     {   c3=ICR1L+(counter*65535);
  	   counter=ICR1L+(counter*65535);
  	   Clr_Bit(TIMSK,5); // Disable icu INT
     }

     flag++;
}

void __vector_9(void)
{
	counter++;
}
