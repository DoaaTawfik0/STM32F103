/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:June 25, 2024        ****************/
/***********************************************************/
/***********************************************************/


#include   "../Inc/STD_TYPES.h"
#include   "../Inc/BIT_MATH.h"
#include   "../Inc/ERROR_STATE.h"

#include   "../Inc/STM32F103xx.h"

#include   "../Inc/SPI_Interface.h"
#include   "../Inc/SPI_Private.h"


/********************************************************/
/*********** Call_Back Functions          ***************/
/*******************************************************/
static volatile void (*Global_PFun_SPI_Fun[2])(u8) = {NULL , NULL};




/*An array For SPI Peripherals Addresses*/
static SPI_RegDef_t* SPI_Peripheral[SPI_PERIPHERAL_NUM] = {SPI_1 , SPI_2};



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SPI_enuInitialize.                                 ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_pstr_SPIConfig                                ****/
/** Functionality   : Initialize SPI                                     ****/
/****************************************************************************/
/****************************************************************************/
ES_t  SPI_enuInitialize(SPI_Config_t* Copy_pstr_SPIConfig)
{
	ES_t  Local_enuErrorState = ES_NOK;


	if(Copy_pstr_SPIConfig != NULL)
	{
		/*Local variables to simplify dealing with structure*/
		SPI_NUM_t        Local_enuNum = Copy_pstr_SPIConfig->SPI_NUM;
		SPI_MODE_t       Local_enuMODE = Copy_pstr_SPIConfig->SPI_MODE;
		SPI_FF_t         Local_enuFIRST_SIG_BIT = Copy_pstr_SPIConfig->SPI_FRAME_FORMAT;
		SPI_BRate_t      Local_enuBAUD_RATE = Copy_pstr_SPIConfig->SPI_BAUD_RATE;
		SPI_FS_t         Local_enuFRAME_FORMAT = Copy_pstr_SPIConfig->SPI_FRAME_FORMAT;
		SPI_CLK_POL_t    Local_enuCLOCK_POLARITY = Copy_pstr_SPIConfig->SPI_CLOCK_POLARITY;
		SPI_CLK_Phase_t  Local_enuCLOCK_PHASE = Copy_pstr_SPIConfig->SPI_CLOCK_PHASE;



		if(Local_enuMODE == SPI_MASTER)
		{
			/*Masking bits from 3 to 5*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(BAUD_RATE_MASKING << Bit_3));
			/*Setting Value of Baud Rate*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuBAUD_RATE << Bit_3);

			/*Masking bit1 used for Polarity*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_1));
			/*Setting Polarity*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuCLOCK_POLARITY << Bit_1);

			/*Masking bit0 used for Clock Phase*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_0));
			/*Setting Clock Phase*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuCLOCK_PHASE << Bit_0);

			/*Masking bit11 used for Data Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_11));
			/*Setting Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuFRAME_FORMAT<< Bit_11);

			/*Masking bit7 used for Frame Format LSBFIRST*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_7));
			/*Setting Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuFIRST_SIG_BIT << Bit_7);


			/*this is the case where we have only one slave*/
			/*From DataSheet in the section of Configuring SPI in Master Mode*/
			/*SW Management enable*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_9);
			/*Slave not Selected using SSI*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_8);


			/*Setting Master bit*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_2);


			/*Enable SPI*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_6);

			Local_enuErrorState = ES_OK;
		}
		else if(Local_enuMODE == SPI_SLAVE)
		{

			/*Masking bit11 used for Data Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_11));
			/*Setting Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuFRAME_FORMAT<< Bit_11);

			/*Masking bit1 used for Polarity*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_1));
			/*Setting Polarity*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuCLOCK_POLARITY << Bit_1);

			/*Masking bit0 used for Clock Phase*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_0));
			/*Setting Clock Phase*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuCLOCK_PHASE << Bit_0);

			/*Masking bit7 used for Frame Format LSBFIRST*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_7));
			/*Setting Frame Format*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (Local_enuFIRST_SIG_BIT << Bit_7);


			/*this is the case where we have only one slave*/
			/*From DataSheet in the section of Configuring SPI in Slave Mode*/
			/*Let NSS be in I/P mode*/
			SPI_Peripheral[Local_enuNum]->SPI_CR2 &= (~(ONE_VAL << Bit_2));
			/*SW Management enable*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_9);
			/*Slave  Selected using SSI*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_8));


			/*Clearing Master bit*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 &= (~(ONE_VAL << Bit_2));


			/*Enable SPI*/
			SPI_Peripheral[Local_enuNum]->SPI_CR1 |= (ONE_VAL << Bit_6);

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



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SPI_enuEnable_Peripheral.                          ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuSPI_ID                                     ****/
/** Functionality   : Enable SPI[SPI_1 , SPI_2]                          ****/
/****************************************************************************/
/****************************************************************************/
ES_t  SPI_enuEnable_Peripheral(SPI_NUM_t Copy_enuSPI_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuSPI_ID>=SPI_1_) && (Copy_enuSPI_ID<=SPI_2_))
	{
		/*Enable SPI[SPI1,SPI2]*/
		SPI_Peripheral[Copy_enuSPI_ID]->SPI_CR1 |= (ONE_VAL << Bit_6);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return  Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SPI_enuDisable_Peripheral.                         ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuSPI_ID                                     ****/
/** Functionality   : Disable SPI[SPI_1 , SPI_2]                         ****/
/****************************************************************************/
/****************************************************************************/
ES_t  SPI_enuDisable_Peripheral(SPI_NUM_t Copy_enuSPI_ID)
{

	ES_t  Local_enuErrorState = ES_NOK;
	u8 Local_u8Flag = 0;

	if((Copy_enuSPI_ID>=SPI_1_) && (Copy_enuSPI_ID<=SPI_2_))
	{
		/****This is the procedure to disable SPI when in full duplex mode****/

		/*Get State of RXNE (Receive buffer not empty)*/
		Local_u8Flag = GET_BIT(SPI_Peripheral[Copy_enuSPI_ID]->SPI_SR , Bit_0);
		/*Wait untill RXNE become 1 ->indication for receiving last data*/
		while(!Local_u8Flag);
		/*Get State of TXE (Transmit buffer empty)*/
		Local_u8Flag = GET_BIT(SPI_Peripheral[Copy_enuSPI_ID]->SPI_SR , Bit_1);
		/*Wait untill TXE become 1 ->indication for complete transmission*/
		while(!Local_u8Flag);
		/*Get State of BSY (busy flag)*/
		Local_u8Flag = GET_BIT(SPI_Peripheral[Copy_enuSPI_ID]->SPI_SR , Bit_7);
		/*Wait untill BSY become 0 ->indication for SPI isn't busy*/
		while(Local_u8Flag);

		/*Disable SPI[SPI1,SPI2]*/
		SPI_Peripheral[Copy_enuSPI_ID]->SPI_CR1 &= (~(1<<Bit_6));

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return  Local_enuErrorState;
}



/****************************************************************************/
/****************************************************************************/
/** Function Name   : SPI_enuINT_Enable.                                 ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuSPI_ID , Copy_enuInt_Src                   ****/
/** Functionality   : Enable INT_SRC [RXNEI,TXEI,ERRI]                   ****/
/****************************************************************************/
/****************************************************************************/
ES_t  SPI_enuINT_Enable(SPI_NUM_t Copy_enuSPI_ID, SPI_INT_SRC_t Copy_enuInt_Src)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuSPI_ID <= SPI_2_) && (Copy_enuInt_Src <= SPI_TXEI))
	{
		/*Enable INT Source based on Copy_enuInt_Src that will determine the bit to be set*/
		SPI_Peripheral[Copy_enuSPI_ID]->SPI_CR2 |= (ONE_VAL << Copy_enuInt_Src);

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
/** Function Name   : SPI_enuINT_Disable.                                ****/
/** Return Type     : Error_State enum.                                  ****/
/** Arguments       : Copy_enuSPI_ID , Copy_enuInt_Src                   ****/
/** Functionality   : Disable INT_SRC [RXNEI,TXEI,ERRI]                  ****/
/****************************************************************************/
/****************************************************************************/
ES_t  SPI_enuINT_Disable(SPI_NUM_t Copy_enuSPI_ID, SPI_INT_SRC_t Copy_enuInt_Src)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuSPI_ID <= SPI_2_) && (Copy_enuInt_Src <= SPI_TXEI))
	{
		/*Disable INT Source based on Copy_enuInt_Src that will determine the bit to be cleared*/
		SPI_Peripheral[Copy_enuSPI_ID]->SPI_CR2 &= (~(ONE_VAL << Copy_enuInt_Src));

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;

}



/*******************************************************************************************/
/*******************************************************************************************/
/** Function Name   : SPI_enuSendSync.                                                  ****/
/** Return Type     : Error_State enum.                                                 ****/
/** Arguments       : Copy_enuSPI_ID,Copy_u8Data_To_Transmit,Copy_pu8Data_To_Receive    ****/
/** Functionality   : send data from master & receive from slave using Polling          ****/
/*******************************************************************************************/
/*******************************************************************************************/
ES_t  SPI_enuSendSync(SPI_NUM_t Copy_enuSPI_ID , u8 Copy_u8Data_To_Transmit , u8* Copy_pu8Data_To_Receive)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_pu8Data_To_Receive != NULL)
	{
		if(Copy_enuSPI_ID <= SPI_2_)
		{
			/*Move Data to be Transmit into Data Register */
			SPI_Peripheral[Copy_enuSPI_ID]->SPI_DR = Copy_u8Data_To_Transmit;

			/*Wait untill TX Buffer Empty Flag become 1*/
			while(!GET_BIT(SPI_Peripheral[Copy_enuSPI_ID]->SPI_SR , Bit_1));

			/*Get data that has been receieved from Slave*/
			*Copy_pu8Data_To_Receive = SPI_Peripheral[Copy_enuSPI_ID]->SPI_DR;
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



/*********************************************************************************************/
/*********************************************************************************************/
/** Function Name   : SPI_enuSendSync.                                                    ****/
/** Return Type     : Error_State enum.                                                   ****/
/** Arguments       : Copy_enuSPI_ID,Copy_u8Data_To_Transmit                              ****/
/** Functionality   : send data from master & receive from slave using INT                ****/
/**                   before calling this function you must call SPI_enuCallBack_Function ****/
/*********************************************************************************************/
/*********************************************************************************************/
ES_t  SPI_enuSendASync(SPI_NUM_t Copy_enuSPI_ID , u8 Copy_u8Data_To_Transmit)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuSPI_ID <= SPI_2_)
	{
		/*Move Data to be Transmit into Data Register */
		SPI_Peripheral[Copy_enuSPI_ID]->SPI_DR = Copy_u8Data_To_Transmit;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}



/**********************************************************************/
/**********************************************************************/
/** Function Name   : SPI_enuCallBack_Function.                    ****/
/** Return Type     : Error_State enum.                            ****/
/** Arguments       : Copy_enuSPI_ID , Copy_Pfun_AppFun            ****/
/** Functionality   : Set Call_Back Function                       ****/
/**********************************************************************/
/**********************************************************************/
ES_t  SPI_enuCallBack_Function(SPI_NUM_t Copy_enuSPI_ID , void(*Copy_Pfun_AppFun)(u8))
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuSPI_ID <= SPI_2_)
	{
		if(Copy_Pfun_AppFun != NULL)
		{
			Global_PFun_SPI_Fun[Copy_enuSPI_ID] = Copy_Pfun_AppFun;

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
/*********************************             SPI Handlers              *********************************/
/*********************************************************************************************************/


/*SPI1 Handler*/
void SPI1_IRQHandler(void)
{
	if(Global_PFun_SPI_Fun[SPI_1_] != NULL)
	{
		/*Callback Function will receieve data from DR as a Parameter*/
		Global_PFun_SPI_Fun[SPI_1_](SPI_Peripheral[SPI_1_]->SPI_DR);
	}

}


/*SPI2 Handler*/
void SPI2_IRQHandler(void)
{
	if(Global_PFun_SPI_Fun[SPI_2_] != NULL)
	{
		/*Callback Function will receieve data from DR as a Parameter*/
		Global_PFun_SPI_Fun[SPI_2_](SPI_Peripheral[SPI_1_]->SPI_DR);
	}

}



