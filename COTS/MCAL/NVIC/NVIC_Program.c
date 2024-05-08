/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 8, 2024          ****************/
/***********************************************************/
/***********************************************************/

#include "../Inc/STD_TYPES.h"
#include "../Inc/ERROR_STATE.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/STM32F103xx.h"
#include "../Inc/NVIC_Interface.h"
#include "../Inc/NVIC_Private.h"



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuEnable_IRQ.                                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM                                                    ****/
/** Functionality   : Enable Interrupt Line for specific INT_REQ                         ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuEnable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{

		u32 Local_u32Reg_Num , Local_u32Bit_Num;

		/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
		Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
		Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
		/*Enable Interrupt*/
		NVIC->NVIC_ISER[Local_u32Reg_Num] |= (ONE_VALUE << Local_u32Bit_Num);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuDisable_IRQ.                                               ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM                                                    ****/
/** Functionality   : Disable Interrupt Line for specific INT_REQ                        ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuDisable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{

		u32 Local_u32Reg_Num , Local_u32Bit_Num;

		/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
		Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
		Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
		/*Disable Interrupt*/
		NVIC->NVIC_ICER[Local_u32Reg_Num] |= (ONE_VALUE << Local_u32Bit_Num);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuGetEnabledINT_IRQ.                                         ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM , Copy_pu8Enabled_INT                              ****/
/** Functionality   : Get Enabled Interrupt Request                                      ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuGetEnabledINT_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Enabled_INT)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_pu8Enabled_INT != NULL)
	{
		if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
		{

			u32 Local_u32Reg_Num , Local_u32Bit_Num;

			/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
			Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
			Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);

			*Copy_pu8Enabled_INT = (((NVIC->NVIC_ISER[Local_u32Reg_Num]) >> Local_u32Bit_Num)&ONE_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuSetPendingFlag_IRQ.                                        ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM                                                    ****/
/** Functionality   : Set Pending Flag For Specific Interrupt Request                    ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuSetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{

		u32 Local_u32Reg_Num , Local_u32Bit_Num;

		/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
		Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
		Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
		/*change interrupt state to pending*/
		NVIC->NVIC_ISPR[Local_u32Reg_Num] |= (ONE_VALUE << Local_u32Bit_Num);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuClearPendingFlag_IRQ.                                      ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM                                                    ****/
/** Functionality   : Clear Pending Flag For Specific Interrupt Request                  ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuClearPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{

		u32 Local_u32Reg_Num , Local_u32Bit_Num;

		/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
		Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
		Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
		/*Clearing Pending Flag*/
		NVIC->NVIC_ICPR[Local_u32Reg_Num] |= (ONE_VALUE << Local_u32Bit_Num);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuGetPendingFlag_IRQ.                                        ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM , Copy_pu8Pending_Flag                             ****/
/** Functionality   : Get Pending Flag For Specific Interrupt Request                    ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuGetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Pending_Flag)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu8Pending_Flag != NULL)
	{
		if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
		{

			u32 Local_u32Reg_Num , Local_u32Bit_Num;

			/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
			Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
			Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
			/*Get Pending Flag of Interrupt Request*/
			*Copy_pu8Pending_Flag = (((NVIC->NVIC_ISPR[Local_u32Reg_Num]) >> Local_u32Bit_Num)&ONE_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuGetPendingFlag_IRQ.                                        ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM , Copy_pu32Active_IRQ                              ****/
/** Functionality   : Get Active Flag For Specific Interrupt Request                     ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuGetActive_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Active_IRQ)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu32Active_IRQ != NULL)
	{
		if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
		{

			u32 Local_u32Reg_Num , Local_u32Bit_Num;

			/*Calculating Reg_Num & Bit_Num using IRQ_NUM*/
			Local_u32Reg_Num = Copy_enuIRQ_NUM/REGISTER_SIZE;
			Local_u32Bit_Num = Copy_enuIRQ_NUM-(Local_u32Reg_Num*REGISTER_SIZE);
			/*Get Indication For Active Interruot*/
			*Copy_pu32Active_IRQ = (((NVIC->NVIC_IABR[Local_u32Reg_Num]) >> Local_u32Bit_Num)&ONE_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuSetPriority_IRQ.                                           ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM , Copy_u32Priority                                 ****/
/** Functionality   : Set Priority of Specific Interrupt                                 ****/
/**                   (Through Priority we Should  Priority group & Sub_Priority)         ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuSetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32 Copy_u32Priority)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{
		if((Copy_u32Priority >= PRIORITY_ZERO) && (Copy_u32Priority <= PRIORITY_FIFTEEN))
		{
			/*Setting given Priority to specific Interrupt*/
			/*Priority shiftted Four bits because only last four bits are implemented*/
			NVIC->NVIC_IPR[Copy_enuIRQ_NUM] = (Copy_u32Priority << FOUR_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : NVIC_enuGetPriority_IRQ.                                           ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuIRQ_NUM , Copy_pu32Prority                                 ****/
/** Functionality   : Get Priority of Specific Interrupt                                 ****/
/**                   (From Priority we will know Priority group & Sub_Priority)         ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  NVIC_enuGetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Prority)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu32Prority != NULL)
	{
		if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
		{

			/*Reading IPR to get Priority for specific Interrupt*/
			/*Priority shiftted Four bits because only last four bits are implemented*/
			*Copy_pu32Prority = (NVIC->NVIC_IPR[Copy_enuIRQ_NUM]>>FOUR_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
