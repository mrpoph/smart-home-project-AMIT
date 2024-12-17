/*
 * Buzzer.h
 *
 * Created: 12/20/2022 2:56:58 PM
 *  Author: Ahmed Dia
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
#include "STD_Types.h"
#include "DIO.h"

#define Buzzer DIO_ChannelC4

void Buz_DIR_OUT(Uint8 portname,Uint8 TYPE);
void Buz_TurnOn(Uint8 portname);
void Buz_Toggle(Uint8 portname);
void Buz_TurnOff(Uint8 portname);

#endif /* BUZZER_H_ */