/*
 * dio.h
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
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
#define input  0

#define high 1
#define low  0

void dio_vidSetPinDir(u8 port,u8 pin,u8 dir);
void dio_vidWritePin(u8 port,u8 pin,u8 value);
u8 dio_u8ReadPinValue(u8 port,u8 pin);
void dio_vidPortDir(u8 port,u8 dir);
void dio_vidSetPortValue(u8 port,u8 value);






#endif /* DIO_H_ */
