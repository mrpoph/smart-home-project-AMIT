/*
 * Keypad.h
 *
 * Created: 11/11/2022 9:28:52 PM
 *  Author: Ahmed Dia
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define NOT_PRESSED 0

#define r0 DIO_ChannelC0
#define r1 DIO_ChannelC1
#define r2 DIO_ChannelD2
#define r3 DIO_ChannelD3

#define c0 DIO_ChannelD4
#define c1 DIO_ChannelD5
#define c2 DIO_ChannelD6
#define c3 DIO_ChannelD7


Uint8 GetKeyPress(void);



#endif /* KEYPAD_H_ */