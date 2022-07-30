/* This is a timer interrupt example code of TM4C123 Tiva C Launchpad */
/* Generates a delay of one second using Timer0 interrupt handler routine */

#include "Timer.h"
#include "Dio.h"

#define Seconds 5 //user input

static  uint8 counts = Seconds;

void Timer_1sec_delay(void)
{

  // SYSCTL->RCGCTIMER |= (1<<1);  /*To Do: implement mcu to enable clock Timer in run mode */

   Gpt_StartTimer(GPT_16_32_BIT_TIMER0,1);

   Gpt_EnableNotification(GPT_16_32_BIT_TIMER0);

}

int main(void)
{
	 
  // SYSCTL->RCGCGPIO |= 0x20; // To Do: implement mcu to turn on bus clock for GPIOF 

   Timer_1sec_delay();

	while(1)
	{
		// do nothing wait for the interrupt to occur
	}
}

/* Timer1 subtimer A interrupt service routine */
void Gpt_Notification_GPT0()
{
     counts++;
	  if(counts == Seconds)
		{  
         Dio_FlipChannel(PF3);
         counts = 0;
      }
//		TIMER1->ICR = 0x1;          /* To Do: clear interrupt*/
}

