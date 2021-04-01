/*
 * i2c.c
 *
 *  Created on: Jan 12, 2020
 *      Author: M_WA
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


void I2C_slaveInit(unsigned char slave_add)
{
	TWAR=slave_add;

}

unsigned char I2C_ReadData()
{    unsigned char x;
	TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while((TWCR & (1<<TWINT))==0);
    while((TWSR & (0XF8)) !=0X80);
    x=TWDR;
    return x;

}
void I2C_Match_ACK()
{
while((TWSR & (0XF8))!=0X60)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while((TWCR &(1<<TWINT))==0);
}
}


