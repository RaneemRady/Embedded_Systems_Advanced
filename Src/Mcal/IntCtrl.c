/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "Registers.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define NVIC_GROUPING_SYSTEM_XXX    4
#define NVIC_GROUPING_SYSTEM_XXY    5
#define NVIC_GROUPING_SYSTEM_XYY    6
#define NVIC_GROUPING_SYSTEM_YYY    7

#define APINT_VECTKEY                0x05FA
#define PRIGROUP_FIELD_OFFSET        0x8u
#define APINT_VECTKEY_FIELD_OFFSET   16u
#define NVIC_REG_NUM_OF_PRI_FIELDS   4u
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void IntCrtl_Init(void)
{

   Nvic_IntType intNum;
	uint8 locGroup, locSubGroup,i,locGroupingField;
	uint32 enRegOffset, enBitOffset;
	uint32 priRegOffset, priBitOffset;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	/*To write to this register, 0x05FA must be written to
     the VECTKEY field, otherwise the write is ignored.*/
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIELD_OFFSET)              //VECTKEY
					|(NVIC_GROUPING_SYSTEM << PRIGROUP_FIELD_OFFSET);//PRIGROUP
	
	for(i=0; i< NVIC_ACTIVATED_INT_SIZE ;i++)
	{
		intNum			= Nvic_Cfg[i].interruptNumber;
		locGroup		= Nvic_Cfg[i].groupPriority;
		locSubGroup = Nvic_Cfg[i].subgroupPriority;
		
		/* enable\disable based on user configuration */
		enRegOffset = (intNum/WORD_LENGTH_BITS)*WORD_LENGTH_BYTES;
		enBitOffset = intNum%WORD_LENGTH_BITS;
			
		GET_HWREG(NVIC_BASE_ADDRESS,enRegOffset) |= (1 << enBitOffset);
				
		
#if NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX //groups 0:7
			locGroupingField = locGroup;
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY //groups 0:3
			locGroupingField = ((locGroup<<1)&0x6) | (locSubGroup&0x1);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY// groups 0:2
        locGroupingField = ((locGroup<<2)&0x4) | (locSubGroup&0x3);
			
#elif NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY //group 0 non pre-emptible
        locGroupingField = locGroup;
#else
     #error INVALID GROUPING SELECTION			
#endif
			
			/* asign group\subgroup priority */
		
			priRegOffset = (intNum/NVIC_REG_NUM_OF_PRI_FIELDS)*WORD_LENGTH_BYTES;//offset 0x10 : Interrupt 16-19 Priority 
			priBitOffset = 5 + (8 * (intNum%NVIC_REG_NUM_OF_PRI_FIELDS));//offset 29 for interrupt 19
			GET_HWREG(NVIC_PRI_BASE_ADDRESS,priRegOffset) |= (locGroupingField << priBitOffset);//assign group priority
	}
	
}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
