#ifndef  STM32F103XX_H_
#define  STM32F103XX_H_


/******************************************************************************************/
/*                          GPIO Peripheral Base Addresses                                */
/******************************************************************************************/

#define     GPIO_PORTA_u32_BASE_ADDRESS      0x40010800U
#define     GPIO_PORTB_u32_BASE_ADDRESS      0x40010C00U
#define     GPIO_PORTC_u32_BASE_ADDRESS      0x40011000U
#define     GPIO_PORTD_u32_BASE_ADDRESS      0x40011400U
#define     GPIO_PORTE_u32_BASE_ADDRESS      0x40011800U



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


#define     GPIO_PORTA      ((GPIO_RegDef_t*)GPIO_PORTA_u32_BASE_ADDRESS)
#define     GPIO_PORTB      ((GPIO_RegDef_t*)GPIO_PORTB_u32_BASE_ADDRESS)
#define     GPIO_PORTC      ((GPIO_RegDef_t*)GPIO_PORTC_u32_BASE_ADDRESS)
#define     GPIO_PORTD      ((GPIO_RegDef_t*)GPIO_PORTD_u32_BASE_ADDRESS)
#define     GPIO_PORTE      ((GPIO_RegDef_t*)GPIO_PORTE_u32_BASE_ADDRESS)






#endif
