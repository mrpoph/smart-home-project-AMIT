/*
 * APP.h
 *
 * Created: 2/21/2023 12:19:40 PM
 *  Author: Ahmed Dia
 */ 


#ifndef APP_H_
#define APP_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "Clock.h"
#include "LCD.h"
#include "LED.h"
#include "MAIN_CONFIG.h"
#include "SPI.h"
#include "Timer.h"
#include "LM35.h"
#include "Motor.h"
#include "Servo.h"
#include "pwm.h"

void APP_Init(void);
void APP_Start(void);



#endif /* APP_H_ */