/*
 * Motor.c
 *
 * Created: 2/9/2023 2:54:57 PM
 *  Author: Ahmed Dia
 */ 

#include "Motor.h"
#include "DIO.h"

void Motor_init(const PWM_configType * config_Ptr){
	PWM_init(config_Ptr);
}
void Motor_speed(const PWM_configType * config_Ptr,Uint8 a_duty){
	PWM_changeDuty(config_Ptr,a_duty);
}

void Motor_set_dir(Uint8 Channel,Uint8 Level){
	DIO_WriteChannel(Channel, Level);
}





