/*
 * TWI.h
 *
 * Created: 12/3/2022 8:35:30 PM
 *  Author: user
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "STD_Types.h"
#include "TWI_HW.h"
#include "TWI_Types.h"
#include "Clock.h"

#define F_TWI 400000UL
#define MyTWPS 1
#define MyTWBR (((F_CPU/F_TWI)-16)/(2*4^MyTWPS))

void TWI_Init(Uint8 address);
Uint8 TWI_Status(void);
Uint8 TWI_Start(void);
void TWI_Stop(void);
Uint8 TWI_Send(Uint8 data);
Uint8 TWI_Read_ACK(Uint8 * data);
Uint8 TWI_Read_NACK(Uint8 * data);

#endif /* TWI_H_ */