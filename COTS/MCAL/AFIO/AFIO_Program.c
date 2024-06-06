/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:June 6, 2024         ****************/
/***********************************************************/
/***********************************************************/

#include   "../Inc/STD_TYPES.h"
#include   "../Inc/ERROR_STATE.h"
#include   "../Inc/BIT_MATH.h"

#include   "../Inc/STM32F103xx.h"
#include   "../Inc/GPIO_Interface.h"
#include   "../Inc/EXTI_Interface.h"

#include   "../Inc/AFIO_Private.h"
#include   "../Inc/AFIO_Interface.h"


/************************************************************************************************/
/************************************************************************************************/
/** Function Name   : AFIO_enuSet_EXTI_Port.                                                 ****/
/** Return Type     : Error_State enum.                                                      ****/
/** Arguments       : Copy_enuEXTI_LINE , Copy_enuPort_ID                                    ****/
/** Functionality   : Selecting Port to work with while using EXTI Lines                     ****/
/** EXTI Line also equal pin nnumber for example->EXTI_Line12 == PIN12 @ given Port          ****/
/** Technically this function should be @ AFIO Driver                                        ****/
/************************************************************************************************/
/************************************************************************************************/
ES_t  AFIO_enuSet_EXTI_Port(EXTI_Line_Num_t Copy_enuEXTI_LINE , GPIO_PORT_NUM_t Copy_enuPort_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if((Copy_enuPort_ID >= PORTA) && (Copy_enuPort_ID <= PORTG))
		{
			/*Calculating Reg Number to specify which register from EXTICR we will deal with*/
			u8 Local_u8Reg_Num   = Copy_enuEXTI_LINE/FOUR_VALUE;
			/*Calculating start bit @ EXTICR Register*/
			u8 Local_u8Start_Bit = ((Copy_enuEXTI_LINE%FOUR_VALUE)*FOUR_VALUE);

			/*Selecting Port to work with while using EXTI Lines*/
			AFIO->AFIO_EXTICR[Local_u8Reg_Num] |= (Copy_enuPort_ID << Local_u8Start_Bit);

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


