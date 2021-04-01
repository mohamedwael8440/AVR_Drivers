/*
 * i2c.h
 *
 *  Created on: Jan 12, 2020
 *      Author: M_WA
 */

#ifndef I2C_H_
#define I2C_H_
void I2C_slaveInit(unsigned char slave_add);
unsigned char I2C_ReadData();
void I2C_Match_ACK();


#endif /* I2C_H_ */
