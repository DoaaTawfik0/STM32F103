/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 6, 2024          ****************/
/***********************************************************/
/***********************************************************/

#include "../Inc/STD_TYPES.h"
#include "../Inc/ERROR_STATE.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/STM32F103xx.h"
#include "../Inc/NVIC_Interface.h"
#include "../Inc/NVIC_Private.h"

ES_t  NVIC_enuEnable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{






	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



ES_t  NVIC_enuDisable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{






	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



ES_t  NVIC_enuSetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{






	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}




ES_t  NVIC_enuClearPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{






	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}




ES_t  NVIC_enuGetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Pending_Flag)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu8Pending_Flag != NULL)
	{
		if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
		{






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



ES_t  NVIC_enuSetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32 Copy_u32Priority)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
	{






	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



ES_t  NVIC_enuGetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Prority)
{
		ES_t Local_enuErrorState = ES_NOK;

		if(Copy_pu32Prority != NULL)
		{
			if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
			{






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



ES_t  NVIC_enuGetActive_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Active_IRQ)
{
		ES_t Local_enuErrorState = ES_NOK;

		if(Copy_pu32Active_IRQ != NULL)
		{
			if((Copy_enuIRQ_NUM >= WWDG_INT) && (Copy_enuIRQ_NUM <= DMA2_Channel4_5_INT))
			{






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
