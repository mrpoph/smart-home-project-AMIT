/*
 * LCD.c
 *
 * Created: 11/11/2022 9:27:38 PM
 *  Author: Ahmed Dia
 */ 

#include "LCD.h"

void LCD_Init(void){
	DIO_WriteChannel(LCD_RW,STD_Low);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(100);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);	//Set Function 4-Bit & 2Line & 5*8 Dots
	_delay_us(100);
	LCD_Cmd(0x0E);//Display on & Cursor off and no blinking
	LCD_Cmd(0x06);	//Entry Mode move to right and no shift
	//LCD_Cmd(0x07);
	LCD_Cmd(0x01);//Clear LCD
	
}

void Enable_CLK(void){
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_Low);

}

void LCD_Cmd(Uint8 cmd){

	Uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS,STD_Low);//Select command Register
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable_CLK();

	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable_CLK();

	_delay_ms(5);
}
void LCD_Char(Uint8 data){

	Uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS,STD_High);	//Select Data Register
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable_CLK();
	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable_CLK();

	_delay_ms(2);
}
void LCD_String(int8 * string){
	Uint8 i = 0;
	while (string[i] != '\0')
	{
		LCD_Char(string[i]);
		i++;
	}
}

void LCD_SetPos(Uint8 LineNo,Uint8 Pos){
	switch(LineNo){
		case 1:
		if(Pos >= 0 || Pos < 16){
			LCD_Cmd(0x80 + Pos);
		}	
		break;
		case 2:
		if(Pos >= 0 || Pos < 16){
			LCD_Cmd(0xC0 + Pos);
		}
		break;
		default:
		LCD_Cmd(0x80);
		break;
	}
}

void LCD_Clear(void){
	LCD_Cmd(CLR_SCREEN);
}

