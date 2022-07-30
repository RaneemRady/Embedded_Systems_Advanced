#include "Port.h"
#include "Port_Cfg.h"

const Port_ConfigType Port_Config[PORT_ACTIVATED_CHANNELS_SIZE]=
{
	/* pinId           pinDir     pinMode    currentStrength        internalAttach     */
	{  PF1,   PORT_PIN_OUTPUT,    DIO       ,PORT_PIN_CURRENT_4m   ,PORT_ATTACH_PULLUP},
	{  PF2,   PORT_PIN_OUTPUT,    DIO       ,PORT_PIN_CURRENT_4m   ,PORT_ATTACH_PULLUP},
	{  PF3,   PORT_PIN_OUTPUT,    DIO       ,PORT_PIN_CURRENT_4m   ,PORT_ATTACH_PULLUP}
	
};
