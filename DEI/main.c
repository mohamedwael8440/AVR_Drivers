/*
 * main.c

 *
 *  Created on: Aug 26, 2019
 *      Author: Wael
 */
#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"
#include "DEI.h"




void main (void)

{

DIO_vidSetPinDir(a,pin0,output);
DIO_vidWritePinValue(d,pin2,high);
DIO_vidWritePinValue(d,pin3,high);

DEI_vidInit();
while(1)
{

}


}


