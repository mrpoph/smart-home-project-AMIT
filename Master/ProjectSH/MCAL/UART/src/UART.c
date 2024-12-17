/*
 * UART.c
 *
 * Created: 2/11/2023 11:11:39 AM
 *  Author: Ahmed Dia
 */ 

#include "UART.h"
#include <avr/interrupt.h>

void Uart_Init(void){
	UART_UCSRB_REG = (UART_UCSRB_TX_Enable | UART_UCSRB_RX_Enable | UART_UCSRB_RXCIE_Enable );
	UART_UCSRC_REG = (UART_UCSRC_Reg_Select | UART_UCSRC_CharSize_8Bit);
	UART_UBRRL_REG = MyUBRR;
	UART_UBRRH_REG = MyUBRR>>8;
	sei();
}
void Uart_Transmit(int8 data){
	while(GetBit(UART_UCSRA_REG, UART_UCSRA_UDRE_Bit) == 0);
	UART_UDR_REG = data;
}
int8 Uart_Receive(void){
	while(GetBit(UART_UCSRA_REG,UART_UCSRA_RXC_Bit) == 0);
	return UART_UDR_REG;
}
void Uart_TransmitString(int8 * string){
	Uint8 i = 0;
	while (string[i] != '\0')
	{
		Uart_Transmit(string[i]);
		i++;
	}
}

void New_line(){
	Uart_Transmit(0x0A);
}

void Uart_T_Admin_menu(){
	
	Uart_TransmitString("1.ROOM1");
	 New_line();
	Uart_TransmitString("2.ROOM2");
	 New_line();
	Uart_TransmitString("3.ROOM3");
	 New_line();
	Uart_TransmitString("4.ROOM4");
	 New_line();
	Uart_TransmitString("5.ROOM5");
	 New_line();
	Uart_TransmitString("6.Dimmer");
	 New_line();
	Uart_TransmitString("7.AC");
	 New_line();
	Uart_TransmitString("8.DOOR");
	 New_line();
	Uart_TransmitString("9.Access");
	 New_line();
	Uart_TransmitString("C.Logout");
	 New_line();
}
