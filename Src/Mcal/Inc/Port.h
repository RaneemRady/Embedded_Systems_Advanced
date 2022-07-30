#ifndef PORT_H
#define PORT_H
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
}Port_PinType;

typedef enum {
	PORT_PIN_INPUT,
	PORT_PIN_OUTPUT
}Port_PinDirectionType; //Input or Output

typedef enum  {
	DIO,
	ADC
}Port_PinModeType;//Dio,// To do ADC and alternate functions

typedef enum {
	PORT_ATTACH_DEFAULT,
	PORT_ATTACH_PULLUP,
	PORT_ATTACH_PULLDOWN,
	PORT_ATTACH_OPENDRAIN
}Port_PinInternalAttachType;

typedef enum {
	PORT_PIN_CURRENT_2m,
	PORT_PIN_CURRENT_4m,
}Port_PinOutputCurrentType;

typedef struct Pin {

	Port_PinType PinId;//e.g PF1
	Port_PinDirectionType PinDirection; //Input or Output
	Port_PinModeType PinMode; //Dio,//ADC
	Port_PinInternalAttachType PinInternalAttach; //To Do
	Port_PinOutputCurrentType PinOutputCurrent; //To Do

}Port_ConfigType;




void PortInit(const Port_ConfigType* ConfigPtr);

#endif



