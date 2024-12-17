/*
 * LM35.c
 *
 * Created: 12/25/2022 5:01:44 PM
 *  Author: Ahmed Dia
 */ 
#include "LM35.h"

void LM35_Init(){
	ADC_Init();
}
int16 LM35_Read(ADC_Channel_Type ChannelId){
	int16 temp = 0;
	temp = ADC_Read(ChannelId);
	temp /= 4;
	return temp;
}