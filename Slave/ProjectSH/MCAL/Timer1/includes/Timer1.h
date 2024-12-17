/*
 * Timer1.h
 *
 * Created: 2/8/2023 1:25:33 PM
 *  Author: Ahmed Dia
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "BitMath.h"
#include "Timer1_HW.h"
#include "STD_Types.h"

#define TOP (2499u)
#define Min (65u)
#define Max (300u)

void Timer1_init(void);
void Timer1_start(void);
void Timer1_stop(void);




#endif /* TIMER1_H_ */