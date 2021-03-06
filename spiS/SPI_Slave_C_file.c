/*
 * SPI_Slave_C_file.c
 *
 */
#include "std_types.h"
#include "utils.h"
#include "SPI_Slave_H_file.h"

void SPI_Init()									/* SPI Initialize function */
{
	DDRB &= ~((1<<MOSI)|(1<<SCK)|(1<<SS));		/* Make MOSI, SCK, SS pin direction as input pins */
	DDRB |= (1<<MISO);							/* Make MISO pin as output pin */
	SPCR = (1<<SPE);							/* Enable SPI in slave mode */
}

char SPI_Transmit(char data)					/* SPI transmit data function */
{
	SPDR = data;								/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));					/* Wait till transmission complete */
	return(SPDR);								/* return received data */
}

char SPI_Receive()								/* SPI Receive data function */
{
	while(!(SPSR & (1<<SPIF)));					/* Wait till reception complete */
	return(SPDR);								/* return received data */
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
