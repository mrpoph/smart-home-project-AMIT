/*
 * Timer1_HW.h
 *
 * Created: 2/8/2023 1:25:53 PM
 *  Author: Ahmed Dia
 */ 


#ifndef TIMER1_HW_H_
#define TIMER1_HW_H_


#include "STD_Types.h"

#define TCCR1A_Reg (*(volatile Uint8 *)0x4F)
#define TCCR1B_Reg (*(volatile Uint8 *)0x4E)

#define TCNT1_Reg (*(volatile Uint16 *)0x4C)	//H and L

#define OCR1A_Reg (*(volatile Uint16 *)0x4A)
#define OCR1B_Reg (*(volatile Uint16 *)0x48)

#define ICR1_Reg (*(volatile Uint16 *)0x46)

#define TIMSK_Reg (*(volatile Uint8 *)0x59)


#define TCNT1_L (*(volatile Uint8 *)0x4C)
#define TCNT1_H (*(volatile Uint8 *)0x4D)

#define OCR1A_L (*(volatile Uint8 *)0x4A)
#define OCR1A_H (*(volatile Uint8 *)0x4B)

#define ICR1_L (*(volatile Uint8 *)0x46)
#define ICR1_H (*(volatile Uint8 *)0x47)










#define TCCR1A_WGM10_BIT (0)
#define TCCR1A_WGM11_BIT (1)

#define TCCR1A_COM1A1_BIT (7)
#define TCCR1A_COM1A0_BIT (6)


#define TCCR1B_CS10_BIT (0)
#define TCCR1B_CS11_BIT (1)
#define TCCR1B_CS12_BIT (2)

#define TCCR1B_WGM12_BIT (3)
#define TCCR1B_WGM13_BIT (4)



#endif /* TIMER1_HW_H_ */