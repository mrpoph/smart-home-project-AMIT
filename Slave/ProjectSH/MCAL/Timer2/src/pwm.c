/*
 * pwm.c
 *
 * Created: 2/3/2023 4:23:26 PM
 *  Author: Ahmed Dia
 */ 


#include "pwm.h"

Uint8  g_initialCount_T0 = 0;
Uint16 g_initialCount_T1 = 0;
Uint8  g_initialCount_T2 = 0;

Uint8 g_OCR0;
Uint8 g_OCR1;
Uint8 g_OCR2;

void PWM_init(const PWM_configType * config_Ptr)
{
	if((config_Ptr->whichTimer) == TIMER_0)
	{
		SetBit(DDRB,PB3);
		TCNT0 = g_initialCount_T0;
		OCR0  = g_OCR0;
		SetBit(TCCR0,WGM01);
		SetBit(TCCR0,WGM00);
		TCCR0 = (TCCR0 & 0xCF) | ((config_Ptr->mode)<<4);
		TCCR0 = (TCCR0 & 0xF8) | (config_Ptr->clock);
		SetBit(TIMSK,TOIE0);
	}
	else if((config_Ptr->whichTimer) == TIMER_1)
	{

	}
	else if((config_Ptr->whichTimer) == TIMER_2)
	{
		SetBit(DDRD,PB7);
		TCNT2 = g_initialCount_T2;
		OCR2  = g_OCR2;
		SetBit(TCCR2,WGM21);
		SetBit(TCCR2,WGM20);
		TCCR2 = (TCCR2 & 0xCF) | ((config_Ptr->mode)<<4);
		TCCR2 = (TCCR2 & 0xF8) | (config_Ptr->clock);
		SetBit(TIMSK,OCIE2);
		
	}
}

void PWM_changeDuty(const PWM_configType * config_Ptr,Uint8 a_duty)
{
	if((config_Ptr->whichTimer) ==TIMER_0)
	{
		OCR0 = a_duty;
	}
	else if((config_Ptr->whichTimer) ==TIMER_1)
	{

	}
	else if((config_Ptr->whichTimer) ==TIMER_2)
	{
		OCR2 = a_duty;
	}
}

void PWM_TurnOff(){
	ClearBit(TCCR0,CS00);
	ClearBit(TCCR0,CS01);
	ClearBit(TCCR0,CS02);
}