/*
 * utilites.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Wael
 */

#ifndef UTILITES_H_
#define UTILITES_H_

#define set_bit(reg,bitn) reg |=(1<<bitn)
#define clr_bit(reg,bitn) reg &=(~(1<<bitn))
#define get_bit(reg,bitn) (reg&((1<<bitn))>>bitn)

#define set_port(reg) reg =0b11111111
#define clr_port(reg) reg =0b00000000

#endif /* UTILITES_H_ */
