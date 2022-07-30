/*****************************************GPIO Registers***************************************/
#define GPIO_APB_BASE_ADDRESS_A          0x40004000
#define GPIO_APB_BASE_ADDRESS_B          0x40005000
#define GPIO_APB_BASE_ADDRESS_C          0x40006000
#define GPIO_APB_BASE_ADDRESS_D          0x40007000
#define GPIO_APB_BASE_ADDRESS_E          0x40024000
#define GPIO_APB_BASE_ADDRESS_F          0x40025000

#define GPIODIR_OFFSET			0x400
#define GPIODEN_OFFSET			0x51C
#define GPIOAFSEL_OFFSET		0x420
#define GPIODR2R_OFFSET			0x500    //2ma
#define GPIODR4R_OFFSET			0x504    //4ma
#define GPIODR4R_OFFSET			0x508    //8ma
#define GPIOODR_OFFSET			0x50C
#define GPIOPUR_OFFSET			0x50C
#define GPIOPDR_OFFSET			0x50C

#define GPIODATA(BaseAddr,OFFSET)                 *((volatile uint32*)BaseAddr+OFFSET)
#define GPIODIR(BaseAddr)                  *((volatile uint32*)BaseAddr+GPIODIR_OFFSET)
#define GPIODEN(BaseAddr)                  *((volatile uint32*)BaseAddr+GPIODEN_OFFSET)

/*****************************************GTM Registers***************************************/
#define GPT_16_32_BIT_TIMER0_BASE_ADDRESS					0x40030000
#define	GPT_16_32_BIT_TIMER1_BASE_ADDRESS					0x40031000
#define	GPT_16_32_BIT_TIMER2_BASE_ADDRESS					0x40032000
#define	GPT_16_32_BIT_TIMER3_BASE_ADDRESS					0x40033000
#define	GPT_16_32_BIT_TIMER4_BASE_ADDRESS					0x40034000
#define	GPT_16_32_BIT_TIMER5_BASE_ADDRESS					0x40035000
#define	GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS				0x40036000
#define	GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS				0x40037000
#define	GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS				0x4004C000
#define	GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS				0x4004D000
#define	GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS				0x4004E000
#define	GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS				0x4004F000

#define GPTMCFG_OFFSET					0x000
#define GPTMTAMR_OFFSET					0x004
#define GPTMTBMR_OFFSET					0x008
#define GPTMCTL_OFFSET					0x00C
#define GPTMIMR_OFFSET					0x018
#define GPTMTAV_OFFSET					0x050
#define GPTMTAILR_OFFSET				0x028

#define GPTMCFG(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMCFG_OFFSET))
#define GPTMTAMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAMR_OFFSET))
#define GPTMTBMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTBMR_OFFSET))
#define GPTMCTL(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMCTL_OFFSET))	
#define GPTMIMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMIMR_OFFSET))
#define GPTMTAV(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAV_OFFSET))
#define GPTMTAILR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAILR_OFFSET))

#define TAEN 		                    0
#define TACDIR	                        4


#define APINT           				                   *((volatile uint32*)0xE000ED0C) //Application Interrupt and Reset Control
#define NVIC_BASE_ADDRESS					               0xE000E100 //Interrupt 0-31 Set Enable
#define NVIC_PRI_BASE_ADDRESS			                   0xE000E400 //Interrupt 0-3 Priority
#define GET_HWREG(BaseAddress,RegOffset)		           *((volatile uint32*)(BaseAddress+RegOffset))