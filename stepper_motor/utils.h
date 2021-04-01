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
#define toggle_Bit(reg,bitno) reg^=(1<<bitno) //xor 1 make it 0


#endif /* UTILS_H_ */
