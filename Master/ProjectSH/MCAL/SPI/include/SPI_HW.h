/*
 * SPI_HW.h
 *
 * Created: 12/2/2022 8:35:59 PM
 *  Author: Ahmed Dia
 */ 


#ifndef SPI_HW_H_
#define SPI_HW_H_
#include "SPI_Types.h"
#include "DIO.h"

#define SPI_SS_PIN DIO_ChannelB4
#define SPI_MOSI_PIN DIO_ChannelB5
#define SPI_MISO_PIN DIO_ChannelB6
#define SPI_SCLK_PIN DIO_ChannelB7

#define SPI ((volatile SPI_Reg*)0x2D)


#endif /* SPI_HW_H_ */