/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 9, 2024          ****************/
/***********************************************************/
/***********************************************************/

#include "../Inc/STD_TYPES.h"
#include "../Inc/ERROR_STATE.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/STM32F103xx.h"
#include "../Inc/EXTI_Private.h"
#include "../Inc/EXTI_Interface.h"


/********************************************************/
/*********** Call_Back Functions          ***************/
/*******************************************************/
static volatile void (*Global_PFun_ISRFun)(void*) = NULL;
static volatile void (*Global_PV_ISRParameter) = NULL;




/****************************************************************************/
/****************************************************************************/
/** Function Name   : EXTI_enuInitialize.                                ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_pstrEXTI_Config                               ****/
/** Functionality   : Initialize EXTI Line                               ****/
/****************************************************************************/
/****************************************************************************/
ES_t  EXTI_enuInitialize(EXTI_CONFIG_t* Copy_pstrEXTI_Config)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_pstrEXTI_Config != NULL)
	{
		/*Local Variables to varry values inside struct*/
		EXTI_Edge_Trigger_t  Local_enuEXTI_EDGE  = Copy_pstrEXTI_Config->EXTI_EDGE;
		EXTI_Line_Num_t      Local_enuEXTI_Line  = Copy_pstrEXTI_Config->EXTI_Line;
		EXTI_State_t         Local_enuEXTI_State = Copy_pstrEXTI_Config->EXTI_State;
		EXTI_Type_t          Local_enuEXTI_Type  = Copy_pstrEXTI_Config->EXTI_Type;

		/*Cheek State of EXTI Line*/
		if(Local_enuEXTI_State == EXTI_ENABLE)
		{
			Local_enuErrorState = EXTI_enuEnable_EXTI(Local_enuEXTI_Line, Local_enuEXTI_Type);
		}
		else if(Local_enuEXTI_State == EXTI_DISABLE)
		{
			Local_enuErrorState = EXTI_enuDisable_EXTI(Local_enuEXTI_Line, Local_enuEXTI_Type);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		/*Setting Edge Trigger*/
		Local_enuErrorState |= EXTI_enuSet_Edge_Trigger(Local_enuEXTI_Line , Local_enuEXTI_EDGE);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}



/*************************************************************************************************************/
/*************************************************************************************************************/
/** Function Name   : EXTI_enuEnable_EXTI.                                                                ****/
/** Return Type     : Error_State enum.                                                                   ****/
/** Arguments       : Copy_enuEXTI_LINE , Copy_enuEXTI_Type                                               ****/
/** Functionality   : enable EXTI Line                                                                    ****/
/** this function takes EXTI type just to be able to access right register based on type(interrupt/event) ****/
/*************************************************************************************************************/
/*************************************************************************************************************/
ES_t  EXTI_enuEnable_EXTI(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Type_t Copy_enuEXTI_Type)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if(Copy_enuEXTI_Type == EXTI_INTERRUPT)
		{
			/*Setting Corresponding bit to enable EXTI Line @ EXTI_IMR*/
			EXTI->EXTI_IMR |= (ONE_VALUE << Copy_enuEXTI_LINE);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEXTI_Type == EXTI_EVENT)
		{
			/*Setting Corresponding bit to enable EXTI Line @ EXTI_EMR*/
			EXTI->EXTI_EMR |= (ONE_VALUE << Copy_enuEXTI_LINE);

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



/*************************************************************************************************************/
/*************************************************************************************************************/
/** Function Name   : EXTI_enuDisable_EXTI.                                                               ****/
/** Return Type     : Error_State enum.                                                                   ****/
/** Arguments       : Copy_enuEXTI_LINE , Copy_enuEXTI_Type                                               ****/
/** Functionality   : disable EXTI Line                                                                    ****/
/** this function takes EXTI type just to be able to access right register based on type(interrupt/event) ****/
/*************************************************************************************************************/
/*************************************************************************************************************/
ES_t  EXTI_enuDisable_EXTI(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Type_t Copy_enuEXTI_Type)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if(Copy_enuEXTI_Type == EXTI_INTERRUPT)
		{
			/*Clearing Corresponding bit to disable EXTI Line @ EXTI_IMR*/
			EXTI->EXTI_IMR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEXTI_Type == EXTI_EVENT)
		{
			/*Clearing Corresponding bit to disable EXTI Line @ EXTI_EMR*/
			EXTI->EXTI_EMR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));

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



/**********************************************************************************************************/
/**********************************************************************************************************/
/** Function Name   : EXTI_enuClear_Edge_Trigger.                                                      ****/
/** Return Type     : Error_State enum.                                                                ****/
/** Arguments       : Copy_enuEXTI_LINE , Copy_enuEdge_Trigger                                         ****/
/** Functionality   : Set Edge Trigger                                                                 ****/
/** this function takes Edge trigger type just to be able to access right register to enable trigger   ****/
/**********************************************************************************************************/
/**********************************************************************************************************/
ES_t  EXTI_enuSet_Edge_Trigger(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Edge_Trigger_t Copy_enuEdge_Trigger)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if(Copy_enuEdge_Trigger == EXTI_RISING_EDGE)
		{
			/*Enable Rising Edge for specific EXTI Line*/
			EXTI->EXTI_RTSR |= (ONE_VALUE << Copy_enuEXTI_LINE);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEdge_Trigger == EXTI_FALLING_EDGE)
		{
			/*Enable Falling Edge for specific EXTI Line*/
			EXTI->EXTI_FTSR |= (ONE_VALUE << Copy_enuEXTI_LINE);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEdge_Trigger == EXTI_RISING_FALLING_EDGE)
		{
			/*Enable Rising & Falling Edge for specific EXTI Line*/
			EXTI->EXTI_RTSR |= (ONE_VALUE << Copy_enuEXTI_LINE);
			EXTI->EXTI_FTSR |= (ONE_VALUE << Copy_enuEXTI_LINE);

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



/**********************************************************************************************************/
/**********************************************************************************************************/
/** Function Name   : EXTI_enuClear_Edge_Trigger.                                                      ****/
/** Return Type     : Error_State enum.                                                                ****/
/** Arguments       : Copy_enuEXTI_LINE , Copy_enuEdge_Trigger                                         ****/
/** Functionality   : Clear Edge Trigger                                                               ****/
/** this function takes Edge trigger type just to be able to access right register to disable trigger  ****/
/**********************************************************************************************************/
/**********************************************************************************************************/
ES_t  EXTI_enuClear_Edge_Trigger(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Edge_Trigger_t Copy_enuEdge_Trigger)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if(Copy_enuEdge_Trigger == EXTI_RISING_EDGE)
		{
			/*Disable Rising Edge for specific EXTI Line*/
			EXTI->EXTI_RTSR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEdge_Trigger == EXTI_FALLING_EDGE)
		{
			/*Disable Rising Edge for specific EXTI Line*/
			EXTI->EXTI_FTSR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuEdge_Trigger == EXTI_RISING_FALLING_EDGE)
		{
			/*Disable Rising & Falling Edge for specific EXTI Line*/
			EXTI->EXTI_RTSR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));
			EXTI->EXTI_FTSR &= (~(ONE_VALUE << Copy_enuEXTI_LINE));

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



/************************************************************************************************/
/************************************************************************************************/
/** Function Name   : EXTI_enuSW_Interrupt.                                                  ****/
/** Return Type     : Error_State enum.                                                      ****/
/** Arguments       : Copy_enuEXTI_LINE                                                      ****/
/** Functionality   : enable Software Interrupt                                              ****/
/** If the interrupt is enabled on this line in the EXTI_IMR
 *  writing '1' to this bit sets the corresponding pending bit in EXTI_PR
 *  resulting in an interrupt request generation.
 *  >>This bit will be cleared by writing 1 into corresponding bit @ EXTI_PR                 ****/
/************************************************************************************************/
/************************************************************************************************/
ES_t  EXTI_enuSW_Interrupt(EXTI_Line_Num_t Copy_enuEXTI_LINE)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		/*Setting Corresponding bit to specific EXTI Line @ EXTI_SWIER*/
		EXTI->EXTI_SWIER |= (ONE_VALUE << Copy_enuEXTI_LINE);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/************************************************************************************************/
/************************************************************************************************/
/** Function Name   : EXTI_enuGet_Pending_Flag.                                              ****/
/** Return Type     : Error_State enum.                                                      ****/
/** Arguments       : Copy_enuEXTI_LINE                                                      ****/
/** Functionality   : Get bending Flag                                                       ****/
/** Each bit in the EXTI_PR register corresponds to a specific external interrupt line.
 *  When an interrupt event occurs on a particular line, the corresponding bit is set
 *  to indicate that the interrupt is pending                                                ****/
/************************************************************************************************/
/************************************************************************************************/
ES_t  EXTI_enuGet_Pending_Flag(EXTI_Line_Num_t Copy_enuEXTI_LINE , u8* Copy_pu8PendingState)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		if(Copy_pu8PendingState != NULL)
		{
			/*Reading Corresponding bit @ EXTI_PR to see if EXTI is in pending state or not*/
			*Copy_pu8PendingState = ((EXTI->EXTI_PR >> Copy_enuEXTI_LINE)&ONE_VALUE);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/************************************************************************************************/
/************************************************************************************************/
/** Function Name   : EXTI_enuClear_Pending_Flag.                                            ****/
/** Return Type     : Error_State enum.                                                      ****/
/** Arguments       : Copy_enuEXTI_LINE                                                      ****/
/** Functionality   : Clear bending Flag                                                     ****/
/**                   bending flag must be cleared inside ISR                                ****/
/************************************************************************************************/
/************************************************************************************************/
ES_t  EXTI_enuClear_Pending_Flag(EXTI_Line_Num_t Copy_enuEXTI_LINE)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE >= EXTI_LINE_0) && (Copy_enuEXTI_LINE <= EXTI_LINE_18))
	{
		/*Clearing Corresponding bit @ EXTI_PR by writing one into bit*/
		EXTI->EXTI_PR |= (ONE_VALUE << Copy_enuEXTI_LINE);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/************************************************************************************************/
/************************************************************************************************/
/** Function Name   : EXTI_enuCallBack_Function.                                             ****/
/** Return Type     : Error_State enum.                                                      ****/
/** Arguments       : Copy_Pfun_AppFun , Copy_PV_AppParameter                                ****/
/** Functionality   : receive Call_back function from APP Layer                              ****/
/** this Function should be called before enabling EXTI even before initialization function  ****/
/************************************************************************************************/
/************************************************************************************************/
ES_t  EXTI_enuCallBack_Function(void(*Copy_Pfun_AppFun)(void*) , void* Copy_PV_AppParameter)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_Pfun_AppFun != NULL)
	{

		Global_PFun_ISRFun = Copy_Pfun_AppFun;
		Global_PV_ISRParameter = Copy_PV_AppParameter;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

/*********************************************************************************************************/
/*********************************             EXTI Handlers             *********************************/
/*********************************************************************************************************/
/* EXTI Line0 Handler*/
void EXTI0_IRQHandler(void)
{

}


/*EXTI Line1 Handler*/
void EXTI1_IRQHandler(void)
{

}


/*EXTI Line2 Handler*/
void EXTI2_IRQHandler(void)
{

}


/*EXTI Line3 Handler*/
void EXTI3_IRQHandler(void)
{

}


/*EXTI Line4 Handler*/
void EXTI4_IRQHandler(void)
{

}


/*EXTI Line[5-9] Handler*/
void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI->EXTI_PR , Bit_5) == 1)
	{
		/*here we should call call_back function && clear bending flag*/
	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_6) == 1)
	{

	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_7) == 1)
	{

	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_8) == 1)
	{

	}
	else
	{

	}
}


/*EXTI Line[10-15] Handler*/
void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI->EXTI_PR , Bit_10) == 1)
	{
		/*here we should call call_back function && clear bending flag*/
	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_11) == 1)
	{

	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_12) == 1)
	{

	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_13) == 1)
	{

	}
	else if(GET_BIT(EXTI->EXTI_PR , Bit_14) == 1)
	{

	}
	else
	{

	}

}


/*RTC Alarms through EXTI line Handler*/
void RTCAlarm_IRQHandler(void)
{

}


/*PVD through EXTI line detection Handler*/
void PVD_IRQHandler(void)
{


}





















