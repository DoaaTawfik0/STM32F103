/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Update_Date:May 19, 2024  ****************/
/***********************************************************/
/***********************************************************/


#include  "../Inc/STD_TYPES.h"
#include  "../Inc/ERROR_STATE.h"
#include  "../Inc/BIT_MATH.h"

#include  "../Inc/STM32F103xx.h"
#include  "../Inc/USART_Private.h"
#include  "../Inc/USART_Interface.h"


/*An array For USART Peripherals Addresses*/
static USART_RegDef_t* USART_Peripheral[USART_PERIPHERAL_NUM] = {USART_1 , USART_2 , USART_3};





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : USART_enuInitialize.                                  **/
/** Return Type     : Error_State enum.                                     **/
/** Arguments       : Copy_pstr_USARTConfig.                                **/
/** Functionality   : Initializing USART [1,2,3]                            **/
/** initiate BaudRate,OP_Mode,SB_Mode,Parity,Word_Length                    **/
/*****************************************************************************/
/*****************************************************************************/
ES_t  USART_enuInitialize(USART_Config_t* Copy_pstr_USARTConfig)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_pstr_USARTConfig != NULL)
	{
		/*getting values of struct into local variables ->just to make it easy in writing code*/
		u32 Local_enuBAUD_RATE = Copy_pstr_USARTConfig->USART_BAUD_RATE;
		USART_Num_t Local_enuNUM = Copy_pstr_USARTConfig->USART_NUM;
		USART_OP_Mode_t Local_enuOP_MODE = Copy_pstr_USARTConfig->USART_OP_MODE;
		USART_StopBits_t Local_enuStopBit_MODE = Copy_pstr_USARTConfig->USART_StopBit_MODE;
		USART_PARITY_STATE_t Local_enuPARITY_STATE = Copy_pstr_USARTConfig->USART_PARITY_STATE;
		USART_PARITY_MODE_t Local_enuPARITY_MODE = Copy_pstr_USARTConfig->USART_PARITY_MODE;
		USART_WORD_LENGTH_t Local_enuWORD_LENGTH = Copy_pstr_USARTConfig->USART_WORD_LENGTH;

		/*Baud Rate Calculations*/
		u32 Local_u32USARTDIV = (u32)((F_CLOCK)/(16*Local_enuBAUD_RATE)*1000);
		u16 Local_u16DIV_MANTISSA = (u16)(Local_u32USARTDIV/1000);

		u16 Local_u16DIV_Fraction = ((((Local_u32USARTDIV%1000)*16)+500)/1000);

		u16 Local_u16BaudRate= ((Local_u16DIV_MANTISSA << Bit_4)|(Local_u16DIV_Fraction));

		USART_Peripheral[Local_enuNUM]->USART_BRR = Local_u16BaudRate;



		if((Local_enuNUM >= USART_1_) && (Local_enuNUM <= USART_3_))
		{

			/*Enable USART[USART1-USART2-USART3]*/
			USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_13);

			if((Local_enuOP_MODE >= USART_TX) && (Local_enuOP_MODE <= USART_TX_RX))
			{
				/*Set operation mode for USART [TX,RX,TX_RX]*/
				switch (Local_enuOP_MODE)
				{
				case USART_TX:
					USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_3);
					break;
				case USART_RX:
					USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_2);
					break;
				case USART_TX_RX:
					USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_3);
					USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_2);
					break;
				}



				if((Local_enuStopBit_MODE >= USART_ONE_SB) && (Local_enuStopBit_MODE <= USART_ONE_HALF_SB))
				{
					/*Set Configuration for stop bits in USART*/
					switch (Local_enuStopBit_MODE)
					{
					case USART_ONE_SB:
						USART_Peripheral[Local_enuNUM]->USART_CR2 &= (~(ONE_VALUE << Bit_12));
						USART_Peripheral[Local_enuNUM]->USART_CR2 &= (~(ONE_VALUE << Bit_13));
						break;
					case USART_HALF_SB:
						USART_Peripheral[Local_enuNUM]->USART_CR2 |= (ONE_VALUE << Bit_12);
						USART_Peripheral[Local_enuNUM]->USART_CR2 &= (~(ONE_VALUE << Bit_13));
						break;
					case USART_TWO_SB:
						USART_Peripheral[Local_enuNUM]->USART_CR2 &= (~(ONE_VALUE << Bit_12));
						USART_Peripheral[Local_enuNUM]->USART_CR2 |= (ONE_VALUE << Bit_13);
						break;
					case USART_ONE_HALF_SB:
						USART_Peripheral[Local_enuNUM]->USART_CR2 |= (ONE_VALUE << Bit_12);
						USART_Peripheral[Local_enuNUM]->USART_CR2 |= (ONE_VALUE << Bit_13);
						break;
					}



					if((Local_enuPARITY_STATE == USART_EN_PARITY) || (Local_enuPARITY_STATE == USART_DIS_PARITY))
					{
						/*Configure Parity pit if enabled or disabled*/
						switch (Local_enuPARITY_STATE)
						{
						case USART_EN_PARITY:
							USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_10);
							break;
						case USART_DIS_PARITY:
							USART_Peripheral[Local_enuNUM]->USART_CR1 &= (~(ONE_VALUE << Bit_10));
							break;
						}



						if((Local_enuPARITY_MODE == USART_EVEN_PARITY) || (Local_enuPARITY_MODE == USART_ODD_PARITY))
						{
							/*Configure mode of parity [odd,even]*/
							switch (Local_enuPARITY_MODE)
							{
							case USART_ODD_PARITY:
								USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_9);
								break;
							case USART_EVEN_PARITY:
								USART_Peripheral[Local_enuNUM]->USART_CR1 &= (~(ONE_VALUE << Bit_9));
								break;
							}



							if((Local_enuWORD_LENGTH == USART_EIGHT_LEN) || (Local_enuWORD_LENGTH == USART_NINE_LEN))
							{
								/*Configure Word Size[8,9]Data Bits*/
								switch (Local_enuPARITY_MODE)
								{
								case USART_EIGHT_LEN:
									USART_Peripheral[Local_enuNUM]->USART_CR1 &= (~(ONE_VALUE << Bit_12));
									break;
								case USART_NINE_LEN:
									USART_Peripheral[Local_enuNUM]->USART_CR1 |= (ONE_VALUE << Bit_12);
									break;
								}

								/*error state is ok after all conditions*/
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
						Local_enuErrorState = ES_OUT_OF_RANGE;
					}
				}
				else
				{

				}
			}
			else
			{

			}
		}
		else
		{

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
/** Function Name   : USART_enuEnable_Peripheral.                                 **/
/** Return Type     : Error_State enum.                                           **/
/** Arguments       : Copy_enuUSART_ID.                                           **/
/** Functionality   : Enable USART Peripheral based on which one u want to enable **/
/***********************************************************************************/
/***********************************************************************************/
ES_t  USART_enuEnable_Peripheral(USART_Num_t Copy_enuUSART_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
	{
		/*Enable USART[USART1-USART2-USART3]*/
		USART_Peripheral[Copy_enuUSART_ID]->USART_CR1 |= (ONE_VALUE << Bit_13);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/************************************************************************************/
/************************************************************************************/
/** Function Name   : USART_enuDisable_Peripheral.                                 **/
/** Return Type     : Error_State enum.                                            **/
/** Arguments       : Copy_enuUSART_ID.                                            **/
/** Functionality   : disable USART Peripheral based on which one u want to disable**/
/************************************************************************************/
/************************************************************************************/
ES_t  USART_enuDisable_Peripheral(USART_Num_t Copy_enuUSART_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
	{
		/*Disable USART[USART1-USART2-USART3]*/
		USART_Peripheral[Copy_enuUSART_ID]->USART_CR1 &= (~(ONE_VALUE << Bit_13));
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}



/************************************************************************************/
/************************************************************************************/
/** Function Name   : USART_enuEnable_Interrupt.                                   **/
/** Return Type     : Error_State enum.                                            **/
/** Arguments       : Copy_enuUSART_ID , Copy_enuIntType.                          **/
/** Functionality   : enable USART INT based on which USART u want to enable       **/
/**  also based on type of INT u want to enable                                    **/
/************************************************************************************/
/************************************************************************************/
ES_t  USART_enuEnable_Interrupt(USART_Num_t Copy_enuUSART_ID , USART_INT_Type_t Copy_enuIntType)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
	{
		if((Copy_enuIntType >= USART_IDLEI) && (Copy_enuIntType <= USART_PEIE))
		{
			USART_Peripheral[Copy_enuUSART_ID]->USART_CR1 |= (ONE_VALUE << Copy_enuIntType);

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



/************************************************************************************/
/************************************************************************************/
/** Function Name   : USART_enuDisable_Interrupt.                                  **/
/** Return Type     : Error_State enum.                                            **/
/** Arguments       : Copy_enuUSART_ID , Copy_enuIntType.                          **/
/** Functionality   : disable USART INT based on which USART u want to disable     **/
/**  also based on type of INT u want to disable                                   **/
/************************************************************************************/
/************************************************************************************/
ES_t  USART_enuDisable_Interrupt(USART_Num_t Copy_enuUSART_ID , USART_INT_Type_t Copy_enuIntType)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
	{
		if((Copy_enuIntType >= USART_IDLEI) && (Copy_enuIntType <= USART_PEIE))
		{
			USART_Peripheral[Copy_enuUSART_ID]->USART_CR1 &= (~(ONE_VALUE << Copy_enuIntType));

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



/************************************************************************************/
/************************************************************************************/
/** Function Name   : USART_enuSyncSendData.                                       **/
/** Return Type     : Error_State enum.                                            **/
/** Arguments       : Copy_enuUSART_ID , Copy_u8Data.                              **/
/** Functionality   : send data on USART line[USART1/USART2/USART3]                **/
/**  this function used polling[Synchronous Functio]                               **/
/************************************************************************************/
/************************************************************************************/
ES_t  USART_enuSyncSendData(USART_Num_t Copy_enuUSART_ID , u8 Copy_u8Data)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
	{
		/*Polling->wait on flag to be set*/
		while(GET_BIT(USART_Peripheral[Copy_enuUSART_ID]->USART_SR , Bit_6) == 0);
		/*read data drom Data Register*/
		USART_Peripheral[Copy_enuUSART_ID]->USART_DR = Copy_u8Data;
		/*clear flag*/
		CLEAR_BIT(USART_Peripheral[Copy_enuUSART_ID]->USART_SR , Bit_6);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}



	return Local_enuErrorState;
}



/************************************************************************************/
/************************************************************************************/
/** Function Name   : USART_enuSyncRecieveData.                                    **/
/** Return Type     : Error_State enum.                                            **/
/** Arguments       : Copy_enuUSART_ID , Copy_pu8Data.                             **/
/** Functionality   : Receive data on USART line[USART1/USART2/USART3]             **/
/**  this function used polling[Synchronous Functio]                               **/
/************************************************************************************/
/************************************************************************************/
ES_t  USART_enuSyncRecieveData(USART_Num_t Copy_enuUSART_ID , u8* Copy_pu8Data)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_pu8Data != NULL)
	{
		if((Copy_enuUSART_ID >= USART_1_) && (Copy_enuUSART_ID <= USART_3_))
		{
			/*Polling->wait on flag to be set*/
			while(GET_BIT(USART_Peripheral[Copy_enuUSART_ID]->USART_SR , Bit_5) == 0);
			/*read data drom Data Register*/
			*Copy_pu8Data = USART_Peripheral[Copy_enuUSART_ID]->USART_DR;
			/*clear flag*/
			CLEAR_BIT(USART_Peripheral[Copy_enuUSART_ID]->USART_SR , Bit_5);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState =ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}


