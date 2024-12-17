/*
 * DIO_Config.h
 *
 * Created: 11/11/2022 8:41:54 PM
 *  Author: Ahmed Dia
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "DIO.h"

typedef struct
{
	DIO_DirTypes PinDir;
	STD_LevelTypes Level;
	
}DIO_PinCfg;

#define PINCOUNT 32

void DIO_Init(void);

#endif /* DIO_CONFIG_H_ */