/*
 * ADC.h
 *
 * Created: 12/25/2022 1:33:41 PM
 *  Author: Ahmed Dia
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Clock.h"
#include "STD_Types.h"
#include "ADC_HW.h"
#include "BitMath.h"
#include "ADC_Types.h"


void ADC_Init(void);
int16 ADC_Read(ADC_Channel_Type ChannelId);


#endif /* ADC_H_ */