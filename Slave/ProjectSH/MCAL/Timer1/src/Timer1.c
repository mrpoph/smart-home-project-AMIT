/*
 * Timer.c
 *
 * Created: 11/19/2022 10:15:58 AM
 *  Author: Ahmed Dia
 */ 

#include "Timer1.h"
#include "Timer1_HW.h"
#include "STD_Types.h"
#include "avr/io.h"
#include <stdlib.h>



void Timer1_init(void){
	
	//SetBit(TCCR1A, WGM11);
	//SetBit(TCCR1B, WGM12);
	//SetBit(TCCR1B, WGM13);
	//SetBit(TCCR1A, COM1A1);
	
	//ICR1_H = (TOP && 0xFF00) >> 8;
	//ICR1_L = (TOP && 0x00FF);
	
	//TCNT1 = 0;
	
	//OCR1A_H = (Max && 0xFF00) >> 8;
	//OCR1A_L = (Max && 0x00FF);
	
	//SetBit(TCCR1B, CS11);
	//SetBit(TCCR1B, CS10);
	//SetBit(TCCR1A_Reg, TCCR1A_WGM11_BIT);  //								//
	//SetBit(TCCR1B_Reg, TCCR1B_WGM12_BIT);  //	Set Fast PWM (TOP ICR1)		//
	//SetBit(TCCR1B_Reg, TCCR1B_WGM13_BIT);  //****						****//
	//
	//SetBit(TCCR1A_Reg, TCCR1A_COM1A1_BIT);	//Clear OC1A on compare match
	
	//ICR1_Reg = TOP; // FPWM=50hz (T=20ms	)
	//TCNT1_Reg = 0;
	//SetBit(TCCR1B_Reg, TCCR1B_CS11_BIT);
	//OCR1A_Reg = Max;
	
	
	DDRD |= (1<<PORTD5);	/* Make OC1A pin as output */
	TCNT1 = 0;			/* Set timer1 count zero */
	ICR1 = 4999;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13);

	OCR1A = 375;		/* Set servo shaft at -90° position */

	//375 0
	//500 90
	//250 -90
	
}

void Timer1_90(void){
	
	OCR1A_Reg = 500;
	SetBit(TCCR1B_Reg, TCCR1B_CS11_BIT);
	SetBit(TCCR1B_Reg, TCCR1B_CS10_BIT);

}

void Timer1_0(void){
	OCR1A_Reg = 375;
}
void Timer1_stop(void){
	ClearBit(TCCR1B_Reg, TCCR1B_CS11_BIT);
	ClearBit(TCCR1B_Reg, TCCR1B_CS10_BIT);
}