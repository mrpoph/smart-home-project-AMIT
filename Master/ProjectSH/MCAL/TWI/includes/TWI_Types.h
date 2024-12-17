/*
* TWI_Types.h
*
* Created: 12/3/2022 8:36:28 PM
*  Author: user
*/


#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_

#include "STD_Types.h"

typedef struct
{
	Uint8 TWIE_Bit:1;
	Uint8 RESERVED:1;
	Uint8 TWEN_Bit:1;
	Uint8 TWWC_Bit:1;
	Uint8 TWSTO_Bit:1;
	Uint8 TWSTA_Bit:1;
	Uint8 TWEA_Bit:1;
	Uint8 TWINT_Bit:1;
}TWI_TWCRBits;

typedef union{
	Uint8 AllReg;
	TWI_TWCRBits Bits;
}TWI_TWCRType;

typedef struct{
	Uint8 TWBR_Reg;
	Uint8 TWSR_Reg;
	Uint8 TWAR_Reg;
	Uint8 TWDR_Reg;
	Uint8 RESERVED[50];
	TWI_TWCRType TWCR_Reg;
}TWI_Reg;


#endif /* TWI_TYPES_H_ */