#include "Port.h"
#include "Registers.h"
#include "Port_Cfg.h"

#define CHANNEL_SIZE_IN_PORT               8u
#define MAX_NUMBER_OF_GPIO_PORTS           6u

static const uint32 Port_BaseAddr[MAX_NUMBER_OF_GPIO_PORTS] = {GPIO_APB_BASE_ADDRESS_A,
	                                                      GPIO_APB_BASE_ADDRESS_B,
	                                                      GPIO_APB_BASE_ADDRESS_C,
	                                                      GPIO_APB_BASE_ADDRESS_D,
	                                                      GPIO_APB_BASE_ADDRESS_E,
	                                                      GPIO_APB_BASE_ADDRESS_F};


void Port_Init ( const Port_ConfigType* ConfigPtr )
{
	Port_PinType                locPinId;
	Port_PinDirectionType       locPinDir;
	Port_PinModeType            locPinMode;
	Port_PinOutputCurrentType   locCurrentStrength;
	Port_PinInternalAttachType  locInternalAttach;
	uint8 PortIndex;
	uint8 PinIndex;
	uint32 PortBaseAddr;
	
	for(uint8 i=0;i<PORT_ACTIVATED_CHANNELS_SIZE;i++)
	{
		locPinId             = ConfigPtr[i].PinId;
		locPinDir            = ConfigPtr[i].PinDirection;
		locPinMode           = ConfigPtr[i].PinMode;
		locCurrentStrength   = ConfigPtr[i].PinOutputCurrent;
		locInternalAttach    = ConfigPtr[i].PinInternalAttach;
		
		PortIndex    = locPinId / CHANNEL_SIZE_IN_PORT ;
		PinIndex     = locPinId % CHANNEL_SIZE_IN_PORT ;
        PortBaseAddr = Port_BaseAddr[PortIndex] ;
		
		GPIODIR(PortBaseAddr) |= (locPinDir<< PinIndex) ; 
		GPIODEN(PortBaseAddr) |= (PinIndex);
		GPIODATA(PortBaseAddr,(PinIndex<<2))|= 0;//initially off 
		                                        //bit masking
		
	}

}