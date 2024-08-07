/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer: LIBRARY            ****************/
/**************   Version: 1.00             ****************/
/**************   Update_Date:June 23, 2024 ****************/
/***********************************************************/
/***********************************************************/

#ifndef  STM32F103XX_H_
#define  STM32F103XX_H_


/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            Start of Peripherals Base Addresses Region                   *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/******************************************************************************************/
/*                          SYSTICK Peripheral Base Addresses                             */
/******************************************************************************************/

#define     SYSTICK_u32_BASE_ADDRESS         0xE000E010U



/******************************************************************************************/
/*                          NVIC Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     NVIC_u32__BASE_ADDRESS           0xE000E100U



/******************************************************************************************/
/*                          SCB Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     SCB_u32__BASE_ADDRESS            0xE000ED00



/******************************************************************************************/
/*                          RCC Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     RCC_u32__BASE_ADDRESS            0x40021000U



/******************************************************************************************/
/*                          GPIO Peripheral Base Addresses                                */
/******************************************************************************************/

#define     GPIO_PORTA_u32_BASE_ADDRESS      0x40010800U
#define     GPIO_PORTB_u32_BASE_ADDRESS      0x40010C00U
#define     GPIO_PORTC_u32_BASE_ADDRESS      0x40011000U
#define     GPIO_PORTD_u32_BASE_ADDRESS      0x40011400U
#define     GPIO_PORTE_u32_BASE_ADDRESS      0x40011800U



/******************************************************************************************/
/*                          AFIO Peripheral Base Addresses                                */
/******************************************************************************************/

#define     AFIO_u32_BASE_ADDRESS            0x40010000U



/******************************************************************************************/
/*                          ADC Peripheral Base Addresses                                */
/******************************************************************************************/

#define     ADC1_u32_BASE_ADDRESS            0x40012400U
#define     ADC2_u32_BASE_ADDRESS            0x40012800U



/******************************************************************************************/
/*                          Timer Peripheral Base Addresses                               */
/******************************************************************************************/

#define     TIM1_u32_BASE_ADDRESS            0x40012C00U
#define     TIM2_u32_BASE_ADDRESS            0x40000000U
#define     TIM3_u32_BASE_ADDRESS            0x40000400U
#define     TIM4_u32_BASE_ADDRESS            0x40000800U



/******************************************************************************************/
/*                          RTC Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     RTC_u32_BASE_ADDRESS             0x40002800U


/******************************************************************************************/
/*                          SPI Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     SPI1_u32_BASE_ADDRESS            0x40013000U
#define     SPI2_u32_BASE_ADDRESS            0x40003800U



/******************************************************************************************/
/*                          USART Peripheral Base Addresses                               */
/******************************************************************************************/

#define     USART1_u32_BASE_ADDRESS          0x40013800U
#define     USART2_u32_BASE_ADDRESS          0x40004400U
#define     USART3_u32_BASE_ADDRESS          0x40004800U



/******************************************************************************************/
/*                          I2C Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     I2C1_u32_BASE_ADDRESS            0x40005400U
#define     I2C2_u32_BASE_ADDRESS            0x40005800U



/******************************************************************************************/
/*                          DMA Peripheral Base Addresses                                 */
/******************************************************************************************/

#define     DMA_u32_BASE_ADDRESS             0x40020000U



/******************************************************************************************/
/*                          EXTI Peripheral Base Addresses                                */
/******************************************************************************************/

#define     EXTI_u32_BASE_ADDRESS            0x40010400U



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            End of Peripherals Base Addresses Region                     *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            Start of Register Definitions Structures Region              *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/******************************************************************************************/
/*                          RCC Register Definitions Structure                            */
/******************************************************************************************/

typedef struct
{
	volatile u32  RCC_CR               ;   /*RCC Clock control register*/
	volatile u32  RCC_CFGR             ;   /*RCC Clock configuration register*/
	volatile u32  RCC_CIR              ;   /*RCC Clock interrupt register (*/
	volatile u32  RCC_APB2RSTR         ;   /*RCC APB2 peripheral reset register*/
	volatile u32  RCC_APB1RSTR         ;   /*RCC APB1 peripheral reset register*/
	volatile u32  RCC_AHBENR           ;   /*RCC AHB peripheral clock enable register*/
	volatile u32  RCC_APB2ENR          ;   /*RCC APB2 peripheral clock enable register*/
	volatile u32  RCC_APB1ENR          ;   /*RCC APB1 peripheral clock enable register*/
	volatile u32  RCC_BDCR             ;   /*RCC Backup domain control register*/
	volatile u32  RCC_CSR              ;   /*RCC Control/status register*/
	volatile u32  RCC_AHBSTR           ;   /*RCC AHB peripheral clock reset register*/
	volatile u32  RCC_CFGR2            ;   /*RCC Clock configuration register2*/
}RCC_RegDef_t;



/******************************************************************************************/
/*                          NVIC Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
	volatile u32  NVIC_ISER[8]         ;   /*Interrupt Set-enable Registers*/
	volatile u32  NVIC_ICER[8]         ;   /*Interrupt Clear-enable Registers*/
	volatile u32  NVIC_ISPR[8]         ;   /*Interrupt Set-pending Registers*/
	volatile u32  NVIC_ICPR[8]         ;   /*Interrupt Clear-pending Registers*/
	volatile u32  NVIC_IABR[8]         ;   /*Interrupt Active Bit Registers*/
	volatile u8   NVIC_IPR[240]        ;   /*Interrupt Priority Registers*/
}NVIC_RegDef_t;



/******************************************************************************************/
/*                          SCB Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
    volatile u32  SCB_CPUID            ;   /*CPUID Base Register*/
	volatile u32  SCB_ICSR             ;   /*Interrupt Control and State Register*/
	volatile u32  SCB_VTOR             ;   /*Vector Table Offset Register*/
    volatile u32  SCB_AIRCR            ;   /*Application Interrupt and Reset Control Register*/
    volatile u32  SCB_SCR              ;   /*System Control Register*/
    volatile u32  SCB_CCR              ;   /*Configuration and Control Register*/
    volatile u32  SCB_SHPR[3]          ;   /*System Handler Priority Register[3]*/
    volatile u32  SCB_SHCRS            ;   /*System Handler Control and State Register*/
    volatile u32  SCB_CFSR             ;   /*Configurable Fault Status Register*/
    volatile u32  SCB_HFSR             ;   /*HardFault Status Register*/
    volatile u32  SCB_RESERVED[2]      ;   /*Reserved Bytes*/
    volatile u32  SCB_MMAR             ;   /*MemManage Fault Address Register*/
    volatile u32  SCB_BFAR             ;   /*BusFault Address Register */
    volatile u32  SCB_AFSR             ;   /*Auxiliary Fault Status Register*/
}SCB_RegDef_t;



/******************************************************************************************/
/*                          EXTI Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
    volatile u32  EXTI_IMR             ;   /*Interrupt mask register*/
    volatile u32  EXTI_EMR             ;   /*Event mask register*/
    volatile u32  EXTI_RTSR            ;   /*Rising trigger selection register*/
    volatile u32  EXTI_FTSR            ;   /*Falling trigger selection register*/
    volatile u32  EXTI_SWIER           ;   /*Software interrupt event register*/
	volatile u32  EXTI_PR              ;   /*Pending register*/
}EXTI_RegDef_t;



/******************************************************************************************/
/*                          GPIO Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
	volatile u32  GPIO_CRL             ;   /*GPIO Port Configuration register Low*/
	volatile u32  GPIO_CRH             ;   /*GPIO Port Configuration Register High*/
	volatile u32  GPIO_IDR             ;   /*GPIO Port Input Data Register */
	volatile u32  GPIO_ODR             ;   /*GPIO Port Output Data Register */
	volatile u32  GPIO_BSRR            ;   /*GPIO Port Bit Set/Reset Register */
	volatile u32  GPIO_BRR             ;   /*GPIO Port Bit Reset Register*/
	volatile u32  GPIO_LCKR            ;   /*GPIO Port Configuration Lock Register */

}GPIO_RegDef_t;



/******************************************************************************************/
/*                          AFIO Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
	volatile u32  AFIO_EVCR            ;   /*Event control register*/
	volatile u32  AFIO_MAPR            ;   /*AF remap and debug I/O configuration register*/
	volatile u32  AFIO_EXTICR[4]       ;   /*External interrupt configuration register*/
	volatile u32  AFIO_MAPR2           ;   /*AF remap and debug I/O configuration register2*/
}AFIO_RegDef_t;



/******************************************************************************************/
/*                          SysTick Register Definitions Structure                        */
/******************************************************************************************/

typedef struct
{
	volatile u32  SYST_CSR             ;   /*SysTick Control and Status Register */
	volatile u32  SYST_RVR             ;   /*SysTick Reload Value Register*/
	volatile u32  SYST_CVR             ;   /* SysTick Current Value Register*/
	volatile u32  SYST_CALIB           ;   /* SysTick Calibration Value Register*/

}SYSTICK_RegDef_t;



/******************************************************************************************/
/*                          SPI Register Definitions Structure                          */
/******************************************************************************************/

typedef struct
{
	volatile u32  SPI_CR1              ;   /*SPI control register 1 [not used in I2S mode]*/
	volatile u32  SPI_CR2              ;   /*SPI control register 2*/
	volatile u32  SPI_SR               ;   /*SPI status register*/
	volatile u32  SPI_DR               ;   /*SPI data register*/
	volatile u32  SPI_CRCPR            ;   /*SPI CRC polynomial register [not used in I2S Mode]*/
	volatile u32  SPI_RXCRCR           ;   /*SPI RX CRC register [not used in I2S mode]*/
	volatile u32  SPI_TXCRCR           ;   /*SPI TX CRC register [not used in I2S mode]*/
	volatile u32  SPI_I2SCFGR          ;   /*SPI_I2S configuration register*/
	volatile u32  SPI_I2SPR            ;   /*SPI_I2S prescaler register*/
}SPI_RegDef_t;



/******************************************************************************************/
/*                          USART Register Definitions Structure                          */
/******************************************************************************************/

typedef struct
{
	volatile u32  USART_SR             ;   /*Status register*/
	volatile u32  USART_DR             ;   /*Data register*/
	volatile u32  USART_BRR            ;   /*Baud rate register*/
	volatile u32  USART_CR1            ;   /*Control register 1*/
	volatile u32  USART_CR2            ;   /*Control register 2*/
	volatile u32  USART_CR3            ;   /*Control register 3*/
	volatile u32  USART_GTPR           ;   /*Guard time and prescaler register */
}USART_RegDef_t;



/******************************************************************************************/
/*                          DMA Register Definitions Structure                          */
/******************************************************************************************/


/*to get address of these registers for each channel we need channel num(1..7)*/
typedef struct
{
	volatile u32  DMA_CCR              ;   /*DMA channel x configuration register*/
    volatile u32  DMA_CNDTR            ;   /*DMA channel x number of data register*/
    volatile u32  DMA_CPAR             ;   /*DMA channel x peripheral address register*/
    volatile u32  DMA_CMAR             ;   /*DMA channel x memory address register*/
    volatile u32  DMA_RESERVED         ;   /*Reserved Bytes*/
}DMA_CHANNEL_Reg_t;

typedef struct
{
	volatile u32  DMA_ISR              ;   /*DMA interrupt status register*/
	volatile u32  DMA_IFCR             ;   /*DMA interrupt flag clear register*/
	DMA_CHANNEL_Reg_t DMA_CH[7]  ;   /*7 Channels for DMA1*/
}DMA_RegDef_t;



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            End of Register Definitions Structures Region                *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            Start of Macros Definitions Region                           *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/******************************************************************************************/
/*                          Macros Definitions for RCC                                    */
/******************************************************************************************/

#define     RCC             ((RCC_RegDef_t*)RCC_u32__BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for GPIO Port                              */
/******************************************************************************************/

#define     GPIO_PORTA      ((GPIO_RegDef_t*)GPIO_PORTA_u32_BASE_ADDRESS)
#define     GPIO_PORTB      ((GPIO_RegDef_t*)GPIO_PORTB_u32_BASE_ADDRESS)
#define     GPIO_PORTC      ((GPIO_RegDef_t*)GPIO_PORTC_u32_BASE_ADDRESS)
#define     GPIO_PORTD      ((GPIO_RegDef_t*)GPIO_PORTD_u32_BASE_ADDRESS)
#define     GPIO_PORTE      ((GPIO_RegDef_t*)GPIO_PORTE_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for AFIO                                   */
/******************************************************************************************/

#define     AFIO            ((AFIO_RegDef_t*)AFIO_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for SYSTICK                                */
/******************************************************************************************/

#define     SYSTICK         ((SYSTICK_RegDef_t*)SYSTICK_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for NVIC                                */
/******************************************************************************************/

#define     NVIC            ((NVIC_RegDef_t*)NVIC_u32__BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for SCB                                */
/******************************************************************************************/

#define     SCB             ((SCB_RegDef_t*)SCB_u32__BASE_ADDRESS)


/******************************************************************************************/
/*                          Macros Definitions for EXTI                                    */
/******************************************************************************************/

#define     EXTI            ((EXTI_RegDef_t*)EXTI_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for SPI                                    */
/******************************************************************************************/

#define     SPI_1           ((SPI_RegDef_t*)SPI1_u32_BASE_ADDRESS)
#define     SPI_2           ((SPI_RegDef_t*)SPI2_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for USART                                  */
/******************************************************************************************/

#define     USART_1         ((USART_RegDef_t*)USART1_u32_BASE_ADDRESS)
#define     USART_2         ((USART_RegDef_t*)USART2_u32_BASE_ADDRESS)
#define     USART_3         ((USART_RegDef_t*)USART3_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for DMA                                  */
/******************************************************************************************/

#define     DMA             ((DMA_RegDef_t*)DMA_u32_BASE_ADDRESS)


/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            End of Macros Definitions Region                             *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            Start of Enums Definitions Region                            *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/



typedef enum
{
	Bit_0 = 0 ,
	Bit_1     ,
	Bit_2     ,
	Bit_3     ,
	Bit_4     ,
	Bit_5     ,
	Bit_6     ,
	Bit_7     ,
	Bit_8     ,
	Bit_9     ,
	Bit_10    ,
	Bit_11    ,
	Bit_12    ,
	Bit_13    ,
	Bit_14    ,
	Bit_15    ,
	Bit_16    ,
	Bit_17    ,
	Bit_18    ,
	Bit_19    ,
	Bit_20    ,
	Bit_21    ,
	Bit_22    ,
	Bit_23    ,
	Bit_24    ,
	Bit_25    ,
	Bit_26    ,
	Bit_27    ,
	Bit_28    ,
	Bit_29    ,
	Bit_30    ,
	Bit_31    ,

}Bits_Num_t;



/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/
/***************************                            End of Enums Definitions Region                              *************************************/
/*********************************************************************************************************************************************************/
/*********************************************************************************************************************************************************/

#endif
