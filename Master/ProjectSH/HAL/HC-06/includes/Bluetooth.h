/*
 * Bluetooth.h
 *
 * Created: 2/21/2023 11:14:55 AM
 *  Author: Ahmed Dia
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "STD_Types.h"
#include "UART.h"


void Bluetooth_Init();
void Bluetooth_Transmit(int8 data);
int8 Bluetooth_Receive();
void Bluetooth_TransmitString(int8 * string);
void Bluetooth_New_line();
void Bluetooth_T_Admin_menu();



#endif /* BLUETOOTH_H_ */