/*
 * Timer_Types.h
 *
 * Created: 11/19/2022 10:16:49 AM
 *  Author: Ahmed Dia
 */ 


#ifndef TIMER_TYPES_H_
#define TIMER_TYPES_H_

typedef enum {
	Normal_mode=0,
	PWM_PC,
	CTC,
	Fast_PWM
}Timer_Modes;

typedef enum {
	Timer_off = 0,
	No_prescalling,
	scale_8,
	scale_64,
	scale_256,
	scale_1024,
	EC_Fall_edge,
	EC_rising_edge
}Prescaller;

typedef enum {
	interrupt_disabled = 0,
	overflow_interrupt,
	OCR_interrupt,
	both_interrupts
}interrupt_activation;


#endif /* TIMER_TYPES_H_ */