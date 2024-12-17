/*
 * Servo.c
 *
 * Created: 2/9/2023 9:35:07 PM
 *  Author: Ahmed Dia
 */ 

#include "Servo.h"


void Servo_init(void){
	Timer1_init();
}
void Servo_Open(void){
	Timer1_90();
}

void Servo_Close(void){
	Timer1_0();
}