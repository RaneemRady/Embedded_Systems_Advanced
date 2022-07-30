#include "Timer.h"
#include "Registers.h"
#include "Timer_Cfg.h"
#include "Std_Types.h"

#define MAX_NUMBER_OF_GPIO_GPT 		                 12u

Gpt_FunPtr locGptNotification[MAX_NUMBER_OF_GPIO_GPT];

static const Gpt_ConfigType*			globalGptConfig;

extern volatile uint32 GlobalSystemClock = 16000;//assumption

static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER1_BASE_ADDRESS,		
	                                                           GPT_16_32_BIT_TIMER2_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER3_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER4_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER5_BASE_ADDRESS,			
	                                                           GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
															   
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	uint8 i;
	uint8 prescale;
	uint32 gptBaseAddress;
	Gpt_ChannelType locChannel;
	Gpt_ValueType locChannelTickFreq;
	Gpt_ValueType locChannelTickMaxValue;
	Gpt_ModeType locChannelMode;
	globalGptConfig = ConfigPtr;
	for(i=0;i<GPT_ACTIVATED_CHANNELS_SIZE;i++)
	{
		locChannel = ConfigPtr[i].GptChannelID;
		locChannelTickFreq = ConfigPtr[i].GptChannelTickFrequency;
		locChannelTickMaxValue = ConfigPtr[i].GptChannelTickValueMax;
		locChannelMode = ConfigPtr[i].GptChannelMode;
		locGptNotification[locChannel]= ConfigPtr[i].GptNotification;

		gptBaseAddress = Gpt_BaseAddress[locChannel];
		
		GPTMCTL(gptBaseAddress) = 0;   //Ensure the timer is disabled: CLear TAEN bit in GPTMCTL 
		
		GPTMCFG(gptBaseAddress) = 0x4; //16 bit timer for 16/32 bit timers

		/* counting up  , starting from 0*/
		GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);

		/* Select Timer Mode */
		if (locChannelMode == GPT_CH_MODE_ONESHOT)
		{
			GPTMTAMR(gptBaseAddress) |= 0x1;
		}
		else if (locChannelMode == GPT_CH_MODE_CONTINUOUS)
		{
			GPTMTAMR(gptBaseAddress) |= 0x2; 
		}
		
		Gpt_DisableNotification(locChannel);
	}
}
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0;
}
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMIMR(gptBaseAddress) = 0x1;
}
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value )
{
	uint8 i;
	uint32 prescale;
	uint32 gptBaseAddress;
	Gpt_ValueType locChannelTickFreq;
	
	gptBaseAddress = Gpt_BaseAddress[Channel];
		for(i=0;i<MAX_NUMBER_OF_GPIO_GPT;i++)
	{
		if (globalGptConfig[i].GptChannelID == Channel)
		{
			locChannelTickFreq = globalGptConfig[i].GptChannelTickFrequency;
			break;
		}
	}
	
	prescale = GlobalSystemClock / locChannelTickFreq; //user requires frequency different from oscillator
	
	/* adding the value deppending on the freq required */
	GPTMTAILR(gptBaseAddress) = Value * prescale; //Load the start value in GPTMTAILR
	
	GPTMCTL(gptBaseAddress) |= (1<<TAEN);//Enable the timer to start counting
}

void Gpt_StopTimer(Gpt_ChannelType Channel,Gpt_ValueType Value )
{
	uint32 gptBaseAddress;
	gptBaseAddress = Gpt_BaseAddress[Channel];
	GPTMCTL(gptBaseAddress) &= (~(1<<TAEN));
}
void TIMER0A_Handler(void)
{
	Gpt_FunPtr gptNotificationFn_TIMER0A;
	if (locGptNotification[GPT_16_32_BIT_TIMER0] != NULL)
	{
		gptNotificationFn_TIMER0A = locGptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
	}
}


