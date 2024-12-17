/*
 * Timer_HW.h
 *
 * Created: 11/19/2022 10:16:27 AM
 *  Author: Ahmed Dia
 */ 


#ifndef TIMER_HW_H_
#define TIMER_HW_H_

#include "STD_Types.h"

#define TCCR0_Reg (*(volatile Uint8 *)0x53)
#define TCNT0_Reg (*(volatile Uint8 *)0x52)
#define OCR0_Reg (*(volatile Uint8 *)0x5C)
#define TIMSK_Reg (*(volatile Uint8 *)0x59)

#define TCCR0_WGM00_BIT (6)	// Mode selection
#define TCCR0_WGM01_BIT (3)	// Mode selection

#define TCCR0_CS00_BIT  (0)	//*****************************//
#define TCCR0_CS01_BIT  (1)	//	Clock Select (Prescaling)  //
#define TCCR0_CS02_BIT	(2)	//*****************************//

#define TIMSK_OCIE0_BIT (0)	//Compare Interrupt enable
#define TIMSK_TOIE0_BIT (1)	//OverFlow Interrupt enable

#define TCCR0_COM00_BIT (4)	
#define TCCR0_COM01_BIT (5)	


#endif /* TIMER_HW_H_ */