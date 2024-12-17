/*
 * UART.h
 *
 * Created: 2/11/2023 11:11:11 AM
 *  Author: Ahmed Dia
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_HW.h"
#include "Clock.h"
#include "STD_Types.h"
#include "BitMath.h"


#define BaudRate 9600

//#define DoubleSpeed

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(BaudRate*16UL))-1)
#else
#define MyUBRR ((F_CPU/(BaudRate*8UL))-1)
#endif

void Uart_Init();
void Uart_Transmit(int8 data);
int8 Uart_Receive();
void Uart_TransmitString(int8 * string);
void New_line();
void Uart_T_Admin_menu();




#endif /* UART_H_ */