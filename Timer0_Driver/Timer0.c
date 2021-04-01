/*
 * Timer0.c
 *
 *  Created on: Feb 10, 2018
 *      Author: Mohamed Waleed
 */



#include "STD_Types.h"
#include "utilss.h"
#include "Timer0.h"
#include "DIO.h"


/*
 * Addresses of the Registers
 */
#define TCCR0  *((volatile u8*) 0x53)
#define TCNT0  *((volatile u8*) 0x52)
#define OCR0  *((volatile u8*) 0x5C)
#define TIMSK  *((volatile u8*) 0x59)
#define TIFR  *((volatile u8*) 0x58)

#define DDRB *((volatile u8*)0x37)
#define SREG *((volatile u8*) 0x5F)

/*Private Variables*/
#if ((GI == 1) && (OverFlow_Mode==Enable))
	static u16 Timer0_NumOfOverflows=0;
#endif

#if ((GI == 1) && (CTC_Mode==Enable || PWM_Mode==Enable))
	static u16 Timer0_CTC_Counter=0;
#endif

/*
 * The ISR of the Overflow of Timer0 mode will be enabled
 * if Global interrupt bit is set to high and
 * if the overflow Interrupt enable bit is set to high in TIMSK
 */

#if ((GI == 1) && (OverFlow_Mode==Enable))
	#if TOIE0 == 1
		void __vector_11 (void)  __attribute__((signal,__INTR_ATTRS));
		void __vector_11 (void)
		{
			Timer0_NumOfOverflows++;
			if(Timer0_NumOfOverflows==46)
			{
				Timer0_NumOfOverflows=0;
				toggle_bit(PORTA,0);
			}
		}
	#endif
#endif
/*
 * the ISR of the Capture Match mode will be enabled
 *  if Global interrupt bit is set to high and
 * if the Capture Match Interrupt enable bit is set to high in TIMSK
 */
#if ((GI == 1) && (CTC_Mode==Enable || PWM_Mode ==Enable))
	#if OCIE0 == 1
		void __vector_10 (void)  __attribute__((signal,__INTR_ATTRS));
		void __vector_10 (void)
		{
			Timer0_CTC_Counter++;
			if(10000==Timer0_CTC_Counter)
			{
				toggle_bit(PORTA,0);
				Timer0_CTC_Counter=0;
			}

		}
	#endif
#endif


void Timer0_voidInit(void)
{

	#if GI == 1
		/*set the Global interrupt bit value*/
		assign_bit(SREG,GI_bit,GI);
	#endif

	/*fill the value of the TCCR0 Register according to the Configuration*/
	TCCR0 |= (FOC0 << FOC0_bit) | (WGM00 << WGM00_bit) | (COM01 << COM01_bit)
			| (COM00 << COM00_bit) | (WGM01 << WGM01_bit) | (CS02 << CS02_bit)
			| (CS01 << CS01_bit) | (CS00 << CS00_bit);

	/*fill the value of the TIMSK0 Register according to the Configuration*/
	#if ((OCIE0 == 1) && (CTC_Mode==Enable || PWM_Mode == Enable))
	OCR0=OCR0_Value;
	TIMSK |= (OCIE0<<OCIE0_bit);

	#endif

	#if ((TOIE0 == 1) && (OverFlow_Mode==Enable))
		TIMSK |= (TOIE0<<TOIE0_bit);
	#endif

}
