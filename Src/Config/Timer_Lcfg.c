#include "Timer_Cfg.h"
#include "Timer.h"

const Gpt_ConfigType Gpt_Config[GPT_ACTIVATED_CHANNELS_SIZE] =
{
	/* channel						channelTickFreq					channelTickMaxValue					channelMode								gptNotification */
	{GPT_16_32_BIT_TIMER0,		      1,							0xFFFF,								GPT_CH_MODE_CONTINUOUS,			&Gpt_Notification_GPT0},

};