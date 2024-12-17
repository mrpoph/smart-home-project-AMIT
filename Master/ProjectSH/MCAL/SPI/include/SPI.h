/*
 * SPI.h
 *
 * Created: 12/2/2022 8:35:42 PM
 *  Author: Ahmed Dia
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "STD_Types.h"
#include "SPI_Types.h"
#include "SPI_HW.h"

void SPI_Init(SPI_InitType options);
Uint8 SPI_TxRx(Uint8 data);
void SPI_SlaveEnable();
void SPI_SlaveDisable();


#endif /* SPI_H_ */