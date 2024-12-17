/*
 * ADC_HW.h
 *
 * Created: 11/12/2022 8:31:39 PM
 *  Author: Ahmed Dia
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#include "STD_Types.h"

#define ADMUX_Reg (*(volatile Uint8 *)0x27)
#define ADCSRA_Reg (*(volatile Uint8 *)0x26)
#define ADCH_Reg (*(volatile Uint8 *)0x25)
#define ADCL_Reg (*(volatile Uint8 *)0x24)

#define ADMUX_REFS1_BIT (7)	//SET to 1
#define ADMUX_REFS0_BIT (6)	//SET to 1

#define ADCSRA_ADEN_BIT  (7)
#define ADCSRA_ADSC_BIT  (6)
#define ADCSRA_ADIF_BIT	 (4)
#define ADCSRA_ADIE_BIT	 (3)

#define ADCSRA_ADPS0_BIT (0)	//SET to 1
#define ADCSRA_ADPS1_BIT (1)	//SET to 1
#define ADCSRA_ADPS2_BIT (2)	//SET to 1



#endif /* ADC_HW_H_ */