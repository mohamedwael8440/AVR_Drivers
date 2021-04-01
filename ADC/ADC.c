/*
 * ADC.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Wael
 */
#include "standardtypes.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"


void ADC_init(void)
{
  //we need to clear unused bits
	Set_Bit(ADMUX,6); // SELECT VRE=VCC
    Set_Bit(ADCSRA,7); // ENABLE adc circuit
    Set_Bit(ADCSRA,2);
    Set_Bit(ADCSRA,0);
	//SELECT prescaller=32
}
u16 ADC_u16Read(u8 channel)
{
  ADMUX &=0b11100000; // init
  ADMUX|=channel; //select channel
  Set_Bit(ADCSRA,6); //start converstion
  while(!(Get_Bit(ADCSRA,4))); // ==0 wait till flag =1 and quit W B3D KDA E3MEL RESET BEL SOFTWARE
  Set_Bit(ADCSRA,4);
  // RESET ADIF
  return(ADC); // return digital value
}

