/*
 * LED.h
 *
 *  Created on: Sep 3, 2019
 *      Author: Wael
 */

#ifndef LED_H_
#define LED_H_


#define blink 0
#define on   1
#define of   2

void LED_vidInit(u8 port , u8 pin,u8 dir );
void LED_vidBlink(u8 port,u8 pin , u8 delay);
void LED_vidONOF(u8 port,u8 pin ,u8 status );
void LED_vidFeature(u8 port , u8 pin ,u8 feature ,u8 delay);

#endif /* LED_H_ */
