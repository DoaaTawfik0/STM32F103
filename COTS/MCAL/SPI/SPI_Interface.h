/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:June 25, 2024        ****************/
/***********************************************************/
/***********************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


typedef enum
{
	SPI_SLAVE ,
	SPI_MASTER
}SPI_MODE_t;


typedef enum
{
	SPI_8bit  ,
	SPI_16bit
}SPI_FS_t;/*Frame Size*/

typedef enum
{
	SPI_MSB_FIRST  ,
	SPI_LSB_FIRST
}SPI_FF_t;/*Frame Format*/

//typedef enum
//{
//	SPI_Enable  ,
//	SPI_Disable
//}SPI_State_t;


typedef enum
{
	SPI_BR_2    ,
	SPI_BR_4    ,
	SPI_BR_8    ,
	SPI_BR_16   ,
	SPI_BR_32   ,
	SPI_BR_64   ,
	SPI_BR_128  ,
	SPI_BR_256

}SPI_BRate_t;


typedef enum
{
	SPI_IDLE_0  ,
	SPI_IDLE_1
}SPI_CLK_POL_t;

typedef enum
{
	SPI_FIRST_EDGE_READ  ,
	SPI_SECOND_EDGE_READ
}SPI_CLK_Phase_t;

typedef enum
{
	SPI_1_ ,
	SPI_2_
}SPI_NUM_t;


typedef enum
{
	SPI_ERRI = 5  ,
	SPI_RXNEI     ,
	SPI_TXEI
}SPI_INT_SRC_t;

typedef struct
{
	SPI_NUM_t        SPI_NUM;
	SPI_MODE_t       SPI_MODE;
	SPI_FF_t         SPI_FIRST_SIG_BIT;
	SPI_BRate_t      SPI_BAUD_RATE;
	SPI_FS_t         SPI_FRAME_FORMAT;
	SPI_CLK_POL_t    SPI_CLOCK_POLARITY;
	SPI_CLK_Phase_t  SPI_CLOCK_PHASE;
}SPI_Config_t;


ES_t  SPI_enuInitialize(SPI_Config_t* Copy_pstr_SPIConfig);
ES_t  SPI_enuEnable_Peripheral(SPI_NUM_t Copy_enuSPI_ID);
ES_t  SPI_enuDisable_Peripheral(SPI_NUM_t Copy_enuSPI_ID);
ES_t  SPI_enuINT_Enable(SPI_NUM_t Copy_enuSPI_Num, SPI_INT_SRC_t Copy_enuInt_Src);
ES_t  SPI_enuINT_Disable(SPI_NUM_t Copy_enuSPI_Num, SPI_INT_SRC_t Copy_enuInt_Src);


#endif
