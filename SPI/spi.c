/*
 * spi.c
 *
 *  Created on: Jan 19, 2020
 *      Author: Wael
 */
#include "registers.h"
#include "std_types.h"
#include "utils.h"
#include <avr/io.h>
#include "DIO.h"
#include "spi.h"


void SPI_vidMasterInit(void)
{ //direction Initialization
// DIOSetPinDirection(b,pin5,output); //MOSI O/P
// DIOSetPinDirection(b,pin6,input);  //MISO I/P
// DIOSetPinDirection(b,pin7,output); // SCK O/P
// DIOSetPinDirection(b,pin4,output);  //SS I/P
//// DIOSetPinValue(b,pin4,high); // SS PULLED UP
////SPI Enable
// Set_Bit(SPCR,6);
// //MASTER SELECT
// Set_Bit(SPCR,4);
// //clock TO divide by 16
// Set_Bit(SPCR,0);
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);		/* Make MOSI, SCK, 0th pin direction as output pins */
		DDRB &= ~(1<<MISO);						/* Make MISO pin as input pin */
		PORTB |= (1<<SS);						/* Disable slave initially by making high on SS pin */
		SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI, Enable in master mode, with Fosc/16 SCK frequency */
		SPSR &= ~(1<<SPI2X);					/* Disable speed doubler */

}


void SPI_vidSlaveInit(void)
{
//	//direction Initialization
//	DIOSetPinDirection(b,pin5,input); //MOSI I/P
//	DIOSetPinDirection(b,pin6,output);  //MISO O/P
//	DIOSetPinDirection(b,pin7,input); // SCK I/P
//	DIOSetPinDirection(b,pin4,input);  //SS I/P
////	DIOSetPinValue(b,pin4,high); // SS PULLED UP
// Set_Bit(SPCR,6);
////SPI Enable
	DDRB &= ~((1<<MOSI)|(1<<SCK)|(1<<SS));		/* Make MOSI, SCK, SS pin direction as input pins */
	DDRB |= (1<<MISO);							/* Make MISO pin as output pin */
	SPCR = (1<<SPE);							/* Enable SPI in slave mode */

}
void SPI_vidMasterSend(u8 data)
{    u8 access_data;
	// send data
	SPDR=data;
	//check data is sent
	while((Get_Bit(SPSR,7))==0); // el flag dah msh benzal 3'er lma 2a2rah w 2aro7 2a2arah fa 3amalt var esmo access data fa kda 2arato
	access_data=SPDR; //READ SPDR TO CLEAR FLAG
}

u8 SPI_u8SlaveReceive(void)
{  // CHECK data is received
  while((Get_Bit(SPSR,7))==0);
  // read the data
  return SPDR;
}

u8 SPI_u8MasterReceive(void)
{
	// send null lazm ana ka master 2abda2 communication 3ashn el data el 3ando tagele
	SPDR=10;
	while((Get_Bit(SPSR,7))==0);
	return SPDR;
}
void SPI_vidSlaveSend(u8 data)
{
   u8 access_data;
   SPDR=data;
   //check data is sent
   while((Get_Bit(SPSR,7))==0);
   //CLEAR THE FLAG
   access_data=SPDR;
}

