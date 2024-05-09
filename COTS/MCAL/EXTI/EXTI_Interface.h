/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 9, 2024          ****************/
/***********************************************************/
/***********************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_LINE_0     ,
	EXTI_LINE_1     ,
	EXTI_LINE_2     ,
	EXTI_LINE_3     ,
	EXTI_LINE_4     ,
	EXTI_LINE_5     ,
	EXTI_LINE_6     ,
	EXTI_LINE_7     ,
	EXTI_LINE_8     ,
	EXTI_LINE_9     ,
	EXTI_LINE_10    ,
	EXTI_LINE_11    ,
	EXTI_LINE_12    ,
	EXTI_LINE_13    ,
	EXTI_LINE_14    ,
	EXTI_LINE_15    ,
	EXTI_LINE_16    ,
	EXTI_LINE_17    ,
	EXTI_LINE_18
}EXTI_Line_Num_t;

typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_FALLING_EDGE
}EXTI_Edge_Trigger_t;

typedef enum
{
	EXTI_INTERRUPT,
	EXTI_EVENT
}EXTI_Type_t;

typedef enum
{
	EXTI_ENABLE,
	EXTI_DISABLE
}EXTI_State_t;


typedef struct
{
	EXTI_Line_Num_t     EXTI_Line;
	EXTI_State_t        EXTI_State;
	EXTI_Edge_Trigger_t EXTI_EDGE;
    EXTI_Type_t         EXTI_Type;
}EXTI_CONFIG_t;

ES_t  EXTI_enuInitialize(EXTI_CONFIG_t* Copy_pstrEXTI_Config);

ES_t  EXTI_enuEnable_EXTI(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Type_t Copy_enuEXTI_Type);
ES_t  EXTI_enuDisable_EXTI(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Type_t Copy_enuEXTI_Type);

ES_t  EXTI_enuSet_Edge_Trigger(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Edge_Trigger_t Copy_enuEdge_Trigger);
ES_t  EXTI_enuClear_Edge_Trigger(EXTI_Line_Num_t Copy_enuEXTI_LINE , EXTI_Edge_Trigger_t Copy_enuEdge_Trigger);

ES_t  EXTI_enuSW_Interrupt(EXTI_Line_Num_t Copy_enuEXTI_LINE);

ES_t  EXTI_enuGet_Pending_Flag(EXTI_Line_Num_t Copy_enuEXTI_LINE , u8* Copy_pu8PendingState);
ES_t  EXTI_enuClear_Pending_Flag(EXTI_Line_Num_t Copy_enuEXTI_LINE);

ES_t  EXTI_enuCallBack_Function(void(*Copy_Pfun_AppFun)(void*) , void* Copy_PV_AppParameter);


#endif
