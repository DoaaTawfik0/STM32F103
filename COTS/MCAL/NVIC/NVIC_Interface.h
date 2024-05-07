/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:May 7, 2024          ****************/
/***********************************************************/
/***********************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


typedef enum
{
	/*Window watchdog interrupt*/
	 WWDG_INT = 0                                                        ,
	 /*PVD through EXTI Line detection interrupt*/
	 PVD_INT                                                             ,
	 /*Tamper interrupt*/
	 TAMPER_INT                                                          ,
	 /*RTC global interrupt*/
	 RTC_INT                                                             ,
	 /*Flash global interru*/
	 FLASH_INT                                                           ,
	 /*RCC global interrupt*/
	 RCC_INT                                                             ,
	 /*EXTI Line0 interrupt*/
	 EXTI0_INT                                                           ,
	 /*EXTI Line1 interrupt*/
	 EXTI1_INT                                                           ,
	 /*EXTI Line2 interrupt*/
	 EXTI2_INT                                                           ,
	 /*EXTI Line3 interrupt*/
	 EXTI3_INT                                                           ,
	 /*EXTI Line4 interrupt*/
	 EXTI4_INT                                                           ,
	 /*DMA1 Channel1 global interrupt*/
	 DMA1_Channel1_INT                                                   ,
	 /*DMA1 Channel2 global interrupt*/
	 DMA1_Channel2_INT                                                   ,
	 /*DMA1 Channel3 global interrupt*/
	 DMA1_Channel3_INT                                                   ,
	 /*DMA1 Channel4 global interrupt*/
	 DMA1_Channel4_INT                                                   ,
	 /*DMA1 Channel5 global interrupt*/
	 DMA1_Channel5_INT                                                   ,
	 /*DMA1 Channel6 global interrupt*/
	 DMA1_Channel6_INT                                                   ,
	 /*DMA1 Channel7 global interrupt*/
	 DMA1_Channel7_INT                                                   ,
	 /*ADC1 and ADC2 global interrupt*/
	 ADC1_2_INT                                                          ,
	 /*USB High Priority or CAN TX interrupts*/
	 USB_HP_CAN_TX_INT                                                   ,
	 /*USB Low Priority or CAN RX0 interrupts*/
	 USB_LP_CAN_RX0_INT                                                  ,
	 /*CAN RX1 interrupt*/
	 CAN_RX1_INT                                                         ,
	 /*CAN SCE interrupt*/
	 CAN_SCE_INT                                                         ,
	 /*EXTI Line[5] interrupts*/
	 EXTI5_INT = 23                                                      ,
	 /*EXTI Line[6] interrupts*/
	 EXTI6_INT = 23                                                      ,
	 /*EXTI Line[7] interrupts*/
	 EXTI7_INT = 23                                                      ,
	 /*EXTI Line[8] interrupts*/
	 EXTI8_INT = 23                                                      ,
	 /*EXTI Line[9] interrupts*/
	 EXTI9_INT = 23                                                      ,
	 /*TIM1 Break interrupt*/
	 TIM1_BRK_INT                                                        ,
	 /*TIM1 Update interrupt*/
	 TIM1_UP_INT                                                         ,
	 /*TIM1 Trigger and Commutation interrupts*/
	 TIM1_TRG_COM_INT                                                    ,
	 /*TIM1 Capture Compare interrupt*/
	 TIM1_CC_INT                                                         ,
	 /*TIM2 global interrupt*/
	 TIM2_INT                                                            ,
	 /*TIM3 global interrupt*/
	 TIM3_INT                                                            ,
	 /* TIM4 global interrupt*/
	 TIM4_INT                                                            ,
	 /*I2C1 event interrupt*/
	 I2C1_EV_INT                                                         ,
	 /*I2C1 error interrupt*/
	 I2C1_ER_INT                                                         ,
	 /*I2C2 event interrupt*/
	 I2C2_EV_INT                                                         ,
	 /*I2C2 error interrupt*/
	 I2C2_ER_INT                                                         ,
	 /*SPI1 global interrup*/
	 SPI1_INT                                                            ,
	 /*SPI2 global interrupt*/
	 SPI2_INT                                                            ,
	 /*USART1 global interrupt*/
	 USART1_INT                                                          ,
	 /*USART2 global interrupt*/
	 USART2_INT                                                          ,
	 /*USART3 global interrupt*/
	 USART3_INT                                                          ,
	 /*EXTI Line[10] interrupts*/
	 EXTI10_INT  = 40                                                    ,
	 /*EXTI Line[11] interrupts*/
	 EXTI11_INT  = 40                                                    ,
	 /*EXTI Line[12] interrupts*/
	 EXTI12_INT  = 40                                                    ,
	 /*EXTI Line[13] interrupts*/
	 EXTI13_INT  = 40                                                    ,
	 /*EXTI Line[14] interrupts*/
	 EXTI14_INT  = 40                                                    ,
	 /*EXTI Line[15] interrupts*/
	 EXTI15_INT  = 40                                                    ,
     /*RTC alarm through EXTI line interrupt*/
	 RTCAlarm_INT                                                        ,
	 /*USB wakeup from suspend through EXTI line interrupt*/
	 USBWakeup_INT                                                       ,
	 /* TIM8 Break interrupt*/
	 TIM8_BRK_INT                                                        ,
	 /*TIM8 Update interrupt*/
	 TIM8_UP_INT                                                         ,
	 /*TIM8 Trigger and Commutation interrupts*/
	 TIM8_TRG_COM_INT                                                    ,
	 /*TIM8 Capture Compare interrupt*/
	 TIM8_CC_INT                                                         ,
	 /*ADC3 global interrupt*/
	 ADC3_INT                                                            ,
	 /* FSMC global interrupt*/
	 FSMC_INT                                                            ,
	 /*SDIO global interrupt*/
	 SDIO_INT                                                            ,
	 /*TIM5 global interrupt*/
	 TIM5_INT                                                            ,
	 /*SPI3 global interrupt*/
	 SPI3_INT                                                            ,
	 /*UART4 global interrupt*/
	 UART4_INT                                                           ,
	 /* UART5 global interrupt*/
	 UART5_INT                                                           ,
	 /*TIM6 global interrupt*/
	 TIM6_INT                                                            ,
	 /*TIM7 global interrupt*/
	 TIM7_INT                                                            ,
	 /* DMA2 Channel1 global interrupt*/
	 DMA2_Channel1_INT                                                   ,
	 /* DMA2 Channel2 global interrupt*/
	 DMA2_Channel2_INT                                                   ,
	 /* DMA2 Channel3 global interrupt*/
	 DMA2_Channel3_INT                                                   ,
	 /*DMA2 Channel4 and DMA2 Channel5 global interrupts*/
	 DMA2_Channel4_5_INT

}IRQ_NUM_t;


typedef enum
{
	PENDED_INT,
	NOT_PENDED_INT
}Interrupt_PendingState_t;

typedef enum
{
	ACTIVATED_INT,
	DISACTIVATED_INT
}Interrupt_ActiveState_t;

ES_t  NVIC_enuEnable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVIC_enuDisable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVIC_enuGetEnabledINT_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Enabled_INT);
ES_t  NVIC_enuSetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVIC_enuClearPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVIC_enuGetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Pending_Flag);
ES_t  NVIC_enuSetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32 Copy_u32Priority);
ES_t  NVIC_enuGetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Prority);
ES_t  NVIC_enuGetActive_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Active_IRQ);


#endif
