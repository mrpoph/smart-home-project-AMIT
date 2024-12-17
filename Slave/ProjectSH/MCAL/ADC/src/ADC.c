/*
 * ADC.c
 *
 * Created: 11/12/2022 8:31:59 PM
 *  Author: Ahmed Dia
 */ 

#include "ADC.h"
#include "DIO.h"

void ADC_Init(void){
	SetBit(ADMUX_Reg, ADMUX_REFS0_BIT);
	SetBit(ADMUX_Reg, ADMUX_REFS1_BIT);
	
	SetBit(ADCSRA_Reg, ADCSRA_ADEN_BIT);
	SetBit(ADCSRA_Reg, ADCSRA_ADIE_BIT);
	
	SetBit(ADCSRA_Reg, ADCSRA_ADPS0_BIT);
	SetBit(ADCSRA_Reg, ADCSRA_ADPS1_BIT);
	SetBit(ADCSRA_Reg, ADCSRA_ADPS2_BIT);	
}

int16 ADC_Read(ADC_Channel_Type ChannelId){
	int16 Temp_value = 0;
	ADMUX_Reg =	(ADMUX_Reg & 0xE0) | (ChannelId & 0x1F);
	SetBit(ADCSRA_Reg , ADCSRA_ADSC_BIT);
	while(GetBit(ADCSRA_Reg, ADCSRA_ADIF_BIT) == 0);	//Wait until conversion is complete
	SetBit(ADCSRA_Reg , ADCSRA_ADIF_BIT);
	Temp_value = ADCL_Reg;
	Temp_value |= (ADCH_Reg << 8);
	return Temp_value;
}