/*
 * DIO.h
 *
 * Created: 11/11/2022 8:41:37 PM
 *  Author: Ahmed Dia
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "Clock.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_Config.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);
Uint8 DIO_ReadPort(DIO_PortTypes PortId);
void DIO_WritePort(DIO_PortTypes PortId,Uint8 PortValue);
void DIO_ConfigureChannel(DIO_ChannelTypes ChannelId,DIO_DirTypes Direction);
void DIO_TOGChannel(DIO_ChannelTypes ChannelId);




#endif /* DIO_H_ */