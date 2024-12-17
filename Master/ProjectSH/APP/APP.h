/*
 * APP.h
 *
 * Created: 2/21/2023 12:33:00 PM
 *  Author: Ahmed Dia
 */ 


#ifndef APP_H_
#define APP_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Clock.h"
#include "EEPROM.h"
#include "LCD.h"
#include "Keypad.h"
#include "LED.h"
#include "Buzzer.h"
#include "Bluetooth.h"
#include "TWI.h"
#include "SPI.h"
#include "MAIN_CONFIG.h"

void APP_init(void);
void APP_First_start(void);
void APP_Start_login();
void APP_Start_menu();



#endif /* APP_H_ */