/*
 * UART.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Wael
 */

#ifndef UART_H_
#define UART_H_

void USART_vidInit(void);
void USART_vidTransmit(u8 data);
u8 USART_u8Receive(void);



#endif /* UART_H_ */
