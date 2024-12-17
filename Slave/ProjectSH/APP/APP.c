/*
 * APP.c
 *
 * Created: 2/21/2023 12:19:50 PM
 *  Author: Ahmed Dia
 */ 
#include "APP.h"

Uint8 Door_state = 0;
Uint8 dimmer_state =0;
Uint8 duty = 0;	//Dimmer duty
int8 count = 0;	//Dimmer ISR 0.5s Counter

volatile Uint8 Active_temperature = 28; // the required temperature which sent from Master with initial value 24
volatile Uint8 Disabled_temperature = 21;
volatile Uint16 temp_sensor_reading = 0; // the temperature of the room
volatile Uint8 counter = 0; // the counter which determine the periodic time of implementing ISR
volatile Uint8 last_air_conditioning_value = AIR_CONDTIONING_OFF; // last air conditioning value which will help in hysteresis

PWM_configType _config = {TIMER_0,CLEAR_OC0,F_CPU_1024};
Uint8 request = Default_Ack; //the value that is received from the master

void APP_Init(void){
	/* *********************** INITIALIZATIONS ******************************* */
	SPI_InitType options = {SLAVE};
	DIO_Init();
	LCD_Init();
	LM35_Init();
	SPI_Init(options);
	Servo_init();
	/* ********************************  ************************************* */
	LED_DIR_OUT(ROOM1_LED,Output);
	LED_DIR_OUT(ROOM2_LED,Output);
	LED_DIR_OUT(ROOM3_LED,Output);
	LED_DIR_OUT(ROOM4_LED,Output);
	LED_DIR_OUT(ROOM5_LED,Output);
	LED_DIR_OUT(Dimmer_LED,Output);
	LED_DIR_OUT(AC_LED,Output);
	/* ********************************  ************************************* */
	
	PWM_configType Motor_config = {TIMER_2,CLEAR_OC0,F_CPU_1024};
	Motor_init(&Motor_config);
	Motor_speed(&Motor_config,125);
	sei();
	
	/* ********************************  ************************************* */
}
void APP_Start(void){
	request = SPI_TxRx(Default_Ack);
	
	switch(request){
		case ROOM1:
		if(LED_ReadStatus(ROOM1_LED) == 1){
			LCD_Clear();
			LED_TurnOff(ROOM1_LED);
			break;
		}
		else if(LED_ReadStatus(ROOM1_LED) == 0){
			LCD_Clear();
			LED_TurnOn(ROOM1_LED);
			break;
		}
		else{
			//Nothing
		}
		case ROOM2:
		if(LED_ReadStatus(ROOM2_LED) == 1){
			LCD_Clear();
			LED_TurnOff(ROOM2_LED);
			break;
		}
		else if(LED_ReadStatus(ROOM2_LED) == 0){
			LCD_Clear();
			LED_TurnOn(ROOM2_LED);
			break;
		}
		else{
			//Nothing
		}
		
		case ROOM3:
		if(LED_ReadStatus(ROOM3_LED) == 1){
			LCD_Clear();
			LED_TurnOff(ROOM3_LED);
			break;
		}
		else if(LED_ReadStatus(ROOM3_LED) == 0){
			LCD_Clear();
			LED_TurnOn(ROOM3_LED);
			break;
		}
		else{
			//Nothing
		}
		
		case ROOM4:
		if(LED_ReadStatus(ROOM4_LED) == 1){
			LCD_Clear();
			LED_TurnOff(ROOM4_LED);
			break;
		}
		else if(LED_ReadStatus(ROOM4_LED) == 0){
			LCD_Clear();
			LED_TurnOn(ROOM4_LED);
			break;
		}
		else{
			//Nothing
		}
		
		case ROOM5:
		if(LED_ReadStatus(ROOM5_LED) == 1){
			LCD_Clear();
			LED_TurnOff(ROOM5_LED);
			break;
		}
		else if(LED_ReadStatus(ROOM5_LED) == 0){
			LCD_Clear();
			LED_TurnOn(ROOM5_LED);
			break;
		}
		else{
			//Nothing
			break;
		}
		
		case Dimmer:
		if(dimmer_state == 0){
			PWM_init(&_config);
			dimmer_state++;
		}
		else{
			PWM_TurnOff();
			dimmer_state = 0;
		}
		break;

		case AC:
		if(LED_ReadStatus(AC_LED) == 1){
			LCD_Clear();
			LED_TurnOff(AC_LED);
			break;
		}
		else if(LED_ReadStatus(AC_LED) == 0){
			LCD_Clear();
			LED_TurnOn(AC_LED);
			break;
		}
		else{
			//Nothing
		}
		break;
		
		case DOOR:
		
		if(Door_state == 0){
			Servo_Open();
			Door_state = 1;
		}
		else {
			Servo_Close();
			Door_state = 0;
		}
		
		break;
		
		
	}
}


ISR(TIMER0_OVF_vect){
	count++;
	Uint8 dudd[10];
	if(count == 30){
		duty = ADC_Read(ADC_CHANNEL2);
		PWM_changeDuty(&_config, duty);
		count =0;
	}
	itoa(duty,dudd,10);
}

ISR(TIMER2_COMP_vect)
{
	Uint16 temp[20];
	counter++;	//count the ticks of the timer zero
	if(counter >= 61) //do that code every 1 sec (61 ticks with 1024 prescaler)
	{
		counter=0;//clear the counter of ticks
		
		LCD_String("Temp; ");
		temp_sensor_reading = LM35_Read(ADC_CHANNEL0);
		itoa(temp_sensor_reading,temp,10);
		LCD_String(temp);
		_delay_ms(200);
		LCD_Clear();
		
		if ((temp_sensor_reading >= Active_temperature) && LED_ReadStatus(AC_LED) == 1)//do that code if the read temperature if greater than required temperature by one or more
		{
			
			Motor_set_dir(MotorPin1,STD_Low);
			Motor_set_dir(MotorPin2,STD_High);

			last_air_conditioning_value = AIR_CONDTIONING_ON; //save the value of the state of the air conditioning
		}
		else if (temp_sensor_reading <= Disabled_temperature) //do that code if the read temperature if lesser than required temperature by one or more
		{
			
			last_air_conditioning_value = AIR_CONDTIONING_OFF; //save the value of the state of the air conditioning
			Motor_set_dir(MotorPin1,STD_Low);
			Motor_set_dir(MotorPin2,STD_Low);
		}
		else if ((temp_sensor_reading >= Disabled_temperature && temp_sensor_reading <= Active_temperature) && LED_ReadStatus(AC_LED) == 1){	//do that code if the read temperature is equal to the required temperature
			
			if (last_air_conditioning_value == AIR_CONDTIONING_ON){	//in the case of the last saved status of the air conditioning was on
				Motor_set_dir(MotorPin1,STD_Low);
				Motor_set_dir(MotorPin2,STD_High);
			}
			else if (last_air_conditioning_value == AIR_CONDTIONING_OFF){	//in the case of the last saved status of the air conditioning was off
				
				Motor_set_dir(MotorPin1,STD_Low);
				Motor_set_dir(MotorPin2,STD_Low);
			}
		}
		else if (LED_ReadStatus(AC_LED) == 0){
			Motor_set_dir(MotorPin1,STD_Low);
			Motor_set_dir(MotorPin2,STD_Low);
		}
	}
}
