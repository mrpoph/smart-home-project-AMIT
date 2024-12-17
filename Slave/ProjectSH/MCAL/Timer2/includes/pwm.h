/*
 * pwm.h
 *
 * Created: 2/3/2023 4:23:12 PM
 *  Author: Ahmed Dia
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>


#include "STD_Types.h"
#include "BitMath.h"

/*******************************************************************************
 *                        External Variables                                   *
 *******************************************************************************/

extern Uint8 g_initialCount_T0;
extern Uint16 g_initialCount_T1;
extern Uint8 g_initialCount_T2;

extern Uint8 g_OCR0;
extern Uint8 g_OCR1;
extern Uint8 g_OCR2;

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum
{
	TIMER_0,TIMER_1,TIMER_2
}PWM_timerType;

typedef enum
{
	NORMAL_OC0_DISCONNECTED,REVERSED,CLEAR_OC0,SET_OC0
}PWM_modeType;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_CLOCK_FALLING,EXTERNAL_CLOCK_RISING
}PWM_ClockType;

typedef struct
{
	PWM_timerType whichTimer;
	PWM_modeType  mode;
	PWM_ClockType clock;
}PWM_configType;
/*******************************************************************************



































































368

 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_init(const PWM_configType * config_Ptr);
void PWM_changeDuty(const PWM_configType * config_Ptr, Uint8 a_duty);
void PWM_TurnOff(void);

#endif /* PWM_H_ */