/*
 * Motor.h
 *
 * Created: 2/9/2023 2:54:47 PM
 *  Author: Ahmed Dia
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "pwm.h"


#define MotorPin1 DIO_ChannelD0
#define MotorPin2 DIO_ChannelD1

void Motor_init(const PWM_configType * config_Ptr);
void Motor_speed(const PWM_configType * config_Ptr,Uint8 a_duty);
void Motor_set_dir(Uint8 Channel,Uint8 Level);




#endif /* MOTOR_H_ */