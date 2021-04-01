/*
 * UART.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"

#define URSEL 7
#define USBS 3
#define UCSZ1 2

u8 UCSRC_value=0
;
void USART_vidInit(void)
{
	Set_Bit(UCSRB,4); //EN RX
	Set_Bit(UCSRB,3); //EN TX
	Clr_Bit(UCSRB,2); // 8 BIT

	//select ucsrc lazm a write  directly maynfa3ash setbit 3alatol 3ashn eselect fa ha7atahom fa variable w 2a7atahom mara wa7da fel reg
Set_Bit(UCSRC_value,URSEL);// select ucsrc
// select char size 8 bit
Set_Bit(UCSRC_value,UCSZ1);
Set_Bit(UCSRC_value,1);
// setting ucsrc
UCSRC_UBRRH=UCSRC_value;
// set 9600 bps
UBRRL=51;

}
void USART_vidTransmit(u8 data)
{
	while(Get_Bit(UCSRA,5)==0)
	{
	}
	UDR=data;
	// b3d kda shof el transmit complete

}
u8 USART_u8Receive(void)
{ // check on recieve complete flag
while(Get_Bit(UCSRA,7)==0)
{
}
return UDR;
}

void USART_vidSendstring(u8 *str)
{
	u8 i=0;
	while(str[i]!='\0') // 2a5er element dayman fel array of strings chrs '\0' ,array of char " "
	{
	 USART_vidTransmit(str[i]);
			 i++;
	}
}
