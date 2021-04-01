/*
 * i2c.h
 *
 *  Created on: Jan 12, 2020
 *      Author: M_WA
 */

#ifndef I2C_H_
#define I2C_H_

void I2C_Init();
void I2C_Start();
void I2C_Write_ADD(unsigned char ADDr );
void I2C_WriteData(unsigned char data);
void I2C_Stop();


#endif /* I2C_H_ */
