/*
 * main.c
 *
 * Created: 2/21/2023 12:35:42 PM
 *  Author: Ahmed Dia
 */ 

#include "APP.h"

int main(){
	
	APP_init();
	APP_First_start();

	while(1){
		APP_Start_login();
		APP_Start_menu();
	}
}