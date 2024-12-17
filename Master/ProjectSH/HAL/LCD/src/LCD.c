/*
 * LCD.c
 *
 * Created: 11/11/2022 9:27:38 PM
 *  Author: Ahmed Dia
 */ 

#include "LCD.h"

void LCD_Init(void){
	DIO_WriteChannel(LCD_RW,STD_Low);	//RW SET LOW (WRITE)
	DIO_WriteChannel(LCD_E,STD_High);	//Activates the enable pin
	
	LCD_Cmd(EIGHT_BIT_MODE);	//Set Function 8-Bit & 2Line & 5*8 Dots
	_delay_us(60);
	LCD_Cmd(DISPLAY_ON_CURSOR_OFF_BLNK);
	_delay_us(60);
	LCD_Cmd(ENTRY_MODE);	
	_delay_us(5);
	LCD_Cmd(CLR_SCREEN);	
	_delay_us(60);
	LCD_Cmd(Start_position);
	_delay_us(60);
	
}

void Enable_CLK(void){
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_Low);

}

void LCD_Cmd(Uint8 cmd){

	DIO_WriteChannel(LCD_RS,STD_Low);//Select command Register
	DIO_WritePort(LCD_DataPort,cmd);
	Enable_CLK();
	_delay_ms(5);
}
void LCD_Char(Uint8 data){

	DIO_WriteChannel(LCD_RS,STD_High);	//Select Data Register
	DIO_WritePort(LCD_DataPort,data);
	Enable_CLK();
	_delay_ms(5);
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

