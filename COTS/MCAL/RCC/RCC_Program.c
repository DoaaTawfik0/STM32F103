/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Created on: Mar 7, 2024   ****************/
/***********************************************************/
/***********************************************************/

#include  "../Inc/STD_TYPES.h"
#include  "../Inc/ERROR_STATE.h"
#include  "../Inc/BIT_MATH.h"

#include  "../Inc/STM32F103xx.h"
#include  "../Inc/RCC_Private.h"
#include  "../Inc/RCC_Interface.h"


/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuSelect_SYSCLK.                                              ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuSYSCLK_ID->SYSCLK_ID(HSE-HSI-PLL)                          ****/
/** Functionality   : Setting System Clock                                               ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuSelect_SYSCLK(RCC_SYSCLK_t  Copy_enuSYSCLK_ID)
{
	ES_t  Local_enuErrorState  = ES_NOK;

	if(Copy_enuSYSCLK_ID == HSI_SYSCLK)
	{
		/*Polling->Waiting until HSI Become Ready*/
		while(!((RCC->RCC_CR>>Bit_1) & ONE_VALUE));
		/*Setting First 2 bits with value zero*/
		RCC->RCC_CFGR |= (HSI_SYSCLK);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuSYSCLK_ID == HSE_SYSCLK)
	{
		/*Polling->Waiting until HSE Become Ready*/
		while(!((RCC->RCC_CR>>Bit_17) & ONE_VALUE));
		/*Setting First 2 bits with value One*/
		RCC->RCC_CFGR |= (HSE_SYSCLK);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuSYSCLK_ID == PLL_SYSCLK)
	{
		/*Polling->Waiting until PLL Become Ready*/
		while(!((RCC->RCC_CR>>Bit_25) & ONE_VALUE));
		/*Setting First 2 bits with value Two*/
		RCC->RCC_CFGR |= (PLL_SYSCLK);
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
/** Function Name   : RCC_enuHSI_Enable.                                                 ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Enable HSI Clock                                                   ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuHSI_Enable()
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR |= (ONE_VALUE<<Bit_0);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuHSE_Enable.                                                 ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Enable HSE Clock                                                   ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuHSE_Enable(void)
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR |= (ONE_VALUE<<Bit_16);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuPLL_Enable.                                                 ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Enable PLL Clock                                                   ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuPLL_Enable()
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR |= (ONE_VALUE<<Bit_24);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuHSI_Disable.                                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Disable HSI Clock                                                  ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuHSI_Disable()
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR &= ~(ONE_VALUE<<Bit_0);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuHSE_Disable.                                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Disable HSE Clock                                                  ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuHSE_Disable()
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR &= ~(ONE_VALUE<<Bit_16);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuPLL_Disable.                                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Disable PLL Clock                                                  ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuPLL_Disable()
{
	ES_t  Local_enuErrorState  = ES_NOK;

	RCC->RCC_CR &= ~(ONE_VALUE<<Bit_24);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuEnable_AHB_Peripherals_CLK.                                 ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_AHB_Peripheral_ID                                         ****/
/** Functionality   : Enable Clock of Any AHB Peripheral                                 ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuEnable_AHB_Peripherals_CLK(RCC_AHB_PERIPHERAL_ID_t Copy_enu_AHB_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Enable AHB Peripheral Clock*/
	RCC->RCC_AHBENR |= (ONE_VALUE << Copy_enu_AHB_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuEnable_APB2_Peripherals_CLK.                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_APB2_Peripheral_ID                                        ****/
/** Functionality   : Enable Clock of Any APB2 Peripheral                                ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuEnable_APB2_Peripherals_CLK(RCC_APB2_PERIPHERAL_ID_t Copy_enu_APB2_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Enable APB2 Peripheral Clock*/
	RCC->RCC_APB2ENR |= (ONE_VALUE << Copy_enu_APB2_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuEnable_APB1_Peripherals_CLK.                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_APB1_Peripheral_ID                                        ****/
/** Functionality   : Enable Clock of Any APB1 Peripheral                                ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuEnable_APB1_Peripherals_CLK(RCC_APB1_PERIPHERAL_ID_t Copy_enu_APB1_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Enable APB1 Peripheral Clock*/
	RCC->RCC_APB1ENR |= (ONE_VALUE << Copy_enu_APB1_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuDisable_AHB_Peripherals_CLK.                                ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_AHB_Peripheral_ID                                         ****/
/** Functionality   : Disable Clock of Any AHB Peripheral                                ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuDisable_AHB_Peripherals_CLK(RCC_AHB_PERIPHERAL_ID_t Copy_enu_AHB_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Disable AHB Peripheral Clock*/
	RCC->RCC_AHBENR &= ~(ONE_VALUE << Copy_enu_AHB_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuDisable_APB2_Peripherals_CLK.                               ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_APB2_Peripheral_ID                                        ****/
/** Functionality   : Disable Clock of Any APB2 Peripheral                               ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuDisable_APB2_Peripherals_CLK(RCC_APB2_PERIPHERAL_ID_t Copy_enu_APB2_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Disable APB2 Peripheral Clock*/
	RCC->RCC_APB2ENR &= ~(ONE_VALUE << Copy_enu_APB2_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuDisable_APB1_Peripherals_CLK.                               ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enu_APB1_Peripheral_ID                                        ****/
/** Functionality   : Disable Clock of Any APB1 Peripheral                                ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuDisable_APB1_Peripherals_CLK(RCC_APB1_PERIPHERAL_ID_t Copy_enu_APB1_Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Disable APB1 Peripheral Clock*/
	RCC->RCC_APB1ENR &= ~(ONE_VALUE << Copy_enu_APB1_Peripheral_ID);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuSet_PLLConfig         .                                     ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_PstrPLLConfig                                                 ****/
/** Functionality   : Set PLL Configuration                                              ****/
/** this function only used when you choose PLL to be SYSCLK                             ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuSet_PLLConfig(RCC_PLL_Config_t* Copy_PstrPLLConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PstrPLLConfig != NULL)
	{
		/*Setting PLL MUL Factor*/
		RCC->RCC_CFGR |= ((Copy_PstrPLLConfig->PLLMUL_FACTOR)<<Bit_18);

		/*Setting PLL SRC*/
		if(Copy_PstrPLLConfig->PLL_SRC == HSE_CLOCK)
		{
			RCC->RCC_CFGR |= (ONE_VALUE<<Bit_16);

			/*in case PLLSRC is HSE Then I have to choose weather HSE is Divided by 2 or not */
			if(Copy_PstrPLLConfig->PLL_XTPRE == HSE_NOT_DIVIDED)
			{
				RCC->RCC_CFGR &= ~(ONE_VALUE<<Bit_17);
				Local_enuErrorState = ES_OK;
			}
			else if(Copy_PstrPLLConfig->PLL_XTPRE == HSE_DIVIDED)
			{
				RCC->RCC_CFGR |= (ONE_VALUE<<Bit_17);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}

		}
		else if(Copy_PstrPLLConfig->PLL_SRC == HSI_CLOCK_DIVIDED_BY_2)
		{
			RCC->RCC_CFGR &= ~(ONE_VALUE<<Bit_16);
			RCC->RCC_CFGR &= ~(ONE_VALUE<<Bit_17);
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






















