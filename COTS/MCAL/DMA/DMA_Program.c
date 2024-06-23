/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:June 23, 2024        ****************/
/***********************************************************/
/***********************************************************/

#include  "../Inc/STD_TYPES.h"
#include  "../Inc/ERROR_STATE.h"
#include  "../Inc/BIT_MATH.h"

#include  "../Inc/DMA_Private.h"
#include  "../Inc/DMA_Interface.h"



/********************************************************/
/*********** Call_Back Functions          ***************/
/*******************************************************/
static volatile void (*Global_PFun_ChISR[7])(volatile void*) = {NULL};
static volatile void (*Global_PV_ChParameter[7]) = {NULL};



/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuChannel_Init.                               ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_pstrChannel_Config                            ****/
/** Functionality   : Initialize DMA Channel                             ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuChannel_Init(DMA_CHANNEL_CONFIG_t* Copy_pstrChannel_Config)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32  Local_u8ErrorState = 0 , Local_u8Iterator = 0;

	if(Copy_pstrChannel_Config != NULL)
	{
		/*Local Variables to carry values of struct to make it easy while coding*/
		DMA_CHANNEL_NUM_t  Local_enuChannel_Num = Copy_pstrChannel_Config->Channel_Number;
		DMA_M2M_MODE_t     Local_enuM2M_MODE = Copy_pstrChannel_Config->M2M_MODE;
		DMA_CHANNEL_PRIO_t Local_enuChannel_Prority = Copy_pstrChannel_Config->Channel_Prority;
		DMA_PSIZE_t        Local_enuPeripheral_Data_Size = Copy_pstrChannel_Config->Peripheral_Data_Size;
		DMA_MSIZE_t        Local_enuMemory_Data_SIZE = Copy_pstrChannel_Config->Memory_Data_SIZE;
		DMA_MINC_t         Local_enuMemory_Inc_State = Copy_pstrChannel_Config->Memory_Inc_State;
		DMA_PINC_t         Local_enuPeripheral_Inc_State = Copy_pstrChannel_Config->Peripheral_Inc_State;
		DMA_CIRC_MODE_t    Local_enuCircular_Mode = Copy_pstrChannel_Config->Circular_Mode;
		DMA_DT_DIR_t       Local_enuData_Direction = Copy_pstrChannel_Config->Data_Direction;

		/*Disable Channel to be able to make Configurations*/
		DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_0));


		/*Configure Mem2Mem Mode*/
		if(Local_enuM2M_MODE <= DMA_M2M_ENABLE)
		{
			/*Mask bit 14*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_14));
			/*determine whether working in M2M mode or not*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuM2M_MODE << Bit_14);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Channel Priority*/
		if(Local_enuChannel_Prority <= DMA_V_HIGH_PRIORITY)
		{
			/*Mask 2 bits[12,13]*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(TWO_BMASKING << Bit_12));
			/*Set Priority*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuChannel_Prority << Bit_12);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Memory Size*/
		if(Local_enuMemory_Data_SIZE <= DMA_MSIZE_32)
		{
			/*Mask 2 bits[10,11]*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(TWO_BMASKING << Bit_10));
			/*Set Memory Size*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuMemory_Data_SIZE << Bit_10);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Peripheral Size*/
		if(Local_enuPeripheral_Data_Size <= DMA_PSIZE_32)
		{
			/*Mask 2 bits[8,9]*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(TWO_BMASKING << Bit_8));
			/*Set Peripheral Size*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuPeripheral_Data_Size << Bit_8);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Memory Increment Mode*/
		if(Local_enuMemory_Inc_State <= DMA_MINC_ENABLE)
		{
			/*Mask bit 7*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_7));
			/*Determine Memory Inc or not*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuMemory_Inc_State << Bit_7);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Peripheral Increment Mode*/
		if(Local_enuPeripheral_Inc_State <= DMA_PINC_ENABLE)
		{
			/*Mask bit 6*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_6));
			/*Determine Peripheral Inc or not*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuPeripheral_Inc_State << Bit_6);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Circular Mode*/
		if(Local_enuCircular_Mode <= DMA_CIRC_ENABLE)
		{
			/*Mask bit 5*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_5));
			/*Determine Circular Mode or not*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuCircular_Mode << Bit_5);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}
		Local_u8Iterator += 2;

		/*Configure Data Transfer Direction*/
		if(Local_enuData_Direction <= DMA_FROM_MEMORY)
		{
			/*Mask bit 4*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_4));
			/*Set DT Direction*/
			DMA->DMA_CH[Local_enuChannel_Num-1].DMA_CCR |= (Local_enuData_Direction << Bit_4);

			Local_u8ErrorState |= (ES_OK << Local_u8Iterator);
		}
		else
		{
			Local_u8ErrorState |= (ES_OUT_OF_RANGE << Local_u8Iterator);
		}

		/*Check on Error if happend*/
		for(Local_u8Iterator = 0 ; Local_u8Iterator < 20 ; Local_u8Iterator+=2)
		{
			if(((Local_u8ErrorState>>Local_u8Iterator)&ONE_VAL) != ES_OK)
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
				break;
			}
			else
			{
				Local_enuErrorState = ES_OK;
			}
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}




/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuChannel_Enable.                             ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuChannel_Num                                ****/
/** Functionality   : Enable DMA Channel                                 ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuChannel_Enable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR |= (ONE_VAL << Bit_0);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuChannel_Disable.                            ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuChannel_Num                                ****/
/** Functionality   : Disable DMA Channel                                ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuChannel_Disable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_0));

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuInt_Enable.                                 ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuChannel_Num , Copy_enuInt_Src              ****/
/** Functionality   : Enable INT source [TEI,HTI,TCI]                    ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuInt_Enable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , DMA_INT_SRC_t Copy_enuInt_Src)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		if(Copy_enuInt_Src == DMA_TEI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR |= (ONE_VAL << Bit_3);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuInt_Src == DMA_HTI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR |= (ONE_VAL << Bit_2);

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuInt_Src == DMA_TCI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR |= (ONE_VAL << Bit_1);

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



/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuINT_Disable.                                ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuChannel_Num , Copy_enuInt_Src              ****/
/** Functionality   : Disable INT source [TEI,HTI,TCI]                   ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuINT_Disable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , DMA_INT_SRC_t Copy_enuInt_Src)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		if(Copy_enuInt_Src == DMA_TEI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_3));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuInt_Src == DMA_HTI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_2));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuInt_Src == DMA_TCI)
		{
			DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CCR &= (~(ONE_VAL << Bit_1));

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




/****************************************************************************/
/****************************************************************************/
/** Function Name   : DMA_enuSetAddress.                                 ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuChannel_Num , Copy_u32MemAddress           *****
                      Copy_u32PeripheralAddress , Copy_u16BlockSize      ****/
/** Functionality   : Set Block_Size , Mem_Add , Per_Add                 ****/
/****************************************************************************/
/****************************************************************************/
ES_t  DMA_enuSetAddress(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , u32 Copy_u32MemAddress , u32 Copy_u32PeripheralAddress , u16 Copy_u16BlockSize)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		/*Set Number of data to be transferred (0 up to 65535)*/
		DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CNDTR = Copy_u16BlockSize;

		/*Set Base address of the peripheral data register*/
		DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CPAR = Copy_u32PeripheralAddress;

		/*Set Base address of the memory area*/
		DMA->DMA_CH[Copy_enuChannel_Num-1].DMA_CMAR = Copy_u32MemAddress;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/***************************************************************************************/
/***************************************************************************************/
/** Function Name   : DMA_enuCallBack_Function.                                     ****/
/** Return Type     : Error_State enum.                                             ****/
/** Arguments       : Copy_enuChannel_Num , Copy_Pfun_AppFun , Copy_PV_AppParameter ****/
/** Functionality   : Set Call_Back Function & Call_Back Parametr                   ****/
/***************************************************************************************/
/***************************************************************************************/
ES_t  DMA_enuCallBack_Function(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , void(*Copy_Pfun_AppFun)(volatile void*) , void* Copy_PV_AppParameter)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuChannel_Num <= DMA_CH_SEVEN)
	{
		if(Copy_Pfun_AppFun != NULL)
		{
			Global_PFun_ChISR[Copy_enuChannel_Num-1] = Copy_Pfun_AppFun;
			Global_PV_ChParameter[Copy_enuChannel_Num-1] = Copy_PV_AppParameter;

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



/*********************************************************************************************************/
/*********************************             DMA Handlers              *********************************/
/*********************************************************************************************************/



/*Channel_1 Handler*/
void DMA1_Channel1_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_ONE-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_ONE-1](Global_PV_ChParameter[DMA_CH_ONE-1]);
	}
	/*Clearing Flags of channel1 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_0);

}


/*Channel_2 Handler*/
void DMA1_Channel2_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_TWO-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_TWO-1](Global_PV_ChParameter[DMA_CH_TWO-1]);
	}
	/*Clearing Flags of channel2 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_4);

}


/*Channel_3 Handler*/
void DMA1_Channel3_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_THREE-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_THREE-1](Global_PV_ChParameter[DMA_CH_THREE-1]);
	}
	/*Clearing Flags of channel3 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_8);

}


/*Channel_4 Handler*/
void DMA1_Channel4_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_FOUR-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_FOUR-1](Global_PV_ChParameter[DMA_CH_FOUR-1]);
	}
	/*Clearing Flags of channel4 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_12);

}


/*Channel_5 Handler*/
void DMA1_Channel5_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_FIVE-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_FIVE-1](Global_PV_ChParameter[DMA_CH_FIVE-1]);
	}
	/*Clearing Flags of channel5 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_16);

}


/*Channel_6 Handler*/
void DMA1_Channel6_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_SIX-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_SIX-1](Global_PV_ChParameter[DMA_CH_SIX-1]);
	}
	/*Clearing Flags of channel6 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_20);

}


/*Channel_7 Handler*/
void DMA1_Channel7_IRQHandler(void)
{
	if(Global_PFun_ChISR[DMA_CH_SEVEN-1] != NULL)
	{
		Global_PFun_ChISR[DMA_CH_SEVEN-1](Global_PV_ChParameter[DMA_CH_SEVEN-1]);
	}
    /*Clearing Flags of channel7 by writing one*/
	DMA->DMA_IFCR |= (0XF << Bit_24);

}
