/*
 * utils.h
 *
 *  Created on: 17Aug.,2019
 *      Author: Fahim
 */

#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(reg,bitno) reg|=(1<<bitno)
#define Clr_Bit(reg,bitno) reg&=(~(1<<bitno))
#define Get_Bit(reg,bitno) ((reg&(1<<bitno))>>bitno)

#define add(x,y)  x+y
#define sub(x,y)  x-y
#define mul(x,y)  x*y
#define div(x,y)  x/y





#endif /* UTILS_H_ */
