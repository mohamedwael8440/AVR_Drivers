/*
 * i2c.c
 *
 *  Created on: Jan 12, 2020
 *      Author: M_WA
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


void I2C_Init()
{
	TWBR= 0X00; //CLEAR STATUS REG
	TWBR=0X0C; //Bit rate

}

void I2C_Start()
{
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTA); //CLEAR STATUS REG
while((TWCR &(TWINT))==0);
while((TWSR & (0XF8))!=0X08);
}
void I2C_Write_ADD(unsigned char ADDr )
{
	TWDR=ADDr;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT))==0);
	while((TWSR &(0XF8)) !=0X18);
}
void I2C_WriteData(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR & (1<<TWINT))==0);
while((TWSR & (0XF8)) !=0X28);

}

void I2C_Stop()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}
