/*

 * DEI.h
 *
 *  Created on: Jan 30, 2018
 *      Author: Mohamed Waleed
 */

#ifndef DEI_H_
#define DEI_H_

/*******************************************************************
 * define value of Enable and disable
 * instead of using magic numbers
 * that are not allowed in the readable SW
 *******************************************************************/
#define Enable 1
#define Disable 0



/******************************************************************
 * Enable the Digital External interrupt that will be used in the SW
 *******************************************************************/
#define INT0 Enable
#define INT1 Disable
#define INT2 Disable



/******************************************************************
 * Configuration of INT0 in Case it is Enabled
 *****************************************************************/
#if INT0==Enable
	/*
	 * Set Trigger Request Reason or the reason of triggering the interrupt
	 */
	#define ISC00 0
	#define ISC01 1
	#define ISC00_bit 0
	#define ISC01_bit 1

#endif


/******************************************************************
 * Configuration of INT1 in Case it is Enabled
 *****************************************************************/
#if INT1==Enable
	//#define INT0_EN 1
	/*
	 * Set Trigger Request Reason or the reason of triggering the interrupt
	 */
	#define ISC10 0
	#define ISC11 1

	#define ISC10_bit 2
	#define ISC11_bit 3
#endif


/******************************************************************
 * Configuration of INT2 in Case it is Enabled
 *****************************************************************/

#if INT2==Enable
	//#define INT0_EN 1
	/*
	 * Set Trigger Request Reason or the reason of triggering the interrupt
	 */
	#define ISC2 0

	#define ISC2_bit 6
#endif

/******************************************************************
 * Public Functions Prototypes
 ******************************************************************/

extern void DEI_voidInit(void);



#endif /* DEI_H_ */
