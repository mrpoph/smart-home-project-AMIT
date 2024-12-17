/*
 * DIO.c
 *
 * Created: 11/11/2022 8:42:39 PM
 *  Author: Ahmed Dia
 */ 

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
		
		if (Level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		
		case DIO_PortB:
		
		if (Level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		
		case DIO_PortC:
		
		if (Level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		
		case DIO_PortD:
		
		if (Level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		
		case DIO_PortA:

		BitValue = GetBit(PINA_Reg,BitNo);
		break;
		
		case DIO_PortB:
		
		BitValue = GetBit(PINB_Reg,BitNo);
		break;
		
		case DIO_PortC:
		
		BitValue = GetBit(PINC_Reg,BitNo);
		break;
		
		case DIO_PortD:
		
		BitValue = GetBit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

Uint8 DIO_ReadPort(DIO_PortTypes PortId){
	Uint8 PortValue = 0;
	
	switch(PortId){
		
		case DIO_PortA:
		
		PortValue = PORTA_Reg;
		break;
		
		case DIO_PortB:
		
		PortValue = PORTB_Reg;
		break;
		
		case DIO_PortC:
		
		PortValue = PORTC_Reg;
		break;
		
		case DIO_PortD:
		
		PortValue = PORTD_Reg;
		break;
	}
	return PortValue;
}

void DIO_WritePort(DIO_PortTypes PortId,Uint8 PortValue){
	switch(PortId){
		
		case DIO_PortA:
		
		PORTA_Reg = PortValue;
		break;
		
		case DIO_PortB:
		
		PORTB_Reg = PortValue;
		break;
		
		case DIO_PortC:
		
		PORTC_Reg = PortValue;
		break;
		
		case DIO_PortD:
		
		PORTD_Reg = PortValue;
		break;
	}
}

void DIO_ConfigureChannel(DIO_ChannelTypes ChannelId,DIO_DirTypes Direction){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
		
		if (Direction == Output)
		{
			SetBit(DDRA_Reg,BitNo);
		}
		else{
			ClearBit(DDRA_Reg,BitNo);
		}
		break;
		
		case DIO_PortB:
		
		if (Direction == Output)
		{
			SetBit(DDRB_Reg,BitNo);
		}
		else{
			ClearBit(DDRB_Reg,BitNo);
		}
		break;
		
		case DIO_PortC:
		
		if (Direction == Output)
		{
			SetBit(DDRC_Reg,BitNo);
		}
		else{
			ClearBit(DDRC_Reg,BitNo);
		}
		break;
		
		case DIO_PortD:
		
		if (Direction == Output)
		{
			SetBit(DDRD_Reg,BitNo);
		}
		else{
			ClearBit(DDRD_Reg,BitNo);
		}
		break;
	}
}


void DIO_TOGChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
	
			ToggleBit(PORTA_Reg,BitNo);
		
		break;
		
		case DIO_PortB:
		
			ToggleBit(PORTB_Reg,BitNo);
	
		break;
		
		case DIO_PortC:
		
			ToggleBit(PORTC_Reg,BitNo);

		break;
		
		case DIO_PortD:
		
			ToggleBit(PORTD_Reg,BitNo);

		break;
	}
}