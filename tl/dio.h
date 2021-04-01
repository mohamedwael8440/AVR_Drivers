/*
 * dio.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */

#ifndef DIO_H_
#define DIO_H_


void dio_vidSetPinDir(u8 port,u8 pin,u8 dir);
void dio_vidWritePinDir(u8 port,u8 pin,u8 value);
u8 dio_u8ReadPinValue(u8 port,u8 pin);
void dio_vidSetPortDir(u8 port,u8 dir);
void dio_vidWritePort(u8 port,u8 value);

#endif /* DIO_H_ */
