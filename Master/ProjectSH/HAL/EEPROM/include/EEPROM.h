/*
 * EEPROM.h
 *
 * Created: 12/18/2022 11:10:07 AM
 *  Author: Ahmed Dia
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "TWI.h"

//void EEPROM_WriteByte(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 data);
//Uint8 EEPROM_ReadByte(Uint8 DeviceAdd,Uint8 LocAdd);
//void EEPROM_WriteBlock(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 *data,Uint8 size);
//Uint8 EEPROM_ReadBlock(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 size);
//Uint8 EEPROM_COMPARE(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 Entered_pass,Uint8 size);


Uint8 EEPROM_ReadByte(const Uint16 u16Address);
void EEPROM_ReadBlock(const Uint16 u16Address, Uint8* dist,const Uint16 size);
void EEPROM_WriteByte(const Uint16 u16Address, const Uint8 u8Data);
void EEPROM_WriteBlock(const Uint16 u16Address, const Uint8* u8Data,const Uint16 size);
Uint8 Pass_Compare(const Uint8* Pass1,const Uint8* Pass2, const Uint8 Size);


#endif /* EEPROM_H_ */