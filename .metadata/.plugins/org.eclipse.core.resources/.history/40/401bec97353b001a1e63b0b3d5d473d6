/*
 * spi.h
 *
 *  Created on: Jan 19, 2020
 *      Author: Wael
 */

#ifndef SPI_H_
#define SPI_H_

#define MOSI 5								/* Define SPI bus pins */
#define MISO 6
#define SCK 7
#define SS 4
#define SS_Enable PORTB &= ~(1<<SS)			/* Define Slave enable */
#define SS_Disable PORTB |= (1<<SS)			/* Define Slave disable */

void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
void SPI_vidMasterSend(u8 data);
u8 SPI_u8SlaveReceive(void);
u8 SPI_u8MasterReceive(void);
void SPI_vidSlaveSend(u8 data);

#endif /* SPI_H_ */
