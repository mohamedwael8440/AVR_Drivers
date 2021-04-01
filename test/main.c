/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */
#include <avr/io.h>
#define F_CPU 8000000

void main(void)
{
	            DDRD=0b00000000;
	            PORTD=0b11111111;

	    	    DDRC = 0b11111111;

while(1)
{
PORTC=0b1111111;

}
}
