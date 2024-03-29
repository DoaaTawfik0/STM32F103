/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer: LIBRARY            ****************/
/**************   Version: 1.00             ****************/
/**************   Update_Date:3/7/2024      ****************/
/***********************************************************/
/***********************************************************/

#ifndef  STM32F103XX_H_
#define  STM32F103XX_H_


/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/***************************                            Peripherals Base Addresses                    ************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/



/******************************************************************************************/
/*                          RCC Peripheral Base Addresses                                 */
/******************************************************************************************/

#define    RCC_u32__BASE_ADDRESS             0x40021000U



/******************************************************************************************/
/*                          GPIO Peripheral Base Addresses                                */
/******************************************************************************************/

#define     GPIO_PORTA_u32_BASE_ADDRESS      0x40010800U
#define     GPIO_PORTB_u32_BASE_ADDRESS      0x40010C00U
#define     GPIO_PORTC_u32_BASE_ADDRESS      0x40011000U
#define     GPIO_PORTD_u32_BASE_ADDRESS      0x40011400U
#define     GPIO_PORTE_u32_BASE_ADDRESS      0x40011800U



/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/***************************                            Registers Definitions Structures              ************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/



/******************************************************************************************/
/*                          RCC Register Definitions Structure                            */
/******************************************************************************************/

typedef struct
{
    u32  RCC_CR       ;   /*RCC Clock control register*/
    u32  RCC_CFGR     ;   /*RCC Clock configuration register*/
	u32  RCC_CIR      ;   /*RCC Clock interrupt register (*/
	u32  RCC_APB2RSTR ;   /*RCC APB2 peripheral reset register*/
	u32  RCC_APB1RSTR ;   /*RCC APB1 peripheral reset register*/
	u32  RCC_AHBENR   ;   /*RCC AHB peripheral clock enable register*/
	u32  RCC_APB2ENR  ;   /*RCC APB2 peripheral clock enable register*/
	u32  RCC_APB1ENR  ;   /*RCC APB1 peripheral clock enable register*/
	u32  RCC_BDCR     ;   /*RCC Backup domain control register*/
	u32  RCC_CSR      ;   /*RCC Control/status register*/
}RCC_RegDef_t;



/******************************************************************************************/
/*                          GPIO Register Definitions Structure                           */
/******************************************************************************************/

typedef struct
{
	u32  GPIO_CRL;           /*GPIO Port Configuration register Low*/
	u32  GPIO_CRH;           /*GPIO Port Configuration Register High*/
	u32  GPIO_IDR;           /*GPIO Port Input Data Register */
	u32  GPIO_ODR;           /*GPIO Port Output Data Register */
    u32  GPIO_BSRR;          /*GPIO Port Bit Set/Reset Register */
    u32  GPIO_BRR;           /*GPIO Port Bit Reset Register*/
	u32  GPIO_LCKR;          /*GPIO Port Configuration Lock Register */

}GPIO_RegDef_t;




/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/***************************                            Macros Definitions                            ************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/



/******************************************************************************************/
/*                          Macros Definitions for GPIO Port                              */
/******************************************************************************************/

#define     GPIO_PORTA      ((GPIO_RegDef_t*)GPIO_PORTA_u32_BASE_ADDRESS)
#define     GPIO_PORTB      ((GPIO_RegDef_t*)GPIO_PORTB_u32_BASE_ADDRESS)
#define     GPIO_PORTC      ((GPIO_RegDef_t*)GPIO_PORTC_u32_BASE_ADDRESS)
#define     GPIO_PORTD      ((GPIO_RegDef_t*)GPIO_PORTD_u32_BASE_ADDRESS)
#define     GPIO_PORTE      ((GPIO_RegDef_t*)GPIO_PORTE_u32_BASE_ADDRESS)



/******************************************************************************************/
/*                          Macros Definitions for RCC                                    */
/******************************************************************************************/

#define     RCC             ((RCC_RegDef_t*)RCC_u32__BASE_ADDRESS)










/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/
/***************************                            Enums Definitions                             ************************************/
/*****************************************************************************************************************************************/
/*****************************************************************************************************************************************/

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




#endif
