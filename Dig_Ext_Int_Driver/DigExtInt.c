/*
 * DEI.c
 *
 *  Created on: Jan 30, 2018
 *      Author: Mohamed Waleed
 */

#include "utilss.h"
#include "Types.h"
#include "DigExtInt.h"
#include "DIO.h"


/******************************************************************
 * define pointers for each Register accessed by This Module
 ******************************************************************/
#define SREG *((volatile u8*) 0x5F)
#define GICR *((volatile u8*) 0x5B)
#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)

/******************************************************************
 * define High Value and Low value
 * instead of using magic numbers
 * that are not allowed in readable SW
 ******************************************************************/

#define HIGH 1
#define LOW 0

/******************************************************************
 * prototypes of the Private Functions
 ******************************************************************/
void __vector_1 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_2 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_3 (void)  __attribute__((signal,__INTR_ATTRS));


/******************************************************************
 * Digital External Interrupt initialization function which initialize
 * peripheral Registers with the value of the header file
 ******************************************************************/

extern void DEI_voidInit(void)
{
	/*Enable Global INterrupt */
	assign_bit(SREG,7,HIGH);

#if INT0 == Enable

	assign_bit(GICR,6,HIGH);
	assign_bit(MCUCR,ISC00_bit,ISC00);
	assign_bit(MCUCR,ISC01_bit,ISC01);

#endif

#if INT1 == Enable

	assign_bit(GICR,7,HIGH);
	assign_bit(MCUCR,ISC10_bit,ISC10);
	assign_bit(MCUCR,ISC11_bit,ISC11);

#endif

#if INT2 == Enable

	assign_bit(GICR,5,HIGH);
	assign_bit(MCUCSR,ISC2_bit,ISC2);

#endif

}

/*******************************************************************
 * ISR Function of External Digital Interrupt 0
 *******************************************************************/
void __vector_1	 (void)
{
	DIO_voidWritePIN(DIO_u8PinA0,DIO_u8HIGH);
}

/*******************************************************************
 * ISR Function of External Digital Interrupt 1
 *******************************************************************/

void __vector_2 (void)
{
	DIO_voidWritePIN(DIO_u8PinA0,DIO_u8LOW);

}


/*******************************************************************
 * ISR Function of External Digital Interrupt 2
 *******************************************************************/

void __vector_3 (void)
{

}
