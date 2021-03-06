/*
 * SPI_Master_C_file.c
 *
 */ 
#include "std_types.h"
#include "utils.h"
#include "SPI_Master_H_file.h"				/* Include SPI Master header file */



void SPI_Init()								/* SPI Initialize function */
{
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);		/* Make MOSI, SCK, 0th pin direction as output pins */
	Set_Bit(DDRD,4);                        //ss2 as outputpin
	DDRB &= ~(1<<MISO);						/* Make MISO pin as input pin */
	PORTB |= (1<<SS);						/* Disable slave initially by making high on SS pin */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI, Enable in master mode, with Fosc/16 SCK frequency */
	SPSR &= ~(1<<SPI2X);					/* Disable speed doubler */
}

void SPI_Write(char data)					/* SPI write data function */
{
	char flush_buffer;
	SPDR = data;							/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));				/* Wait till transmission complete */
	flush_buffer = SPDR;					/* Flush received data */
/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}

char SPI_Read()								/* SPI read data function */
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));				/* Wait till reception complete */
	return(SPDR);							/* return received data */
}
 u8 SPI_u8MasterReceive(void)
{
	// send null lazm ana ka master 2abda2 communication 3ashn el data el 3ando tagele
	SPDR=10;
	while((Get_Bit(SPSR,7))==0);
	return SPDR;
}
