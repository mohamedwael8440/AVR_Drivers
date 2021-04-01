/*
 * scheduler.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Wael
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

void os_vidCreateTask(u8 Tpriority,u16  Tprodicity , void (*Tptr)(void));
void os_vidScheduler(void);
void os_vidStartScheduler(void);



#endif /* SCHEDULER_H_ */
