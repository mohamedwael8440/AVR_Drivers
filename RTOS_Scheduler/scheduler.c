/*
 * scheduler.c
 *
 *  Created on: Oct 26, 2019
 *      Author: Wael
 */

#include "standardtypes.h"
#include "registers.h"
#include "DIO.h"
#include "utils.h"
#include  "SchedulerCfg.h"
#include "timer.h"

extern u32 counter;
typedef struct
{
	u16 periodicity;
	void (*fptr)(void);
}task;

task arr[nooFTasks];

void os_vidCreateTask(u8 Tpriority,u16  Tprodicity , void (*Tptr)(void)) // asm el function ma hwa 2ala awl pointer la awl instruction feha

{
	arr[Tpriority].periodicity=Tprodicity ;
	arr[Tpriority].fptr=Tptr ;

}
void os_vidScheduler(void)
{ u8 i;
  for(i=0;i<nooFTasks;i++)
  {
	  if(counter % arr[i].periodicity==0)//lw doraha nafazaha el hea el 7eta bata3at el common factor
	  {
		  arr[i].fptr(); //nafs el function
	  }
  }
}
void os_vidStartScheduler(void)
{
 timer_vidInit();
}
