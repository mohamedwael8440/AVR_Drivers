/*
 * watchdog.c
 *
 *  Created on: Oct 5, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"

#define WDT_refresh() __asm__ __volatile__("wdr")

void WDT_vidinit(void)
{
	WDTCR=0b00001110;

}

void WDT_vidRefresh(void)
{
	WDT_refresh();
}
