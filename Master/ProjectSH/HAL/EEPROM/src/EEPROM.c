/*
 * EEPROM.c
 *
 * Created: 12/18/2022 11:10:18 AM
 *  Author: Ahmed Dia
 */ 

#include "EEPROM.h"
#include "avr/io.h"
/*
void EEPROM_WriteByte(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 data){
	Uint8 wDeviceAdd = (DeviceAdd & 0xFE);//Clear First Bit for Write
	if (TWI_Start() == 0x08)
	{	
		if (TWI_Send(wDeviceAdd) == 0x18)
		{	
			if (TWI_Send(LocAdd) == 0x28)
			{
				if (TWI_Send(data) == 0x28)
				{
					TWI_Stop();
				}
			}
		}
	}
	else{
		DDRC |= (1<<2);
		PORTC |= (1<<2);
		DDRC |= (1<<3);
		PORTC |= (1<<3);
		
	}
}
Uint8 EEPROM_ReadByte(Uint8 DeviceAdd,Uint8 LocAdd){
	Uint8 wDeviceAdd = (DeviceAdd & 0xFE);//Clear First Bit for Write
	Uint8 rDeviceAdd = (DeviceAdd | 1);//Clear First Bit for Read
	Uint8 ReadData = 0;
	if (TWI_Start() == 0x08)//start in Master Trans. Mode
	{
		if (TWI_Send(wDeviceAdd) == 0x18)
		{
			if (TWI_Send(LocAdd) == 0x28)
			{
				if (TWI_Start() == 0x10)//switch to Master Receive Mode
				{
					if (TWI_Send(rDeviceAdd) == 0x40)
					{
						TWI_Read_NACK(&ReadData);
						TWI_Stop();
					}
				}
			}
		}
	}
	return ReadData;
}


void EEPROM_WriteBlock(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 *data,Uint8 size){
	for(int i = 0; i<size ; i++){
		EEPROM_WriteByte(DeviceAdd,LocAdd,data);
	}
}
Uint8 EEPROM_ReadBlock(Uint8 DeviceAdd,Uint8 LocAdd,Uint8 size){
	Uint8 ReadData[4];
	for(int i = 0; i<size ; i++){
		ReadData[i] = EEPROM_ReadByte(DeviceAdd,LocAdd);	
	}

}
*/


Uint8 EEPROM_ReadByte(const Uint16 u16Address)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;
	/* Set up address register */
	EEAR = u16Address;
	/* Start EEPROM read by writing EERE */
	EECR |= (1 << EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_ReadBlock(const Uint16 uiAddress, Uint8* dist,const Uint16 size)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;

	Uint16 counter = 0;//the counter of bytes that are read

	while (counter < size) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR = uiAddress + counter;
		/* Start EEPROM read by writing EERE */
		EECR |= (1 << EERE);
		/* move data from data register to the array */
		*(dist + counter) = EEDR;

		counter++;//increase the bytes counter
	}
}

void EEPROM_WriteByte(const Uint16 uiAddress, const Uint8 uiData)
{

	/* Wait for completion of previous write process*/
	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
	;
	/* Set up address register */
	EEAR = uiAddress;

	/* Read the byte in the address of EEAR */
	EECR |= (1 << EERE);
	if (EEDR != uiData)//compare the value read to the value to be written
	{//if they are not equal then write the data
		EEDR = uiData;//move the data to EEDR

		/* Write logical one to EEMWE */
		EECR |= (1 << EEMWE);
		/* Start EEPROM write by setting EEWE */
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}

void EEPROM_WriteBlock(const Uint16 uiAddress, const Uint8* uiData,const Uint16 size)
{
	Uint16 counter = 0;//Bytes write counter
	while (counter < size)
	{
		/* Wait for completion of previous write process*/
		while (( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
		;
		/* Set up address register */
		EEAR = uiAddress + counter;

		/* Read the byte in the address of EEAR */
		EECR |= (1 << EERE);
		if (EEDR != (*(uiData + counter)))//compare the value read to the value to be written
		{//if they are not equal then write the data
			EEDR = *(uiData + counter);//move the data to EEDR

			/* Write logical one to EEMWE */
			EECR |= (1 << EEMWE);
			/* Start EEPROM write by setting EEWE */
			EECR |= (1 << EEWE);
		}
		else
		{

		}
		counter++;//increase bytes counter
	}
}

Uint8 Pass_Compare(const Uint8* Pass1,const Uint8* Pass2, const Uint8 Size){
	Uint8 pin_counter=0;//the offset of the character of the pin
	Uint8 ret_value = 1;
	while (pin_counter < Size)//loop till the pin is fully entered
	{
		if (*(Pass1+pin_counter)!=*(Pass2+pin_counter))//if the two characters of the entered pin and the stored pin are not equal
		{
			ret_value= 0;//returns false that means the two PINs are not equal
			break;//break the loop
		}
		pin_counter++;//increase thee offset by one
	}
	return ret_value;
}