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
/** Functionality   : Sitting System Clock                                               ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuSelect_SYSCLK(RCC_SYSCLK_t  Copy_enuSYSCLK_ID)
{
	ES_t  Local_enuErrorState  = ES_NOK;

	if(Copy_enuSYSCLK_ID == HSI_SYSCLK)
	{
		RCC->RCC_CFGR |= (HSI_SYSCLK);   /*Setting First 2 bits with value zero*/
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuSYSCLK_ID == HSE_SYSCLK)
	{
		RCC->RCC_CFGR |= (HSE_SYSCLK);  /*Setting First 2 bits with value One*/
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuSYSCLK_ID == PLL_SYSCLK)
	{
		RCC->RCC_CFGR |= (PLL_SYSCLK);  /*Setting First 2 bits with value Two*/
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

	RCC->RCC_CR &= (~(ONE_VALUE)<<Bit_0);
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

	RCC->RCC_CR &= (~(ONE_VALUE)<<Bit_16);
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

	RCC->RCC_CR &= (~(ONE_VALUE)<<Bit_24);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : RCC_enuCheckRDY.                                                   ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuSYSCLK_ID , Copy_u8ptrRDYState                             ****/
/** Functionality   : Check if clock source is ready                                     ****/
/** this function takes Sysclk Type & read value of its ready flag                       ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuCheckRDY(RCC_SYSCLK_t  Copy_enuSYSCLK_ID , u8* Copy_u8ptrRDYState)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_u8ptrRDYState != NULL)
	{
		if(Copy_enuSYSCLK_ID == HSI_SYSCLK)
		{
			*Copy_u8ptrRDYState = (((RCC->RCC_CR)>>Bit_1)&1);
			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuSYSCLK_ID == HSE_SYSCLK)
		{
			*Copy_u8ptrRDYState = (((RCC->RCC_CR)>>Bit_17)&1);
			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuSYSCLK_ID == PLL_SYSCLK)
		{
			*Copy_u8ptrRDYState = (((RCC->RCC_CR)>>Bit_25)&1);
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
/** Function Name   : RCC_enuEnable_Peripheral_CLK.                                      ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuBUS_ID , Copy_u8Peripheral_ID                              ****/
/** Functionality   : Enable Clock of Any Peripheral                                     ****/
/** this function takes Bus Type & Peripheral Id then enable clock of this peripheral    ****/
/*make sure that Copy_u8Peripheral_ID represents correct number of peripheral
  enable bit in register                                                                 ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuEnable_Peripheral_CLK(RCC_BUS_ID_t Copy_enuBUS_ID , u8 Copy_u8Peripheral_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_enuBUS_ID == AHB_BUS)
	{
		RCC->RCC_AHBENR |= (ONE_VALUE<<Copy_u8Peripheral_ID);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuBUS_ID == APB1_BUS)
	{
		RCC->RCC_APB1ENR |= (ONE_VALUE<<Copy_u8Peripheral_ID);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuBUS_ID == APB2_BUS)
	{
		RCC->RCC_APB2ENR |= (ONE_VALUE<<Copy_u8Peripheral_ID);
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
/** Function Name   : RCC_enuDisable_Peripheral_CLK.                                     ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuBUS_ID , Copy_u8Peripheral_ID                              ****/
/** Functionality   : Disable Clock of Any Peripheral                                    ****/
/** this function takes Bus Type & Peripheral Id then Disable clock of this peripheral   ****/
/*make sure that Copy_u8Peripheral_ID represents correct number of peripheral
  enable bit in register                                                                 ****/
/********************************************************************************************/
/********************************************************************************************/

ES_t  RCC_enuDisable_Peripheral_CLK(RCC_BUS_ID_t Copy_enuBUS_ID , u8 Copy_u8Peripheral_ID)
{

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_enuBUS_ID == AHB_BUS)
	{
		RCC->RCC_AHBENR &= (~(ONE_VALUE)<<Copy_u8Peripheral_ID);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuBUS_ID == APB1_BUS)
	{
		RCC->RCC_APB1ENR &= (~(ONE_VALUE)<<Copy_u8Peripheral_ID);
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuBUS_ID == APB2_BUS)
	{
		RCC->RCC_APB2ENR &= (~(ONE_VALUE)<<Copy_u8Peripheral_ID);
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
				RCC->RCC_CFGR &= (~(ONE_VALUE)<<Bit_17);
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
			RCC->RCC_CFGR &= (~(ONE_VALUE)<<Bit_16);
			RCC->RCC_CFGR &= (~(ONE_VALUE)<<Bit_17);
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






















