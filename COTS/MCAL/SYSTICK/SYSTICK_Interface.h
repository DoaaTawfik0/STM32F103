/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Update_Date:May 5, 2024   ****************/
/***********************************************************/
/***********************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


typedef enum
{
	EXTERNAL_CLK  = 0,
	PROCESSOR_CLK
}SYSTICK_CLKSOURCE_t;




/********************************************************************************************/
/******************************** Functions Prototypes       ********************************/
/********************************************************************************************/
ES_t  SYSTICK_enuInitialize_CLK(SYSTICK_CLKSOURCE_t Copy_enuCLKSOURCE);
ES_t  SYSTICk_enuSetPreloadValue(u32 Copy_u32ReloadValue);
ES_t  SYSTICK_enuEnable_SysTick_INT(void);
ES_t  SYSTICK_enuDisable_SysTick_INT(void);
ES_t  SYSTICK_enuEnable_SysTick(void);
ES_t  SYSTICK_enuDisable_SysTick(void);

ES_t  SYSTICK_enuGet_COUNTFLAG(u8* Copy_Pu8Flag_Value);
ES_t  SYSTICK_enuGet_CurrentValue(u32* Copy_Pu32CurrentValue);

ES_t  SYSTICK_enuSync_Delay_ms(u32 Copy_u32Delay_ms);
ES_t  SYSTICK_enuAsync_Delay_ms(u32 Copy_u32Delay_ms , void (*Copy_Pfun_AppFun)(void*) , void* Copy_PV_AppParameter);


#endif
