/*
 * Keypad.h
 *
 *  Created on: 24Aug.,2019
 *      Author: Fahim
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


/***************************************************************************************/


/***************************************** Macros **************************************/

#define COL_INIT   pin1

#define COL_FIN    pin3

#define ROW_INIT   pin7

#define ROW_FIN    pin3

#define NOT_PRESSED    0
/***************************************************************************************/


/***************************************************************************************/
void Keypad_vidInit(void);
u8 KPD_u8GetPressedKey(void);

#endif /* KEYPAD_H_ */
