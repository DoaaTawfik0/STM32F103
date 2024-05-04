/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Updated on: May 4, 2024   ****************/
/***********************************************************/
/***********************************************************/

#ifndef  GPIO_INTERFACE_H_
#define  GPIO_INTERFACE_H_



/*******************************************************************/
/*                          Port Number                            */
/*******************************************************************/
typedef enum
{
	PORTA = 0   ,
	PORTB       ,
	PORTC       ,
	PORTD       ,
	PORTE
}GPIO_PORT_NUM_t;


/*******************************************************************/
/*                         PIN OUTPUT Value                        */
/*******************************************************************/
typedef enum
{
	PIN_LOW = 0 ,
	PIN_HIGH
}GPIO_PIN_VALUE_t;


/*******************************************************************/
/*                         PORT OUTPUT Value                        */
/*******************************************************************/
typedef enum
{
	PORT_LOW  = 0x0000 ,
	PORT_HIGH = 0xFFFF
}GPIO_PORT_VALUE_t;


/*******************************************************************/
/*                         Pins Number                             */
/*******************************************************************/
typedef enum
{
	PIN0 = 0   ,
	PIN1       ,
	PIN2       ,
	PIN3       ,
	PIN4       ,
	PIN5       ,
	PIN6       ,
	PIN7       ,
	PIN8       ,
	PIN9       ,
	PIN10      ,
	PIN11      ,
	PIN12      ,
	PIN13      ,
	PIN14      ,
	PIN15      ,
}GPIO_PIN_NUM_t;


/*******************************************************************/
/*                         Pins Mode                               */
/*******************************************************************/

typedef enum
{
	PIN_INPUT_FLOATING  = 0b0100                                     ,
	PIN_INPUT_PULL_UP   = 0b11000                                    ,
	PIN_INPUT_PULL_DOWN = 0b1000                                     ,
	PIN_INPUT_ANALOG    = 0b0000                                     ,

	PIN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0b0101                  ,
	PIN_OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0b0110                  ,
	PIN_OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0b0111                  ,

	PIN_OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0b0001                  ,
	PIN_OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0b0010                  ,
	PIN_OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0b0011                  ,

	PIN_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0b1101        ,
	PIN_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0b1110        ,
	PIN_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0b1111        ,

	PIN_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0b1001        ,
	PIN_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0b1010        ,
	PIN_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0b1011

}GPIO_PIN_MODE_t;


/*******************************************************************/
/*                         Port Mode                               */
/*******************************************************************/

typedef enum
{
	PORT_INPUT_FLOATING  = 1145324612                                 ,
	PORT_INPUT_PULL_UP   = 0x8889                                     ,
	PORT_INPUT_PULL_DOWN = 0x8888                                     ,
	PORT_INPUT_ANALOG    = 0x0000                                     ,

	PORT_OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0x5555                  ,
	PORT_OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0x6666                  ,
	PORT_OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0x7777                  ,

	PORT_OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0x1111                  ,
	PORT_OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0x2222                  ,
	PORT_OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0x3333                  ,

	PORT_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0xDDDD        ,
	PORT_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0xEEEE        ,
	PORT_ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0xFFFF        ,

	PORT_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0x9999        ,
	PORT_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0xAAAA        ,
	PORT_ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0xBBBB

}GPIO_PORT_MODE_t;


/*******************************************************************/
/*                          PIN Configuration                      */
/*******************************************************************/
typedef  struct
{
	GPIO_PORT_NUM_t  PORT_ID;
	GPIO_PIN_NUM_t   PIN_ID ;
	GPIO_PIN_MODE_t  PIN_MODE;
}GPIO_PIN_CONFIG_t;


/*******************************************************************/
/*                          PORT Configuration                      */
/*******************************************************************/
typedef  struct
{
	GPIO_PORT_NUM_t   PORT_ID;
	GPIO_PORT_MODE_t  PORT_MODE;
}GPIO_PORT_CONFIG_t;


/*******************************************************************/
/*                         Functions Prototypes                    */
/*******************************************************************/

ES_t  GPIO_enu_PIN_Initialize(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig);
ES_t  GPIO_enu_PORT_Initialize(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig);
ES_t  GPIO_enu_SetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , GPIO_PIN_VALUE_t Copy_enuPin_Value);
ES_t  GPIO_enu_GetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , u8* Copy_Pu8Pin_Value);
ES_t  GPIO_enu_SetPortValue(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig , GPIO_PORT_VALUE_t Copy_enuPort_Value);
ES_t  GPIO_enu_GetPortValue(GPIO_PORT_CONFIG_t* Copy_Pstr_PortConfig , u16* Copy_Pu16Port_Value);
ES_t  GPIO_enu_TogglePinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig);


#endif
