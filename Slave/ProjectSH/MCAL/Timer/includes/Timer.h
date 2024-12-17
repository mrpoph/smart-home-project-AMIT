/*
 * Timer.h
 *
 * Created: 11/19/2022 10:16:15 AM
 *  Author: Ahmed Dia
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "BitMath.h"
#include "Timer_HW.h"
#include "Timer_Types.h"
#include "STD_Types.h"

void Timer_mode_Sel(Timer_Modes mode);
void Clk_Sel(Prescaller scale);
void Timer_init_val(Uint8 num);
void OCR_val(Uint8 Compare_num);
void Timer_interrupt_enable(interrupt_activation interrupt_enable);
void pulse_output(Uint8 num);
Uint8 CTC_Duty(int16 freq,Uint8 duty,Prescaller scale,char count_duty);
//Uint8 freq_to_OCR(int16 freq, Prescaller scale);
	

#endif /* TIMER_H_ */