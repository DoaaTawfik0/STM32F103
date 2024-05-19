/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Update_Date:May 19, 2024  ****************/
/***********************************************************/
/***********************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*Definitions for Baud_Rate*/
#define   USART_BR_2400       2400UL
#define   USART_BR_9600       9600UL
#define   USART_BR_19200      19200UL
#define   USART_BR_57600      57600UL
#define   USART_BR_115200     115200UL
#define   USART_BR_230400     230400UL
#define   USART_BR_460800     460800UL



typedef enum
{
	USART_1_ ,
	USART_2_ ,
	USART_3_
}USART_Num_t;



typedef enum
{
	USART_TX,
	USART_RX,
	USART_TX_RX
}USART_OP_Mode_t;



typedef enum
{
	USART_ONE_SB,
	USART_HALF_SB,
	USART_TWO_SB ,
	USART_ONE_HALF_SB
}USART_StopBits_t;



typedef enum
{
	USART_EN_PARITY,
	USART_DIS_PARITY
}USART_PARITY_STATE_t;



typedef enum
{
	USART_EVEN_PARITY,
	USART_ODD_PARITY
}USART_PARITY_MODE_t;



typedef enum
{
	USART_EIGHT_LEN,
	USART_NINE_LEN
}USART_WORD_LENGTH_t;



typedef enum
{
	USART_IDLEI = 4 ,
	USART_RXNEI     ,
	USART_TCI       ,
	USART_TXEI      ,
	USART_PEIE
}USART_INT_Type_t;




typedef struct
{
	u32                   USART_BAUD_RATE;
	USART_Num_t           USART_NUM;
	USART_OP_Mode_t       USART_OP_MODE;
	USART_StopBits_t      USART_StopBit_MODE;
	USART_PARITY_STATE_t  USART_PARITY_STATE;
	USART_PARITY_MODE_t   USART_PARITY_MODE;
    USART_WORD_LENGTH_t   USART_WORD_LENGTH;
}USART_Config_t;



ES_t  USART_enuInitialize(USART_Config_t* Copy_pstr_USARTConfig);
ES_t  USART_enuEnable_Peripheral(USART_Num_t Copy_enuUSART_ID);
ES_t  USART_enuDisable_Peripheral(USART_Num_t Copy_enuUSART_ID);

ES_t  USART_enuEnable_Interrupt(USART_Num_t Copy_enuUSART_ID , USART_INT_Type_t Copy_enuIntType);
ES_t  USART_enuDisable_Interrupt(USART_Num_t Copy_enuUSART_ID , USART_INT_Type_t Copy_enuIntType);

ES_t  USART_enuSyncSendData(USART_Num_t Copy_enuUSART_ID , u8 Copy_u8Data);
ES_t  USART_enuSyncRecieveData(USART_Num_t Copy_enuUSART_ID , u8* Copy_pu8Data);


/*Functions below still not implemented*/
ES_t  USART_enuAsyncSendData(USART_Num_t Copy_enuUSART_ID , u8 Copy_u8Data);
ES_t  USART_enuAsyncRecieveData(USART_Num_t Copy_enuUSART_ID , u8* Copy_pu8Data);

ES_t  USART_enuCallBack_Function(USART_Num_t Copy_enuUSART_ID , void(*Copy_Pfun_AppFun)(void*) ,  void* Copy_PV_AppParameter);



#endif
