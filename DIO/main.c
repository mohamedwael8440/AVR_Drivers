/*
 * main.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Wael
 */

#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "dio.h"


void main (void)

{
while(1)
{
	dio_vidPortDir(a,0b1111111);

    dio_vidSetPortValue(a ,0b1111111 );

    dio_vidWritePinDir(a,pin0,high);
}
}

