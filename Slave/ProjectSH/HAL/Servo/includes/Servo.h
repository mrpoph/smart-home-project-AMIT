/*
 * Servo.h
 *
 * Created: 2/9/2023 9:34:53 PM
 *  Author: Ahmed Dia
 */ 


#ifndef SERVO_H_
#define SERVO_H_


#include "DIO.h"
#include "Timer1.h"


void Servo_init(void);
void Servo_Open(void);
void Servo_Close(void);
//void Servo_Stop(void);



#endif /* SERVO_H_ */