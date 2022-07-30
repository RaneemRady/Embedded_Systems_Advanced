/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum            /*List All Interrupts */
{
	NVIC_GPIO_PORT_A = 0 			,
	NVIC_GPIO_PORT_B     			,
	NVIC_GPIO_PORT_C     			,
	NVIC_GPIO_PORT_D     			,
	NVIC_GPIO_PORT_E     			,
				
	NVIC_UART_0         			,
	NVIC_UART_1         			,
				
	NVIC_SSI_0          			,
				
	NVIC_I2C_0          			,
				
	NVIC_PWM_0_FAULT    			,
	NVIC_PWM_0_GEN_0    			,
	NVIC_PWM_0_GEN_1    			,
	NVIC_PWM_0_GEN_2    			,
				
	NVIC_QEI_0          			,
				
	NVIC_ADC_0_SEQ_0    			,
	NVIC_ADC_0_SEQ_1    			,
	NVIC_ADC_0_SEQ_2    			,
	NVIC_ADC_0_SEQ_3    			,
	
	NVIC_TIMER_WATCHDOG_0_1    		,
	NVIC_16_32_TIMER_0_A      		,
	NVIC_16_32_TIMER_0_B      		,
	NVIC_16_32_TIMER_1_A      		,
	NVIC_16_32_TIMER_1_B      		,
	NVIC_16_32_TIMER_2_A      		,
	NVIC_16_32_TIMER_2_B      		,
	
	NVIC_ANALOG_COMPARATOR_0   		,
	NVIC_ANALOG_COMPARATOR_1   		,
	
	/*Reserved*/
	
	NVIC_SYSTEM_CONTROL = 28   		,
	
	NVIC_FLASH_EEPROM_MEMORY_CONTROL,
	
	NVIC_DIO_PORT_F    			 	,
	
	/*Reserved*/
	
	NVIC_UART_2 = 33   				,
	
	NVIC_SSI_1         				,
	
	NVIC_16_32_TIMER_3_A     		,
	NVIC_16_32_TIMER_3_B     		,
	
	NVIC_I2C_1         				,
	
	NVIC_QEI_1         				,
	
	NVIC_CAN_0         				,
	NVIC_CAN_1         				,
	
	/*Reserved*/

	NVIC_HIBERNATION = 43 			,
	
	NVIC_USB           				,
					
	NVIC_PWM_GEN_3     				,
					
	NVIC_UDMA_SOFTWARE 				,
	NVIC_UDMA_ERROR    				,
					
	NVIC_ADC_1_SEQ_0   				,
	NVIC_ADC_1_SEQ_1   				,
	NVIC_ADC_1_SEQ_2   				,
	NVIC_ADC_1_SEQ_3   				,
	
	/*Reserved*/
	
	NVIC_SSI_2 = 57    				,
	NVIC_SSI_3         				,
					
	NVIC_UART_3        				,
	NVIC_UART_4        				,
	NVIC_UART_5        				,
	NVIC_UART_6        				,
	NVIC_UART_7        				,
	
	/*Reserved*/
	
	NVIC_I2C_2 = 68    				,
	NVIC_I2C_3         				,
	
	NVIC_16_32_TIMER_4_A     		,
	NVIC_16_32_TIMER_4_B     		,
	
	/*Reserved*/
	
	NVIC_16_32_TIMER_5_A = 92		,
	NVIC_16_32_TIMER_5_B     		,
	NVIC_32_64_TIMER_0_A     		,
	NVIC_32_64_TIMER_0_B     		,
	NVIC_32_64_TIMER_1_A     		,
	NVIC_32_64_TIMER_1_B     		,
	NVIC_32_64_TIMER_2_A     		,
	NVIC_32_64_TIMER_2_B     		,
	NVIC_32_64_TIMER_3_A     		,
	NVIC_32_64_TIMER_3_B     		,
	NVIC_32_64_TIMER_4_A     		,
	NVIC_32_64_TIMER_4_B     		,
	NVIC_32_64_TIMER_5_A     		,
	NVIC_32_64_TIMER_5_B     		,
	
	NVIC_SYSTEM_EXCEPTION    		,
	
	/*Reserved*/
	
	NVIC_PWM_1_GEN_0 = 134   		,
	NVIC_PWM_1_GEN_1         		,
	NVIC_PWM_1_GEN_2         		,
	NVIC_PWM_1_GEN_3         		,
	NVIC_PWM_1_FAULT
	
}Nvic_IntType;

typedef struct
{
	Nvic_IntType interruptNumber;
	uint8        groupPriority;
	uint8        subgroupPriority;
	
}Nvic_CfgType;

 




 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 extern const Nvic_CfgType Nvic_Cfg[];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
