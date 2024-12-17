/*
* TWI.c
*
* Created: 12/3/2022 8:36:43 PM
*  Author: user
*/
#include "TWI.h"
#include "avr/io.h"

void TWI_Init(Uint8 address){
	TWI->TWAR_Reg = address;//Set Address
	TWI->TWBR_Reg = MyTWBR;//Set PReScaller
}
Uint8 TWI_Status(void){
	return (TWI->TWSR_Reg & 0xF8);//Get Status
}
Uint8 TWI_Start(void){
	//TWI->TWCR_Reg.AllReg = 0b10100100;
	TWI->TWCR_Reg.Bits.TWSTA_Bit = 1;//Set Start Bit
	TWI->TWCR_Reg.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEN_Bit = 1;//Enable TWI
	TWI->TWCR_Reg.Bits.TWINT_Bit = 1;//Clear the Flag
	while(TWI->TWCR_Reg.Bits.TWINT_Bit == 0);
	return TWI_Status();
}
void TWI_Stop(void){
	//TWI->TWCR_Reg.AllReg = 0b10010100;
	TWI->TWCR_Reg.Bits.TWSTO_Bit = 1;//Set Stop Bit
	TWI->TWCR_Reg.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEN_Bit = 1;
	TWI->TWCR_Reg.Bits.TWINT_Bit = 1;
}
Uint8 TWI_Send(Uint8 data){
	TWI->TWDR_Reg = data;
	//TWI->TWCR_Reg.AllReg = 0b10000100;
	TWI->TWCR_Reg.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Reg.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEN_Bit = 1;
	TWI->TWCR_Reg.Bits.TWINT_Bit = 1;
	while(TWI->TWCR_Reg.Bits.TWINT_Bit == 0);
	return TWI_Status();
}
Uint8 TWI_Read_ACK(Uint8 * data){
	//TWI->TWCR_Reg.AllReg = 0b11000100;
	TWI->TWCR_Reg.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Reg.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEA_Bit = 1;
	TWI->TWCR_Reg.Bits.TWEN_Bit = 1;
	TWI->TWCR_Reg.Bits.TWINT_Bit = 1;
	while(TWI->TWCR_Reg.Bits.TWINT_Bit == 0);
	*data = TWI->TWDR_Reg;
	return TWI_Status();
}
Uint8 TWI_Read_NACK(Uint8 * data){
	//TWI->TWCR_Reg.AllReg = 0b10000100;
	TWI->TWCR_Reg.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Reg.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEA_Bit = 0;
	TWI->TWCR_Reg.Bits.TWEN_Bit = 1;
	TWI->TWCR_Reg.Bits.TWINT_Bit = 1;
	while(TWI->TWCR_Reg.Bits.TWINT_Bit == 0);
	*data = TWI->TWDR_Reg;
	return TWI_Status();
}