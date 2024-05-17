/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 17, 2024         ****************/
/***********************************************************/
/***********************************************************/

#include  "../Inc/STD_TYPES.h"
#include  "../Inc/ERROR_STATE.h"
#include  "../Inc/BIT_MATH.h"

#include  "../Inc/STM32F103xx.h"
#include  "../Inc/SCB_Private.h"
#include  "../Inc/SCB_Interface.h"




/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuSet_NMI_Pending_bit.                        ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : void                                               ****/
/** Functionality   : Set NMI Pending Flag from ICSR Register            ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuSet_NMI_Pending_bit(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SCB->SCB_ICSR |= (ONE_VALUE << Bit_31);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuSet_PendSV_Pending_bit.                     ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : void                                               ****/
/** Functionality   : Set PendSV Pending Flag from ICSR Register         ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuSet_PendSV_Pending_bit(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SCB->SCB_ICSR |= (ONE_VALUE << Bit_28);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuClear_PendSV_Pending_bit.                   ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : void                                               ****/
/** Functionality   : Clear PendSV Pending Flag from ICSR Register       ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuClear_PendSV_Pending_bit(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SCB->SCB_ICSR |= (ONE_VALUE << Bit_27);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuSet_SysTick_Pending_bit.                    ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : void                                               ****/
/** Functionality   : Set SysTick Pending Flag from ICSR Register        ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuSet_SysTick_Pending_bit(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SCB->SCB_ICSR |= (ONE_VALUE << Bit_26);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuClear_SysTick_Pending_bit.                  ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : void                                               ****/
/** Functionality   : Clear SysTick Pending Flag from ICSR Register      ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuClear_SysTick_Pending_bit(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	SCB->SCB_ICSR |= (ONE_VALUE << Bit_25);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SCB_enuSet_PRIGROUP.                               ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuPRIGROUP                                   ****/
/** Functionality   : Set Priority Group from AIRCR Register             ****/
/**  ->defines which bits used for group_priority/sub_priority           ****/
/****************************************************************************/
/****************************************************************************/
ES_t   SCB_enuSet_PRIGROUP(SCB_PRIGROUP_t Copy_enuPRIGROUP)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Register Key*/
	u32 Local_u32PRIGROUP = (VECTKEY << Bit_16);

	if((Copy_enuPRIGROUP >= SCB_PRIGROUP_4) && (Copy_enuPRIGROUP <= SCB_PRIGROUP_7))
	{
		Local_u32PRIGROUP |= (Copy_enuPRIGROUP << Bit_8);

		SCB->SCB_AIRCR = Local_u32PRIGROUP;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/*****************************************************************************************************************/
/*****************************************************************************************************************/
/** Function Name   : SCB_enuSet_Exception_Prority.                                                           ****/
/** Return Type     : Error_State enum.                                                                       ****/
/** Arguments       : Copy_enuException , Copy_enuPriority                                                    ****/
/** Functionality   : Set Priority for exception handlers that have configurable priority frm SHPR register   ****/
/**  ->like: UsageFault,BusFault,MemManage,SVCall,PendSV,SysTick Exceptions                                   ****/
/*****************************************************************************************************************/
/*****************************************************************************************************************/
ES_t   SCB_enuSet_Exception_Prority(SCB_Exception_Type_t Copy_enuException  , SCB_Exception_Priority_t Copy_enuPriority)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuPriority >= PRIORITY_ZERO) && (Copy_enuPriority <= PRIORITY_FIFTEEN))
	{

		if(Copy_enuException == MemManage_Exception)
		{
			/*Last 4 bits of first byte are the implemented bits for priority*/
			SCB->SCB_SHPR[0] |= (Copy_enuPriority << Bit_4);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuException == BusFault_Exception)
		{
			/*Last 4 bits of second byte(in SHPR1) are the implemented bits for priority*/
			SCB->SCB_SHPR[0] |= (Copy_enuPriority << Bit_12);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuException == UsageFault_Exception)
		{
			/*Last 4 bits of third byte(in SHPR1) are the implemented bits for priority*/
			SCB->SCB_SHPR[0] |= (Copy_enuPriority << Bit_20);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuException == SVCall_Exception)
		{
			/*Last 4 bits of fourth byte(in SHPR2) are the implemented bits for priority*/
			SCB->SCB_SHPR[1] |= (Copy_enuPriority << Bit_28);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuException == PendSV_Exception)
		{
			/*Last 4 bits of third byte(in SHPR3) are the implemented bits for priority*/
			SCB->SCB_SHPR[2] |= (Copy_enuPriority << Bit_20);

			Local_enuErrorState = ES_OK;
		}
		else if (Copy_enuException == SysTick_Exception)
		{
			/*Last 4 bits of fourth byte(in SHPR3) are the implemented bits for priority*/
			SCB->SCB_SHPR[2] |= (Copy_enuPriority << Bit_28);

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



