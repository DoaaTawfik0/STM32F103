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
	LOW = 0 ,
	HIGH
}GPIO_PIN_VALUE_t;


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
	INPUT_FLOATING  = 0b0100                                     ,
	INPUT_PULL_UP   = 0b1000                                     ,
	INPUT_PULL_DOWN = 0b1000                                     ,   //How to differ????????????
	INPUT_ANALOG    = 0b0000                                     ,

	OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0b0101                  ,
	OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0b0110                  ,
	OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0b0111                  ,

	OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0b0001                  ,
	OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0b0010                  ,
	OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0b0011                  ,

	ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SPEED_10MHZ =  0b1101        ,
	ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_2MHZ  =  0b1110        ,
	ALTER_FUN_OUTPUT_OPEN_DRAIN_MAX_SOEED_50MHZ =  0b1111        ,

	ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SPEED_10MHZ =  0b1001        ,
	ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_2MHZ  =  0b1010        ,
	ALTER_FUN_OUTPUT_PUSH_PULL__MAX_SOEED_50MHZ =  0b1011

}GPIO_PIN_MODE_t;


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
/*                         Functions Prototypes                    */
/*******************************************************************/


ES_t  GPIO_enu_SetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , GPIO_PIN_VALUE_t Copy_enuPin_Value);
ES_t  GPIO_enu_GetPinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig , u8* Copy_Pu8Pin_Value);
ES_t  GPIO_enu_PIN_Initialize(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig);
ES_t  GPIO_enu_TogglePinValue(GPIO_PIN_CONFIG_t* Copy_Pstr_PinConfig);
ES_t  GPIO_enuLockPin(GPIO_PIN_CONFIG_t* Copy_PsPinConfig);
































/*

                   ,
	ALTERNATE_FUNCTION_OPEN_DRAIN_WITH_PULL_UP        ,
	ALTERNATE_FUNCTION_OPEN_DRAIN_WITH_PULL_DOWN      ,
	ALTERNATE_FUNCTION_OPEN_DRAIN_WITHOUT_PU_PD       ,
	ALTERNATE_FUNCTION_PUSH_PULL_WITH_PULL_UP         ,
	ALTERNATE_FUNCTION_PUSH_PULL_WITH_PULL_DOWN       ,
	ALTERNATE_FUNCTION_PUSH_PULL_WITHOUT_PU_PD        ,


typedef enum
{
	INPUT_MODE = 0,
	OUTPUT_MODE_MAX_SPEED_10MHZ,
	OUTPUT_MODE_MAX_SOEED_2MHZ,
	OUTPUT_MODE_MAX_SOEED_50MHZ
}GPIO_PIN_DIR_MODE_t;

//typedef enum
{
	ANALOG_MODE = 0,
	FLOATING_MODE ,
	PULL_UP_PULL_DOWN_MODE,      //How to differ?????
}GPIO_PIN_INPUT_MODE_t;

typedef enum
{
	OUTPUT_PUSH_PULL = 0,
	OUTPUT_OPEN_DRAIN ,
	ALTERNATE_FUNCTION_OUTPUT_PUSH_PULL,
	ALTERNATE_FUNCTION_OUTPUT_OPEN_DRAIN
}GPIO_PIN_OUTPUT_MODE_t;


*/








#endif
