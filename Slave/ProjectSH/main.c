/*
 * main.c
 *
 * Created: 2/21/2023 12:19:24 PM
 *  Author: Ahmed Dia
 */ 
#include <avr/interrupt.h>
#include "STD_Types.h"
#include "Clock.h"
#include <util/delay.h>
#include "APP.h"

int main(){
	
	APP_Init();
	while(1){
		APP_Start();
	}
}



