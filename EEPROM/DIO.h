

#ifndef DIO_H_
#define DIO_H_

#define a 0
#define b 1
#define c 2
#define d 3

#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7


#define output 1
#define input 0
#define high 1
#define low 0

 void DIOSetPortDirection (u8 portnumber, u8 value);
void DIOSetPortValue (u8 portnumber, u8 value);
void DIOSetPinDirection (u8 portnumber,u8 Pinnumber,u8 value);
void DIOSetPinValue (u8 portnumber,u8 Pinnumber,u8 value);
u8 DIOGetPinValue (u8 portnumber , u8 Pinnumber);

#endif /* DIO_H_ */
