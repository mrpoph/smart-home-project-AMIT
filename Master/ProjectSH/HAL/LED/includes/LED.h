/*
 * LED.h
 *
 * Created: 12/15/2022 2:07:40 PM
 *  Author: Ahmed Dia
 */ 


#ifndef LED_H_
#define LED_H_
#include "STD_Types.h"
#include "DIO.h"

void LED_DIR_OUT(Uint8 portname,Uint8 TYPE);
void LED_TurnOn(Uint8 portname);
void LED_TurnOff(Uint8 portname);
void LED_Toggle(Uint8 portname);
Uint8 LED_ReadStatus(Uint8 portname);

#define ADMIN_LED_PORT DIO_ChannelC5
#define GUEST_LED_PORT DIO_ChannelC6
#define NO_MODE_PORT DIO_ChannelC7
#define Access_LED_PORT DIO_ChannelC3
#define Bluetooth_LED_PORT DIO_ChannelC2


#endif /* LED_H_ */