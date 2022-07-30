#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
#include "Platform_Types.h"
typedef enum {
	PA0, 
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	
	PE0,
	PE1,
	PE2,
	PE3,
	PE4,
	PE5,
	NAPE6,
	NAPE7,

	PF0,
	PF1,
	PF2,
	PF3,
	PF4,
	NAPF5,
	NAPF6,
	NAPF7
}Dio_ChannelType; //pin id

typedef enum  {
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
}Dio_PortType;//port id
typedef uint8 Dio_LevelType;         //port id

typedef unsigned char Dio_PortLevelType;     //port id

#define HIGH 0xFF

#define LOW  0x00

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType ChannelLevel);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType PortLevel);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif  