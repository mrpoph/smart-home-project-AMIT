/*
 * LM35.h
 *
 * Created: 12/25/2022 5:01:34 PM
 *  Author: Ahmed Dia
 */ 


#ifndef LM35_H_
#define LM35_H_


#include "ADC.h"

void LM35_Init();
int16 LM35_Read(ADC_Channels ChannelId);


#endif /* LM35_H_ */