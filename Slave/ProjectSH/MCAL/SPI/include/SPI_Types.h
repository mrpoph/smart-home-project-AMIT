/*
 * SPI_Types.h
 *
 * Created: 12/2/2022 8:36:10 PM
 *  Author: Ahmed Dia
 */ 


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_
#include "SPI.h"


typedef enum{
	SLAVE=0,
	MASTER
}SPI_StateOptions;

typedef struct
{
	SPI_StateOptions state;
}SPI_InitType;

typedef struct{
	Uint8 MySPI2X:1;
	Uint8 RESERVED:5;
	Uint8 MyWCOL:1;
	Uint8 MySPIF:1;
}SPI_SPSRBits;

typedef union{
	Uint8 AllReg;
	SPI_SPSRBits Bits;
}SPI_SPSR_REG;

typedef struct{
	Uint8 MySPR0:1;
	Uint8 MySPR1:1;
	Uint8 MyCPHA:1;
	Uint8 MyCPOL:1;
	Uint8 MyMSTR:1;
	Uint8 MyDORD:1;
	Uint8 MySPE:1;
	Uint8 MySPIE:1;
}SPI_SPCRBits;

typedef union{
	Uint8 AllReg;
	SPI_SPCRBits Bits;
}SPI_SPCR_REG;

typedef struct{
	SPI_SPCR_REG MySPCR;
	SPI_SPSR_REG MySPSR;
	Uint8 MySPDR;
}SPI_Reg;



#endif /* SPI_TYPES_H_ */