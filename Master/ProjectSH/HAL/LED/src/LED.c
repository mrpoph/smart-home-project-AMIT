/*
 * LED.c
 *
 * Created: 12/15/2022 2:07:54 PM
 *  Author: Ahmed Dia
 */ 

#include "LED.h"


void LED_DIR_OUT(Uint8 portname,Uint8 TYPE){
	DIO_ConfigureChannel(portname,TYPE);
}
void LED_TurnOn(Uint8 portname){
	DIO_WriteChannel(portname, STD_High);
}
void LED_TurnOff(Uint8 portname){
	DIO_WriteChannel(portname, STD_Low);
}
void LED_Toggle(Uint8 portname){
	DIO_TOGChannel(portname);
}
Uint8 LED_ReadStatus(Uint8 portname){
	Uint8 State = DIO_ReadChannel(portname);
	return State;
}