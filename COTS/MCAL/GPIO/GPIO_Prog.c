/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Updated on: May 4, 2024   ****************/
/***********************************************************/
/***********************************************************/



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
			/*Check if Pin_Mode I/P Pull_Up or Pull_Down */
			if(Local_enuPinMode == PIN_INPUT_PULL_UP)
			{
				/*Getting Red Of extra bit in PIN_INPUT_PULL_UP that used to differ between Pull_Up & Pull_Down*/
				Local_enuPinMode -=16;
				/*Activate Pull Up by Setting Corresponding bit in ODR*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR |= (ONE_VALUE << Local_enuPin_ID);
			}
			else if(Local_enuPinMode == PIN_INPUT_PULL_DOWN)
			{
				/*Activate Pull Down by Clearing Corresponding bit in ODR*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR &= ~(ONE_VALUE << Local_enuPin_ID);
			}
			else
			{
				/*Do Nothing*/
			}

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
				Local_enuErrorState = ES_OUT_OF_RANGE;
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


/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : GPIO_enu_PORT_Initialize.                               **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Pointer to struct of Type port Configuration.           **/
/** Functionality   : Initializing port Mode                                  **/
/*******************************************************************************/
/*******************************************************************************/
ES_t  GPIO_enu_PORT_Initialize(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	GPIO_PORT_MODE_t Local_enuPortMode = Copy_Pstr_PortConfig->PORT_MODE;
	GPIO_PORT_NUM_t  Local_enuPort_ID  = Copy_Pstr_PortConfig->PORT_ID;

	if(Copy_Pstr_PortConfig != NULL)
	{
		if(Local_enuPort_ID <= PORTE)
		{
			/*Check if Port_Mode Input Pull_Up or Pull_Down */
			if(Local_enuPortMode == PORT_INPUT_PULL_UP)
			{
				/*Getting Red Of extra bit in PORT_INPUT_PULL_UP that used to differ between Pull_Up & Pull_Down*/
				Local_enuPortMode--;
				/*Activate Pull Up by Setting all bits @ ODR*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR = PORT_HIGH;
			}
			else if(Local_enuPortMode == PORT_INPUT_PULL_DOWN)
			{
				/*Activate Pull Down by Clearing all bits @ ODR*/
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR = PORT_LOW;
			}
			else
			{
				/*Do Nothing*/
			}
			/*Setting CRL & CRH Registers with Port_Mode Values*/
			GPIO_PORT[Local_enuPort_ID]->GPIO_CRL  = Local_enuPortMode;
			GPIO_PORT[Local_enuPort_ID]->GPIO_CRL |= (Local_enuPortMode << 16);
			GPIO_PORT[Local_enuPort_ID]->GPIO_CRH  = Local_enuPortMode;
			GPIO_PORT[Local_enuPort_ID]->GPIO_CRL |= (Local_enuPortMode << 16);

			Local_enuErrorState = ES_OK;

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
			if(Copy_enuPin_Value  == PIN_HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR |= (GPIO_ODR_ONE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == PIN_LOW)
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
			if(Copy_enuPin_Value  == PIN_HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_BSRR |= (ONE_VALUE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == PIN_LOW)
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
			if(Copy_enuPin_Value  == PIN_HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR |= (GPIO_ODR_ONE << Local_enuPin_ID);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPin_Value  == PIN_LOW)
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


/***********************************************************************************/
/***********************************************************************************/
/** Function Name   : GPIO_enu_SetPortValue.                                    ****/
/** Return Type     : Error_State enum.                                         ****/
/** Arguments       : Pointer to struct of Type port Configuration && Port_Val  ****/
/** Functionality   : Setting Value of Port                                     ****/
/***********************************************************************************/
/***********************************************************************************/
ES_t  GPIO_enu_SetPortValue(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig , GPIO_PORT_VALUE_t Copy_enuPort_Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PortConfig->PORT_ID;

	if(Copy_Pstr_PortConfig != NULL)
	{
		if(Local_enuPort_ID <= PORTE)
		{
			if(Copy_enuPort_Value  == PORT_HIGH)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR = PORT_HIGH;
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_enuPort_Value  == PORT_LOW)
			{
				GPIO_PORT[Local_enuPort_ID]->GPIO_ODR = PORT_LOW;
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

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}


/**********************************************************************************************/
/**********************************************************************************************/
/** Function Name   : GPIO_enu_GetPortValue.                                               ****/
/** Return Type     : Error_State enum.                                                    ****/
/** Arguments       : Pointer to struct of Type port Configuration & Pointer to Port_Val   ****/
/** Functionality   : Getting Value of port                                                ****/
/**********************************************************************************************/
/**********************************************************************************************/
ES_t  GPIO_enu_GetPortValue(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig , u16* Copy_Pu16Port_Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_PORT_NUM_t Local_enuPort_ID = Copy_Pstr_PortConfig->PORT_ID;

	if((Copy_Pstr_PortConfig != NULL)&&(Copy_Pu16Port_Value != NULL))
	{
		if(Local_enuPort_ID <= PORTE)
		{
			/*Read first 16 bits & doing masking to last 16 bits*/
			*Copy_Pu16Port_Value = (GPIO_PORT[Local_enuPort_ID]->GPIO_IDR&GPIO_MASKING_IDR);
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









