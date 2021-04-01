/*
 * main.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */

#include "avr/io.h"
#include "avr/delay.h"
#define F_CPU 8000000
typedef unsigned int u8;

void main(void)
{
    DDRA = 0xff;           // Configure PORTA as output to connect seg

   u8 anm1[11]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};
   u8 anm2[11]={0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b00000001};
   u8 anm3[11]={0b11111111,0b11111110,0b11111100,0b11111000,0b11110000,0b11100000,0b11000000,0b10000000};
   u8 anm4[11]={0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111};
   u8 anm5[11]={0b10000001,0b01000010,0b00100100,0b00011000,0b00100100,0b01000010,0b10000001,0b00000000};


   u8 i;

    while(1)
    {
    	for(i=0;i<2;i++)
    {
       for(i=0;i<8;i++)
       {
           PORTA=anm5[i];
           _delay_ms(200);
       }
    }
      	for(i=0;i<2;i++)
        {
           for(i=0;i<8;i++)
           {
               PORTA=anm1[i];
               _delay_ms(200);
           }

        }

      	for(i=0;i<2;i++)
        {
           for(i=0;i<8;i++)
           {
               PORTA=anm2[i];
               _delay_ms(200);
           }

        }

      	for(i=0;i<2;i++)
        {
           for(i=0;i<8;i++)
           {
               PORTA=anm3[i];
               _delay_ms(200);
           }

        }

      	for(i=0;i<2;i++)
        {
           for(i=0;i<8;i++)
           {
               PORTA=anm4[i];
               _delay_ms(200);
           }

        }
  }
  }
