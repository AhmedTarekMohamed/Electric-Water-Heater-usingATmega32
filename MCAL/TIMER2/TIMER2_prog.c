/*
 * TIMER2_prog.c
 *
 *  Created on: Jul 30, 2022
 *      Author: abano
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"

#include "TIMER2_priv.h"
#include "TIMER2_config.h"

static void (*TIMER2_ApfunISRfun[])(void*) =  {NULL,NULL} ;

static void *TIMER2_ApvidISRParameter []= {NULL,NULL} ;

ES_t TIMER2_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if !(WAVEG_MOOD &~(TIM2_FastPWM))
	TCCR2 = WAVEG_MOOD;
#else
	#error"wave mood is out of range"
#endif
#if !(OC2_OUTMOOD &~TIM2_SETONCOMMATCH)
	TCCR2 |= OC2_OUTMOOD;
#else
	#error "OC2_OUTMOOD is out of range"
#endif
#if !(PRESCALLER & ~TIM2_PRE1024)
	TCCR2 |= PRESCALLER;
#else
	#error "PRESCALLER is out of range"
#endif

#if !(INTERRUPT_MOOD & ~(OVERFLOW_INTER|COMPMATCH_INTER))
	TIMSK &= ~(OVERFLOW_INTER|COMPMATCH_INTER);
	TIMSK |=INTERRUPT_MOOD;
	Local_enuErrorState=ES_OK ;
#else
	#error "interrupt mood is out of range"
#endif


	return Local_enuErrorState;
}

ES_t TIMER2_enuSetwaveMood(u8 Copy_u8WaveMood)
{
	ES_t Local_enuErrorState=ES_NOK;

	if (!(Copy_u8WaveMood &~(TIM2_FastPWM)))
	{
		TCCR2 &= ~TIM2_FastPWM;
		TCCR2 |= Copy_u8WaveMood;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}

ES_t TIMER2_enuSetOC2Mood(u8 Copy_u8OC2OutMood)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(!(Copy_u8OC2OutMood &~TIM2_SETONCOMMATCH))
	{
		TCCR2 &= ~TIM2_SETONCOMMATCH;
		TCCR2 |= Copy_u8OC2OutMood;
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES_t TIMER2_enuSetPWMDuty(u8 Copy_u8Duty)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8Duty<=100)
		if(TIM2_FastPWM == (TCCR2 & TIM2_FastPWM))
		{

			if(TIM2_SETONCOMMATCH ==(TCCR2 & TIM2_SETONCOMMATCH) )
			{
				OCR2 = 255ul - 255.f*Copy_u8Duty/ 100.f ;
				Local_enuErrorState = ES_OK;
			}
			else if(TIM2_CleraONCOMMATCH ==(TCCR2 & TIM2_SETONCOMMATCH))
			{
				OCR2 = ((256.f * Copy_u8Duty /100.f ) - 1 );
				Local_enuErrorState = ES_OK;
			}
			else Local_enuErrorState = ES_NOK;
		}
		else if(TIM2_PHASEcorrectWAVmood == (TCCR2 & TIM2_FastPWM) )
		{

			if(TIM2_SETONCOMMATCH ==(TCCR2 &  TIM2_SETONCOMMATCH) )
			{
				OCR2 = 255ull -  Copy_u8Duty * 255ull /100.f ;
				Local_enuErrorState = ES_OK;
			}
			else if(TIM2_CleraONCOMMATCH ==(TCCR2 & TIM2_SETONCOMMATCH))
			{
				OCR2 = Copy_u8Duty * 255ull /100.f;
				Local_enuErrorState = ES_OK;
			}
			else Local_enuErrorState = ES_NOK;
		}else ;
	else
		Local_enuErrorState = ES_OUT_OF_RANGE;

	return Local_enuErrorState;
}

ES_t TIMER2_enuSetthePrescaler(u8 Copy_u8Pres)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(!(Copy_u8Pres & ~TIM2_PRE1024))
	{
		TCCR2 &= ~TIM2_PRE1024;
		TCCR2 |=Copy_u8Pres;
		Local_enuErrorState = ES_OK;
	}
	else Local_enuErrorState=ES_OUT_OF_RANGE;
	return Local_enuErrorState;
}

ES_t TIMER2_enuEnableInterrupt(u8 Copy_u8InterruptMood)
{
	ES_t Local_enuErrorState=ES_NOK;
	if( !(Copy_u8InterruptMood & ~(OVERFLOW_INTER|COMPMATCH_INTER)))
	{
		TIMSK |= Copy_u8InterruptMood;
		Local_enuErrorState= ES_OK;

	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;
	return Local_enuErrorState;
}

ES_t TIMER2_enuDisableInterrupt(u8 Copy_u8InterruptMood)
{
	ES_t Local_enuErrorState=ES_NOK;
	if( !(Copy_u8InterruptMood & ~(OVERFLOW_INTER|COMPMATCH_INTER)))
	{
		TIMSK &= ~Copy_u8InterruptMood;
		Local_enuErrorState= ES_OK;

	}

	return Local_enuErrorState;
}

ES_t TIMER2_enuCallBackFun(u8 Copy_u8InterruptMood,void (*Copy_pfunAPPFun)(void *),void* Copy_pvidISRPara)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(!(Copy_u8InterruptMood & ~(OVERFLOW_INTER|COMPMATCH_INTER))&& Copy_u8InterruptMood!=(OVERFLOW_INTER|COMPMATCH_INTER))
	{
		if(NULL!=Copy_pfunAPPFun)
		{
			TIMER2_ApfunISRfun[(COMPMATCH_INTER==Copy_u8InterruptMood)?0:1] = Copy_pfunAPPFun;
			TIMER2_ApvidISRParameter[(COMPMATCH_INTER==Copy_u8InterruptMood)?0:1] = Copy_pvidISRPara;
			Local_enuErrorState= ES_OK;
		}
		//Local_enuErrorState= ES_OK;
	}

	return Local_enuErrorState;
}

void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	if(NULL!=TIMER2_ApfunISRfun[0])
		TIMER2_ApfunISRfun[0](TIMER2_ApvidISRParameter[0]);
}

void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	if(NULL!=TIMER2_ApfunISRfun[1])
			TIMER2_ApfunISRfun[1](TIMER2_ApvidISRParameter[1]);
}
