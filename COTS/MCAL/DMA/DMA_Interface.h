/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:June 23, 2024        ****************/
/***********************************************************/
/***********************************************************/


#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_



typedef enum
{
	DMA_M2M_DISABLE ,
	DMA_M2M_ENABLE
}DMA_M2M_MODE_t;

typedef enum
{
	DMA_LOW_PRIORITY  ,
	DMA_MEDIUM_PRIORITY ,
	DMA_HIGH_PRIORITY ,
	DMA_V_HIGH_PRIORITY
}DMA_CHANNEL_PRIO_t;

typedef enum
{
	DMA_PSIZE_8 ,
	DMA_PSIZE_16 ,
	DMA_PSIZE_32
}DMA_PSIZE_t;

typedef enum
{
	DMA_MSIZE_8 ,
	DMA_MIZE_16 ,
	DMA_MSIZE_32
}DMA_MSIZE_t;

typedef enum
{
	DMA_MINC_DISABLE ,
	DMA_MINC_ENABLE
}DMA_MINC_t;

typedef enum
{
	DMA_PINC_DISABLE ,
	DMA_PINC_ENABLE
}DMA_PINC_t;

typedef enum
{
	DMA_CIRC_DISABLE ,
	DMA_CIRC_ENABLE
}DMA_CIRC_MODE_t;

typedef enum
{
	DMA_FROM_PERIPHERAL ,
	DMA_FROM_MEMORY
}DMA_DT_DIR_t;

typedef enum
{
	DMA_TEI ,
	DMA_HTI ,
	DMA_TCI
}DMA_INT_SRC_t;

typedef enum
{
	DMA_CH_ONE = 1 ,
	DMA_CH_TWO     ,
	DMA_CH_THREE   ,
	DMA_CH_FOUR    ,
	DMA_CH_FIVE    ,
	DMA_CH_SIX     ,
	DMA_CH_SEVEN
}DMA_CHANNEL_NUM_t;

typedef struct
{
	DMA_CHANNEL_NUM_t   Channel_Number;
	DMA_M2M_MODE_t      M2M_MODE;
	DMA_CHANNEL_PRIO_t  Channel_Prority;
	DMA_PSIZE_t         Peripheral_Data_Size;
	DMA_MSIZE_t         Memory_Data_SIZE;
	DMA_MINC_t          Memory_Inc_State;
	DMA_PINC_t          Peripheral_Inc_State;
	DMA_CIRC_MODE_t     Circular_Mode;
	DMA_DT_DIR_t        Data_Direction;
}DMA_CHANNEL_CONFIG_t;


ES_t  DMA_enuChannel_Init(DMA_CHANNEL_CONFIG_t* Copy_pstrChannel_Config);
ES_t  DMA_enuChannel_Enable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num);
ES_t  DMA_enuChannel_Disable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num);
ES_t  DMA_enuInt_Enable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , DMA_INT_SRC_t Copy_enuInt_Src);
ES_t  DMA_enuINT_Disable(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , DMA_INT_SRC_t Copy_enuInt_Src);
ES_t  DMA_enuSetAddress(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , u32 Copy_u32MemAddress , u32 Copy_u32PeripheralAddress , u16 Copy_u16BlockSize);
ES_t  DMA_enuCallBack_Function(DMA_CHANNEL_NUM_t Copy_enuChannel_Num , void(*Copy_Pfun_AppFun)(volatile void*) , void* Copy_PV_AppParameter);

#endif
