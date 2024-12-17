/*
 * Buzzer.c
 *
 * Created: 12/20/2022 2:56:30 PM
 *  Author: Ahmed Dia
 */ 
#include "Buzzer.h"


void Buz_DIR_OUT(Uint8 portname,Uint8 TYPE){
	DIO_ConfigureChannel(portname,TYPE);
}
void Buz_TurnOn(Uint8 portname){
	DIO_WriteChannel(portname, STD_High);
}
void Buz_TurnOff(Uint8 portname){
	DIO_WriteChannel(portname, STD_Low);
}
void Buz_Toggle(Uint8 portname){
	DIO_TOGChannel(portname);
}