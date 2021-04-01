/*
 * Keypad.c
 *
 *  Created on: 24Aug.,2019
 *      Author: Fahim
 */
#include "registers.h"
#include "utils.h"
#include "standardtypes.h"
#include "DIO.h"
#include "Keypad.h"
#include "KeypadConfig.h"
#include <avr/delay.h>


/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/




/************* KeyPad Key Index ***************/
/*         Col_3    Col_2   Col_1   Col_0     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
{
  {
    0x04,
    0x08,
    0x0C,
    0x10 },
  {
    0x03,
    0x07,
    0x0B,
    0x0F },
  {
    0x02,
    0x06,
    0x0A,
    0x0E },
  {
    0x01,
    0x05,
    0x09,
    0x0D }
};

/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(void)
{

  u8 LOC_u8Column;

  u8 LOC_u8Row;

  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;

  /* Looping on columns of the Key Pad                                                                               */
  for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
    DIO_vidWritePinValue(KeypadPort, LOC_u8Column, low);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
    {
      /* Check the status of the switch                                                                              */
      if (!DIO_u8ReadPinValue(KeypadPort, LOC_u8Row))
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

        /* Wait until the switch is released (Single Press)                                                          */
        while (!DIO_u8ReadPinValue(KeypadPort, LOC_u8Row))
          ;

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(10);

      }
    }

    /* Deactivate the Column                                                                                         */
    DIO_vidWritePinValue(KeypadPort, LOC_u8Column, high);
  }

  return LOC_u8Retrun;
}


void Keypad_vidInit(void)
{
	DIO_vidSetPortDir(KeypadPort,0b00001111); // high nibble output high , while lower nibble input low //
	DIO_vidWritePortValue(KeypadPort,0b11111111);  // lower nibble input pullup so write high //
}
