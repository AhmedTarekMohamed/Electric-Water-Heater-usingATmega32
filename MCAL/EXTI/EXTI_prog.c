/*
 * EXTI_prog.c
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"

extern u8 EXTI_u8EXTINum;
extern EXTI_t EXTI_AstrEXTIConfig [];
static void (*EXTI_ApfunISRFun [ 3 ])(void*) = {NULL,NULL,NULL};
static void * EXTI_ApvidISRParameter [3] =	{NULL,NULL,NULL};
ES_t EXTI_enuInit(void)
{
	ES_t Local_enuErrorState= ES_NOK;
#if EXTI_NUM<=3

	for(u8 Local_u8Iter=0;Local_u8Iter<EXTI_u8EXTINum;Local_u8Iter++)
	{

		if(EXTI_AstrEXTIConfig[Local_u8Iter].intPin==INT0)
		{
			MCUCR &=~(3);
			switch(EXTI_AstrEXTIConfig[Local_u8Iter].senseLvl)
			{

			case LOW_LEVEL:
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<0);
				break;
			case FALLING:
				MCUCR |= (1<<1);
				break;
			case RISING:
				MCUCR |= (3<<0);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				return Local_enuErrorState ;
			}
			if(ENABLED == EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR |=(1<<6);

			else if(POLLING ==  EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR &=~(1<<6);
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				break ;
			}
		}
		else if(EXTI_AstrEXTIConfig[Local_u8Iter].intPin==INT1)
		{
			MCUCR &=~(3<<2);
			switch(EXTI_AstrEXTIConfig[Local_u8Iter].senseLvl)
			{

			case LOW_LEVEL:
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<2);
				break;
			case FALLING:
				MCUCR |= (1<<3);
				break;
			case RISING:
				MCUCR |= (3<<2);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				return Local_enuErrorState ;
			}
			if(ENABLED == EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR |=(1<<7);
			else if(POLLING ==  EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR &=~(1<<7);
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				break ;
			}
		}
		else if(EXTI_AstrEXTIConfig[Local_u8Iter].intPin==INT2)
		{
			switch(EXTI_AstrEXTIConfig[Local_u8Iter].senseLvl)
			{
			case FALLING:
				MCUCSR &= ~(1<<6);
				break;
			case RISING:
				MCUCSR |= (1<<6);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				return Local_enuErrorState ;
			}

			if(ENABLED == EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR |=(1<<5);
			else if(POLLING ==  EXTI_AstrEXTIConfig[Local_u8Iter].IntMode)	GICR &=~(1<<5);
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE ;
				break ;
			}
		}
		else Local_enuErrorState=ES_OUT_OF_RANGE;
	}
#else
#error"the number of interrupt array is out of range "
#endif
	return Local_enuErrorState;
}

ES_t EXTI_enuSetSenseLevel(EXTI_t * Copy_pstrEXTIInfo , u8 Copy_u8SenseLevel)
{
	ES_t Local_enuErrorState= ES_NOK;
	if(Copy_pstrEXTIInfo!= NULL)
	{

		if(Copy_pstrEXTIInfo->intPin == INT0)
		{
			MCUCR &=~(3);
			switch(Copy_u8SenseLevel)
			{
			case LOW_LEVEL:
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<0);
				break;
			case FALLING:
				MCUCR |= (2<<0);
				break;
			case RISING:
				MCUCR |= (3<<0);
				break;
			default:
				return ES_OUT_OF_RANGE  ;
			}
			Local_enuErrorState=ES_OK;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT1)
		{
			MCUCR &=~(3<<2);
			switch(Copy_u8SenseLevel)
			{

			case LOW_LEVEL:
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<2);
				break;
			case FALLING:
				MCUCR |= (1<<3);
				break;
			case RISING:
				MCUCR |= (3<<2);
				break;
			default:
				return  ES_OUT_OF_RANGE ;
			}
			Local_enuErrorState=ES_OK;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT2)
		{
			switch(Copy_u8SenseLevel)
			{
			case FALLING:
				MCUCSR &= ~(1<<6);
				break;
			case RISING:
				MCUCSR |= (1<<6);
				break;
			default:
				return ES_OUT_OF_RANGE ;
			}
			Local_enuErrorState=ES_OK;
		}
		else	return ES_OUT_OF_RANGE;

	}
	else Local_enuErrorState = ES_NULL_POINTER;
	return Local_enuErrorState;
}

ES_t EXTI_enuEnableInterrupt(EXTI_t * Copy_pstrEXTIInfo)
{
	ES_t Local_enuErrorState= ES_NOK;
	if(Copy_pstrEXTIInfo!= NULL)
	{
		if(Copy_pstrEXTIInfo->intPin == INT0)
		{
			GICR |=(1<<6);
			Local_enuErrorState = ES_OK ;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT1)
		{
			GICR |=(1<<7);
			Local_enuErrorState = ES_OK ;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT2)
		{
			GICR |=(1<<5);
			Local_enuErrorState = ES_OK ;
		}
		else	return ES_OUT_OF_RANGE;

	}
	else Local_enuErrorState = ES_NULL_POINTER;

	return Local_enuErrorState;
}


ES_t EXTI_enuDisableInterrupt(EXTI_t * Copy_pstrEXTIInfo)
{
	ES_t Local_enuErrorState= ES_NOK;
	if(Copy_pstrEXTIInfo!= NULL)
	{
		if(Copy_pstrEXTIInfo->intPin == INT0)
		{
			GICR &=~(1<<6);
			Local_enuErrorState = ES_OK ;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT1)
		{
			GICR &=~(1<<7);
			Local_enuErrorState = ES_OK ;
		}
		else if(Copy_pstrEXTIInfo->intPin == INT2)
		{
			GICR &=~(1<<5);
			Local_enuErrorState = ES_OK ;
		}
		else	return ES_OUT_OF_RANGE;

	}
	else Local_enuErrorState = ES_NULL_POINTER;


	return Local_enuErrorState;
}

ES_t EXTI_enuCallBack(EXTI_t * Copy_pstrEXTIInfo , void (*Copy_pfunAppFun)(void*) , void * Copy_pvidParameter)
{
	ES_t Local_enuErrorState= ES_NOK;

	if(Copy_pstrEXTIInfo!= NULL && Copy_pfunAppFun!= NULL)
	{
		if(Copy_pstrEXTIInfo->intPin <=INT2)
		{
			Local_enuErrorState = ES_OK ;
			EXTI_ApfunISRFun[Copy_pstrEXTIInfo->intPin] = Copy_pfunAppFun ;
			EXTI_ApvidISRParameter [Copy_pstrEXTIInfo->intPin] = Copy_pvidParameter ;
		}
		else Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	else Local_enuErrorState = ES_NULL_POINTER ;
	return Local_enuErrorState;
}
void __vector_1 (void)__attribute__((signal)); //int0
void __vector_2 (void)__attribute__((signal));	//int1
void __vector_3 (void)__attribute__((signal));	//int2

void __vector_1 (void)
{
	if(EXTI_ApfunISRFun[INT0]!=NULL)
	{
		EXTI_ApfunISRFun[INT0](EXTI_ApvidISRParameter[INT0]);
	}
}

void __vector_2 (void)
{
	if(EXTI_ApfunISRFun[INT1]!=NULL)
	{
		EXTI_ApfunISRFun[INT1](EXTI_ApvidISRParameter[INT1]);
	}
}
void __vector_3 (void)
{
	if(EXTI_ApfunISRFun[INT2]!=NULL)
	{
		EXTI_ApfunISRFun[INT2](EXTI_ApvidISRParameter[INT2]);
	}
}
