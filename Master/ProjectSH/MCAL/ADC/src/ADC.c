/*
 * ADC.c
 *
 * Created: 12/25/2022 1:33:29 PM
 *  Author: Ahmed Dia
 */ 
#include "../include/ADC.h"

void ADC_Init(void){
	ADC->ADMUX_.Bits.REFS0_ = STD_High;	//VREF = 2.56v
	ADC->ADMUX_.Bits.REFS1_ = STD_High;
	ADC->ADMUX_.Bits.ADLAR_ = STD_Low;
	/* ******************************** */
	ADC->ADCSRA_.Bits.ADEN_ = STD_High;	// ADC Enable
	//ADC->ADCSRA_.Bits.ADIE_ = STD_High;	// Interrupt Enable
	ADC->ADCSRA_.Bits.ADPS0_ = STD_High;	/* ******************** */
	ADC->ADCSRA_.Bits.ADPS1_ = STD_High;	//      F_CPU/128       //
	ADC->ADCSRA_.Bits.ADPS2_ = STD_High;	/* ******************** */
}
int16 ADC_Read(ADC_Channels ChannelId){
	int16 Temp_value = 0;
	ADC->ADMUX_.AllReg = ((ADC->ADMUX_.AllReg & 0xE0) | (ChannelId & 0x07));	// xxxx x111
	ADC->ADCSRA_.Bits.ADSC_ = STD_High;
	while(GetBit(ADC->ADCSRA_.AllReg, ADC->ADCSRA_.Bits.ADIF_) == 0);
	Temp_value = ADC->ADCL_;
	Temp_value |= (ADC->ADCH_ << 8);
	return Temp_value;
}