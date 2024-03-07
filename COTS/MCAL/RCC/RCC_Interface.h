/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Created on: Mar 7, 2024   ****************/
/***********************************************************/
/***********************************************************/

#ifndef  RCC_INTERFACE_H_
#define  RCC_INTERFACE_H_


/*Some Definitions I'll Use In my Driver*/
#define    CLK_OFF         0
#define    CLK_ON          1
#define    CLK_NOT_READY   0
#define    CLK_READY       1



/*enum for identifying different buses*/
typedef enum
{
	AHB_BUS = 0  ,
	APB1_BUS     ,
	APB2_BUS

}RCC_BUS_ID_t;



/*enum for identifying MCO Configuration*/
typedef enum
{
	MCO_SYSCLK     = 0b100 ,
	MCO_HSI        = 0b101 ,
	MCO_HSE        = 0b110 ,
	MCO_PLL        = 0b111
}RCC_MCO_CONFIG_t;



/*enum for identifying PLLMUL Factor*/
typedef enum
{
	PLL_MULFACT_2    = 0b0000 ,
	PLL_MULFACT_3    = 0b0001 ,
	PLL_MULFACT_4    = 0b0010 ,
	PLL_MULFACT_5    = 0b0011 ,
	PLL_MULFACT_6    = 0b0100 ,
	PLL_MULFACT_7    = 0b0101 ,
	PLL_MULFACT_8    = 0b0110 ,
	PLL_MULFACT_9    = 0b0111 ,
	PLL_MULFACT_10   = 0b1000 ,
	PLL_MULFACT_11   = 0b1001 ,
	PLL_MULFACT_12   = 0b1010 ,
	PLL_MULFACT_13   = 0b1011 ,
	PLL_MULFACT_14   = 0b1100 ,
	PLL_MULFACT_15   = 0b1101 ,
	PLL_MULFACT_16   = 0b1110
}RCC_PLLMUL_FACTOR_t;



/*enum for identifying HSE ENTRY*/
typedef enum
{
	HSE_NOT_DIVIDED = 0,
	HSE_DIVIDED
}RCC_HSE_Entry_t;



/*enum for identifying PLL CLKSRC*/
typedef enum
{
	HSI_CLOCK_DIVIDED_BY_2 = 0,
	HSE_CLOCK
}RCC_PLL_CLOCK_SRC_t;



/*enum for identifying SYSCLK*/
typedef enum
{
	HSI_SYSCLK  = 0b00   ,
	HSE_SYSCLK  = 0b01   ,
	PLL_SYSCLK  = 0b10
}RCC_SYSCLK_t;



/*enum for identifying AHB Peripherals*/
typedef enum
{
	DMA1_EN = 0      ,
	DMA2_EN          ,
	SRAM_EN          ,
	FLITF_EN = 4     ,
	CRC_EN   = 6     ,
	FSMC_EN  = 8     ,
	SDIO_EN  = 10

}RCC_AHB_PERIPHERAL_ID_t;



/*enum for identifying APB2 Peripherals*/
typedef enum
{
	AFIO_EN = 0    ,
	IOPA_EN        ,
	IOPB_EN        ,
	IOPC_EN        ,
	IOPD_EN        ,
	IOPE_EN        ,
	IOPF_EN        ,
	IOPG_EN        ,
	ADC1_EN        ,
	ADC2_EN        ,
	TIM1_EN        ,
	SPI1_EN        ,
	TIM8_EN        ,
	USART1_EN      ,
	ADC3_EN        ,
	TIM9_EN = 19   ,
	TIM10_EN       ,
	TIM11_EN

}RCC_APB2_PERIPHERAL_ID_t;



/*enum for identifying APB1 Peripherals*/
typedef enum
{
	TIM2_EN   = 0    ,
	TIM3_EN          ,
	TIM4_EN          ,
	TIM5_EN          ,
	TIM6_EN          ,
	TIM7_EN          ,
	TIM12_EN         ,
	TIM13_EN         ,
	TIM14_EN         ,
	WWDG_EN   = 11   ,
	SPI2_EN   = 14   ,
	SPI3_EN          ,
	UART2_EN  = 17   ,
	UART3_EN         ,
	USART4_EN        ,
	UART5_EN         ,
	I2C1_EN          ,
	I2C2_EN          ,
	USB_EN           ,
	BKP_EN    = 27   ,
	PWR_EN          ,
	DAC_EN

}RCC_APB1_PERIPHERAL_ID_t;



/*Struct for identifying PLL Configuration*/
typedef  struct
{
	RCC_PLLMUL_FACTOR_t  PLLMUL_FACTOR;
	RCC_PLL_CLOCK_SRC_t  PLL_SRC;
	RCC_HSE_Entry_t      PLL_XTPRE;

}RCC_PLL_Config_t;



/*Functions ProtoTypes*/
ES_t  RCC_enuSelect_SYSCLK(RCC_SYSCLK_t  Copy_enuSYSCLK_ID);
ES_t  RCC_enuEnable_Peripheral_CLK(RCC_BUS_ID_t Copy_enuBUS_ID , u8 Copy_u8Peripheral_ID);
ES_t  RCC_enuDisable_Peripheral_CLK(RCC_BUS_ID_t Copy_enuBUS_ID , u8 Copy_u8Peripheral_ID);
ES_t  RCC_enuCheckRDY(RCC_SYSCLK_t  Copy_enuSYSCLK_ID , u8* Copy_u8ptrRDYState);
ES_t  RCC_enuSet_PLLConfig(RCC_PLL_Config_t* Copy_PstrPLLConfig);
ES_t  RCC_enuHSI_Enable();
ES_t  RCC_enuHSE_Enable();
ES_t  RCC_enuPLL_Enable();
ES_t  RCC_enuHSI_Disable();
ES_t  RCC_enuHSE_Disable();
ES_t  RCC_enuPLL_Disable();

#endif
