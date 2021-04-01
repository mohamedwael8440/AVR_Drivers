/*
 * stepper.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#define F_CPU 8000000UL
#include "avr/delay.h"


// ULN2303 stepper

#define coilport b

void STEPPER_vidInit(void)
{
DIO_vidSetPortDir(coilport,0x0f);
}
void STEPPER_vidFULLstepCW(void)
{  DIO_vidWritePortValue(coilport,0b00000001);
_delay_ms(11);
  DIO_vidWritePortValue(coilport,0b00000010);
  _delay_ms(11);
    DIO_vidWritePortValue(coilport,0b00000100);
    _delay_ms(11);
      DIO_vidWritePortValue(coilport,0b00001000);
      _delay_ms(11);

}
void STEPPER_vidFULLstepCCW(void)
{
}
