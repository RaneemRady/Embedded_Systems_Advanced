#include "Dio.h"
#include "Registers.h"

#define CHANNEL_SIZE_IN_PORT               8u
#define MAX_NUMBER_OF_GPIO_PORTS           6u

static const uint32 Port_BaseAddr[MAX_NUMBER_OF_GPIO_PORTS] = {GPIO_APB_BASE_ADDRESS_A,
	                                                      GPIO_APB_BASE_ADDRESS_B,
	                                                      GPIO_APB_BASE_ADDRESS_C,
	                                                      GPIO_APB_BASE_ADDRESS_D,
	                                                      GPIO_APB_BASE_ADDRESS_E,
	                                                      GPIO_APB_BASE_ADDRESS_F};
                                                          
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType ChannelLevel;
	uint32 gpioDataOffset;
	uint32 PortIndex,PinIndex,PortBaseAddr;
	
	PortIndex = ChannelId / CHANNEL_SIZE_IN_PORT;
	PinIndex = ChannelId % CHANNEL_SIZE_IN_PORT;
	
	PortBaseAddr = Port_BaseAddr[PortIndex];
	
	ChannelLevel = (GPIODATA(PortBaseAddr,(PinIndex<<2))) >> PinIndex;
 
	
	return ChannelLevel;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType ChannelLevel)
{
	uint32 gpioDataOffset;
	uint32 PortIndex,PinIndex,PortBaseAddr;
	
	PortIndex = ChannelId / CHANNEL_SIZE_IN_PORT;
	PinIndex = ChannelId % CHANNEL_SIZE_IN_PORT;
	
	PortBaseAddr = Port_BaseAddr[PortIndex];
    GPIODATA(PortBaseAddr,(PinIndex<<2))|= ChannelLevel;
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{

}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType PortLevel)
{
	
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
		Dio_LevelType levelType;
	if (Dio_ReadChannel(ChannelId) == STD_LOW)
	{
		Dio_WriteChannel(ChannelId,STD_HIGH);
		levelType = STD_HIGH;
	}
	else if (Dio_ReadChannel(ChannelId) == STD_HIGH)
	{
		Dio_WriteChannel(ChannelId,STD_LOW);
		levelType = STD_LOW;
	}
	
	return levelType;
}