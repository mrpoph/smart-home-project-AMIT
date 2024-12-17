/*
 * SPI.c
 *
 * Created: 12/2/2022 8:33:48 PM
 *  Author: Ahmed Dia
 */ 

#include "SPI.h"

void SPI_Init(SPI_InitType options){
	switch(options.state){
		case MASTER:
			DIO_ConfigureChannel(SPI_SS_PIN,Output);
			DIO_ConfigureChannel(SPI_MOSI_PIN,Output);
			DIO_ConfigureChannel(SPI_MISO_PIN,Input);
			DIO_ConfigureChannel(SPI_SCLK_PIN,Output);
			SPI->MySPCR.Bits.MyMSTR = 1;
			SPI->MySPCR.Bits.MySPE = 1;
			break;
		case SLAVE:
			DIO_ConfigureChannel(SPI_SS_PIN,Output);
			DIO_ConfigureChannel(SPI_MOSI_PIN,Output);
			DIO_ConfigureChannel(SPI_MISO_PIN,Input);
			DIO_ConfigureChannel(SPI_SCLK_PIN,Output);
			SPI->MySPCR.Bits.MySPE = 1;
	}
}
Uint8 SPI_TxRx(Uint8 data){
	SPI->MySPDR = data;
	while(SPI->MySPSR.Bits.MySPIF == STD_Low);
	return SPI->MySPDR;
}
void SPI_SlaveEnable(){
	DIO_WriteChannel(SPI_SS_PIN,STD_Low);
}
void SPI_SlaveDisable(){
	DIO_WriteChannel(SPI_SS_PIN,STD_High);
}