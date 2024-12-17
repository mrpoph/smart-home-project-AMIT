/*
 * UART_HW.h
 *
 * Created: 2/11/2023 11:11:27 AM
 *  Author: Ahmed Dia
 */ 


#ifndef UART_HW_H_
#define UART_HW_H_


#include "STD_Types.h"

#define UART_UCSRA_REG	(*(volatile Uint8*)0x2B)
#define UART_UCSRB_REG	(*(volatile Uint8*)0x2A)
#define UART_UCSRC_REG	(*(volatile Uint8*)0x40)
#define UART_UBRRL_REG	(*(volatile Uint8*)0x29)
#define UART_UBRRH_REG	(*(volatile Uint8*)0x40)
#define UART_UDR_REG	(*(volatile Uint8*)0x2C)


#define UART_UCSRB_TX_Enable	(1<<3)
#define UART_UCSRB_RX_Enable	(1<<4)
#define UART_UCSRB_RXCIE_Enable	(1<<7)
#define UART_UCSRB_UDRIE_Enable	(1<<5)
#define UART_UCSRC_Reg_Select	(1<<7)
#define UART_UCSRA_UDRE_Bit		(5)	//Default = 1 (EMPTY)
#define UART_UCSRA_RXC_Bit		(7)


#define UART_UCSRC_CharSize_5Bit	(0<<1)
#define UART_UCSRC_CharSize_6Bit	(1<<1)
#define UART_UCSRC_CharSize_7Bit	(2<<1)
#define UART_UCSRC_CharSize_8Bit	(3<<1)


#endif /* UART_HW_H_ */