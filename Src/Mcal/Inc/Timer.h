#ifndef TIMER_H
#define TIMER_H
#include "Platform_Types.h"

typedef enum {
	GPT_16_32_BIT_TIMER0,
	GPT_16_32_BIT_TIMER1,
	GPT_16_32_BIT_TIMER2,
	GPT_16_32_BIT_TIMER3,
	GPT_16_32_BIT_TIMER4,
	GPT_16_32_BIT_TIMER5,
	GPT_32_64_BIT_WIDE_TIMER0,
	GPT_32_64_BIT_WIDE_TIMER1,
	GPT_32_64_BIT_WIDE_TIMER2,
	GPT_32_64_BIT_WIDE_TIMER3,
	GPT_32_64_BIT_WIDE_TIMER4,
	GPT_32_64_BIT_WIDE_TIMER5
}Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef void (*Gpt_FunPtr)(void);

typedef enum {
	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOT
}Gpt_ModeType;

typedef struct {
	Gpt_ChannelType GptChannelID;
	Gpt_ValueType GptChannelTickFrequency;
	Gpt_ValueType GptChannelTickValueMax;
	Gpt_ModeType GptChannelMode;
	Gpt_FunPtr GptNotification;  //GptNotification = &NotificationName
}Gpt_ConfigType;

void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value );
void Gpt_StopTimer(Gpt_ChannelType Channel,Gpt_ValueType Value );

void Gpt_Notification_GPT0(void);

#endif