/*
 * Timer.c
 *
 * Created: 11/19/2022 10:15:58 AM
 *  Author: Ahmed Dia
 */ 

#include "Timer.h"
#include "Timer_HW.h"
#include "Timer_Types.h"
#include "STD_Types.h"

void Timer_mode_Sel(Timer_Modes mode){
	
	switch (mode)
	{	
		case Normal_mode:
			ClearBit(TCCR0_Reg,TCCR0_WGM00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_WGM01_BIT);
			break;
		case PWM_PC:
			SetBit(TCCR0_Reg,TCCR0_WGM00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_WGM01_BIT);
			break;
		case CTC:
			ClearBit(TCCR0_Reg,TCCR0_WGM00_BIT);
			SetBit(TCCR0_Reg,TCCR0_WGM01_BIT);
			break;
		case Fast_PWM:
			SetBit(TCCR0_Reg,TCCR0_WGM00_BIT);
			SetBit(TCCR0_Reg,TCCR0_WGM01_BIT);
			break;
	}
}

void Clk_Sel(Prescaller scale){
	
	switch(scale){
		case Timer_off:
			ClearBit(TCCR0_Reg,TCCR0_CS00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS01_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case No_prescalling:
			SetBit(TCCR0_Reg,TCCR0_CS00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS01_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case scale_8:
			ClearBit(TCCR0_Reg,TCCR0_CS00_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS01_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case scale_64:
			SetBit(TCCR0_Reg,TCCR0_CS00_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS01_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case scale_256:
			ClearBit(TCCR0_Reg,TCCR0_CS00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS01_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case scale_1024:
			SetBit(TCCR0_Reg,TCCR0_CS00_BIT);
			ClearBit(TCCR0_Reg,TCCR0_CS01_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case EC_Fall_edge:
			ClearBit(TCCR0_Reg,TCCR0_CS00_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS01_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
		case EC_rising_edge:
			SetBit(TCCR0_Reg,TCCR0_CS00_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS01_BIT);
			SetBit(TCCR0_Reg,TCCR0_CS02_BIT);
			break;
	}
}

void Timer_init_val(Uint8 num){
	TCCR0_Reg = num;
}

void OCR_val(Uint8 Compare_num){
	OCR0_Reg = Compare_num;
}

void Timer_interrupt_enable(interrupt_activation interrupt_enable){
	
	if(interrupt_enable >= 0 && interrupt_enable <= 3){
		
		switch(interrupt_enable){
			case interrupt_disabled:
				ClearBit(TIMSK_Reg, TIMSK_OCIE0_BIT);
				ClearBit(TIMSK_Reg, TIMSK_TOIE0_BIT);
				break;
			case overflow_interrupt:
				ClearBit(TIMSK_Reg, TIMSK_OCIE0_BIT);
				SetBit(TIMSK_Reg, TIMSK_TOIE0_BIT);
				break;
			case OCR_interrupt:
				SetBit(TIMSK_Reg, TIMSK_OCIE0_BIT);
				ClearBit(TIMSK_Reg, TIMSK_TOIE0_BIT);
				break;
			case both_interrupts:
				SetBit(TIMSK_Reg, TIMSK_OCIE0_BIT);
				SetBit(TIMSK_Reg, TIMSK_TOIE0_BIT);
				break;
		}
	}
	else{
		//do nothing
	}
}
/*
Uint8 freq_to_OCR(int16 freq, Prescaller scale){
	Uint8 OCR_res = 0;
	int16 N = 1;
	switch(scale){
		case scale_8:
		N = 8;
		break;
		case scale_64:
		N = 64;
		break;
		case scale_256:
		N = 256;
		break;
		case scale_1024:
		N = 1024;
		break;
	}
	OCR_res = (1/2*N*freq) - 1;
	return OCR_res;	//Required OCR Value for the freq
}
*/
/*
Uint8 CTC_Duty(int freq, Uint8 duty ,Prescaller scale,char count_duty){
	Uint8 OCR_res = 0;
	int N = 1;
	switch(scale){
		case scale_8:
		N = 8;
		break;
		case scale_64:
		N = 64;
		break;
		case scale_256:
		N = 256;
		break;
		case scale_1024:
		N = 1024;
		break;
	}
	
	OCR_res = (1/2*N*freq) - 1;
	
	Uint8 section1 = OCR_res * (duty/100);
	Uint8 section2 = OCR_res - section1;
	
	if(count_duty == 0){
		return section1;
	}
	else if(count_duty == 1){
		return section2;
	}
	
}
*/
void pulse_output(Uint8 num){
	
		switch(num){
			case 0:
				ClearBit(TCCR0_Reg, TCCR0_COM00_BIT);
				ClearBit(TCCR0_Reg, TCCR0_COM01_BIT);
				break;
			case 1:
				SetBit(TCCR0_Reg, TCCR0_COM00_BIT);
				ClearBit(TCCR0_Reg, TCCR0_COM01_BIT);
				break;
			case 2:
				ClearBit(TCCR0_Reg, TCCR0_COM00_BIT);
				SetBit(TCCR0_Reg, TCCR0_COM01_BIT);
				break;
			case 3:
				SetBit(TCCR0_Reg, TCCR0_COM00_BIT);
				SetBit(TCCR0_Reg, TCCR0_COM01_BIT);
				break;
		}
	
}