/*
 * ADC_Types.h
 *
 * Created: 12/25/2022 1:51:31 PM
 *  Author: Ahmed Dia
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

#include "STD_Types.h"

typedef enum{
	ADC_CHANNEL0 = 0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
}ADC_Channels;

typedef struct{
	Uint8 MUX0:1;
	Uint8 MUX1:1;
	Uint8 MUX2:1;
	Uint8 MUX3:1;
	Uint8 MUX4:1;
	Uint8 ADLAR_:1;
	Uint8 REFS0_:1;
	Uint8 REFS1_:1;
}ADC_ADMUXBits;

typedef union{
	Uint8 AllReg;
	ADC_ADMUXBits Bits;
}ADC_ADMUX_REG;

typedef struct{
	Uint8 ADPS0_:1;
	Uint8 ADPS1_:1;
	Uint8 ADPS2_:1;
	Uint8 ADIE_:1;
	Uint8 ADIF_:1;
	Uint8 ADATE_:1;
	Uint8 ADSC_:1;
	Uint8 ADEN_:1;
}ADC_ADCSRABits;

typedef union{
	Uint8 AllReg;
	ADC_ADCSRABits Bits;
}ADC_ADCSRA_REG;

typedef struct{
	Uint8 RESERVED:5;
	Uint8 ADTS0_:1;
	Uint8 ADTS1_:1;
	Uint8 ADTS2_:1;
}ADC_SFIORBits;

typedef union{
	Uint8 AllReg;
	ADC_SFIORBits Bits;
}ADC_SFIOR_REG;

typedef struct {
	Uint8 ADCL_;
	Uint8 ADCH_;
	ADC_ADCSRA_REG ADCSRA_;
	ADC_ADMUX_REG ADMUX_;
	Uint8 RESERVED[27];
	ADC_SFIOR_REG SFIOR_;
}ADC_Reg;



#endif /* ADC_TYPES_H_ */