/*
 * Bluetooth.c
 *
 * Created: 2/21/2023 11:15:07 AM
 *  Author: Ahmed Dia
 */ 
#include "Bluetooth.h"

void Bluetooth_Init(){
	Uart_Init();
}
void Bluetooth_Transmit(int8 data){
	Uart_Transmit(data);
}
int8 Bluetooth_Receive(){
	Uart_Receive();
}
void Bluetooth_TransmitString(int8 * string){
	Uart_TransmitString(string);
}
void Bluetooth_New_line(){
	New_line();
}
void Bluetooth_T_Admin_menu(){
	Uart_T_Admin_menu();
}