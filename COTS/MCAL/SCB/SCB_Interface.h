/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 17, 2024         ****************/
/***********************************************************/
/***********************************************************/

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_




typedef enum
{
	SCB_PRIGROUP_4 = 4 ,
	SCB_PRIGROUP_5 ,
	SCB_PRIGROUP_6 ,
	SCB_PRIGROUP_7
}SCB_PRIGROUP_t;



typedef enum
{
	/*Number represent System handler number for the exception */
	MemManage_Exception = 4,
	BusFault_Exception,
	UsageFault_Exception,
	SVCall_Exception = 11,
	PendSV_Exception = 14,
	SysTick_Exception

}SCB_Exception_Type_t;



typedef enum
{
	PRIORITY_ZERO          ,
	PRIORITY_ONE           ,
	PRIORITY_TWO           ,
	PRIORITY_THREE         ,
	PRIORITY_FOUR          ,
	PRIORITY_FIVE          ,
	PRIORITY_SIX           ,
	PRIORITY_SEVEN         ,
	PRIORITY_EIGHT         ,
	PRIORITY_NINE          ,
	PRIORITY_TEN           ,
	PRIORITY_ELEVEN        ,
	PRIORITY_TWELVE        ,
	PRIORITY_THIRTEEN      ,
	PRIORITY_FOURTEEN      ,
	PRIORITY_FIFTEEN
}SCB_Exception_Priority_t;


/***********************************************************************************/
/*************************** Functions Prototypes  *********************************/
/***********************************************************************************/


/*From Interrupt Control and State Register ICSR*/
ES_t   SCB_enuSet_NMI_Pending_bit(void);
ES_t   SCB_enuSet_PendSV_Pending_bit(void);
ES_t   SCB_enuSet_SysTick_Pending_bit(void);
ES_t   SCB_enuClear_PendSV_Pending_bit(void);
ES_t   SCB_enuClear_SysTick_Pending_bit(void);

/*From Application Interrupt and Reset Control Register AIRCR*/
ES_t   SCB_enuSet_PRIGROUP(SCB_PRIGROUP_t Copy_enuPRIGROUP);

/*From System Handler Priority Registers SHPR*/
ES_t   SCB_enuSet_Exception_Prority(SCB_Exception_Type_t Copy_enuException  , SCB_Exception_Priority_t Copy_enuPriority);




#endif
