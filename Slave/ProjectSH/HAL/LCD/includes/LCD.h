/*
 * LCD.h
 *
 * Created: 11/11/2022 9:27:21 PM
 *  Author: Ahmed Dia
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelD3

#define CLR_SCREEN           0X01
#define DISPLAY_ON_CURSOR_ON_BLNK 0X0F
#define DISPLAY_ON_CURSOR_OFF_BLNK 0X0E
#define DISPLAY_OFF_CURSOR_OFF 0x08
#define EIGHT_BIT_MODE       0X38
#define ENTRY_MODE 0x06
#define SHIFT_LEFT           0x18

#define LCD_DataPort DIO_PortA

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Uint8 data);
void LCD_String(int8 * string);
void LCD_SetPos(Uint8 LineNo,Uint8 Pos);
void LCD_Clear(void);
void Enable_CLK(void);


#endif /* LCD_H_ */