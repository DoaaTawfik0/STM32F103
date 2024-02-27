#include  "STD_TYPES.h"
#include  "ERROR_STATE.h"
#include  "BIT_MATH.h"

#include  "STM32F103xx.h"

#include  "GPIO_Private.h"
#include  "GPIO_Interface.h"


/*An array For GPIO Peripherals Addresses*/
static GPIO_RegDef_t* GPIO_PORT[GPIO_PERIPHERAL_NUM] = {GPIO_PORTA  , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD , GPIO_PORTE};


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : GPIO_enu_PIN_Initialize.                              **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Pointer to struct of Type Pin Configuration.          **/
/** Functionality   : Initializing PIN Mode                                 **/
/*****************************************************************************/
/*****************************************************************************/
ES_t  GPIO_enu_PIN_Initialize(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig)
{

	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PIN_MODE_t Local_enuPinMode = Copy_Pstr_PinConfig->PIN_MODE;
	GPIO_PIN_NUM_t  Local_enuPin_ID  = Copy_Pstr_PinConfig->PIN_ID;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PinConfig->PORT_ID;

	if(Copy_Pstr_PinConfig != NULL)
	{
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			if(Local_enuPin_ID <= PIN7)
			{
				/*Clear Four bits before Setting it's Values*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_CRL &= ((~(GPIO_MASKING_CRL))<<(Local_enuPin_ID * CONFIG_REG_FOUR_BITS));
				/*Setting Four bits Values*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_CRL |= ((Local_enuPinMode)<<(Local_enuPin_ID * CONFIG_REG_FOUR_BITS));
				Local_enuErrorState = ES_OK;
			}
			else if(Local_enuPin_ID > PIN7)
			{
				Local_enuPin_ID -= EIGHT_VALUE;
				/*Clear Four bits before Setting it's Values*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_CRH &= ((~(GPIO_MASKING_CRH))<<(Local_enuPin_ID * CONFIG_REG_FOUR_BITS));
				/*Setting Four bits Values*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_CRH |= ((Local_enuPinMode)<<(Local_enuPin_ID * CONFIG_REG_FOUR_BITS));
				Local_enuErrorState = ES_OK;
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER ;
	}

	return Local_enuErrorState;
}


/*********************************************************************************/
/*********************************************************************************/
/** Function Name   : GPIO_enu_SetPinValue.                                   ****/
/** Return Type     : Error_State enum.                                       ****/
/** Arguments       : Pointer to struct of Type Pin Configuration && Pin_Val  ****/
/** Functionality   : Setting Value of Pin                                    ****/
/*********************************************************************************/
/*********************************************************************************/
ES_t  GPIO_enu_SetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , GPIO_PIN_VALUE_t Copy_enuPin_Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PIN_NUM_t  Local_enuPin_ID  = Copy_Pstr_PinConfig->PIN_ID;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PinConfig->PORT_ID;

	if(Copy_Pstr_PinConfig != NULL)
	{
		/*First Method: By Writing in ODR Direct*/
		/*
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			if(Copy_enuPin_Value  == HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR |= (GPIO_ODR_ONE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == LOW)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR &= (~(GPIO_ODR_ONE) << Local_enuPin_ID);
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
		 */

		/*Second Method: By Writing in BSRR*/
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			if(Copy_enuPin_Value  == HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_BSRR |= (ONE_VALUE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == LOW)
			{
				Local_enuPin_ID += SIXTEEN_VALUE;
				GPIO_PORT[Local_enuPort_ID]->GPIO_BSRR |= (ONE_VALUE << Local_enuPin_ID);
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

		/*
		//Third Method: Using BRR To reset pins & any method to set pins
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			if(Copy_enuPin_Value  == HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR |= (GPIO_ODR_ONE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == LOW)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_BRR |= (GPIO_BSRR_ONE << Local_enuPin_ID);
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
		 */
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : GPIO_enu_GetPinValue.                                              ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Pointer to struct of Type Pin Configuration & Pointer to Pin_Val   ****/
/** Functionality   : Getting Value of Pin                                               ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  GPIO_enu_GetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , u8* Copy_Pu8Pin_Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PIN_NUM_t  Local_enuPin_ID  = Copy_Pstr_PinConfig->PIN_ID;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PinConfig->PORT_ID;

	if((Copy_Pstr_PinConfig != NULL)&&(Copy_Pu8Pin_Value != NULL))
	{
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			*Copy_Pu8Pin_Value = ((GPIO_PORT[Local_enuPort_ID]->GPIO_IDR >> Local_enuPin_ID) & ONE_VALUE);
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


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : GPIO_enu_TogglePinValue.                            ****/
/** Return Type     : Error_State enum.                                   ****/
/** Arguments       : Pointer to struct of Type Pin Configuration         ****/
/** Functionality   : Toggling Value of Pin                               ****/
/*****************************************************************************/
/*****************************************************************************/
ES_t  GPIO_enu_TogglePinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PIN_NUM_t  Local_enuPin_ID  = Copy_Pstr_PinConfig->PIN_ID;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PinConfig->PORT_ID;

	if(Copy_Pstr_PinConfig != NULL)
	{
		if((Local_enuPort_ID <= PORTE) && (Local_enuPin_ID <= PIN15))
		{
			GPIO_PORT[Local_enuPort_ID]->GPIO_ODR ^= (ONE_VALUE << Local_enuPin_ID);
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





