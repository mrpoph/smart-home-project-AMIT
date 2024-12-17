/*
 * LED.h
 *
 * Created: 12/15/2022 2:07:40 PM
 *  Author: Ahmed Dia
 */ 


#ifndef LED_H_
#define LED_H_
#include "STD_Types.h"

void LED_DIR_OUT(Uint8 portname,Uint8 TYPE);
void LED_TurnOn(Uint8 portname);
void LED_TurnOff(Uint8 portname);
void LED_Toggle(Uint8 portname);
Uint8 LED_ReadStatus(Uint8 portname);

#define ROOM1_LED DIO_ChannelC0
#define ROOM2_LED DIO_ChannelC1
#define ROOM3_LED DIO_ChannelC2
#define ROOM4_LED DIO_ChannelC3
#define ROOM5_LED DIO_ChannelC4
#define Dimmer_LED DIO_ChannelB3
#define AC_LED DIO_ChannelA1




#endif /* LED_H_ */