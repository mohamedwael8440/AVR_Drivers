/*
 * DIO.h
 *
 *  Created on: 17Aug.,2019
 *      Author: Fahim
 */

#ifndef DIO_H_
#define DIO_H_
#define a 0
#define b 1
#define c 2
#define d 3

#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7


#define output 1
#define input 0
#define high 1
#define low 0



void DIO_vidSetPinDir (u8 port,u8 pin,u8 dir);
void DIO_vidWritePinValue (u8 port,u8 pin,u8 value);
void DIO_vidTogglePinValue (u8 port,u8 pin);
u8 DIO_u8ReadPinValue(u8 port, u8 pin);
void DIO_vidWritePortValue(u8 port, u8 Value);
void DIO_vidSetPortDir(u8 port, u8 Dir);



#endif /* DIO_H_ */
