/*
 * Temp_sensor_prog.c
 *
 *  Created on: Jul 27, 2022
 *      Author: Ahmed Tarek
 */
#include "../../LIBRARY/errorState.h"
#include "../../Library/stdTypes.h"

#include "../../MCAL/ADC/ADC_int.h"

#include "Temp_sensor_config.h"
#include "Temp_sensor_priv.h"

ES_t TEMP_voidInit(void)
{
	ES_t Local_ennErrorState=ES_NOK;
	ADC_enuInit();

	Local_ennErrorState=ES_OK;


	return Local_ennErrorState;
}


ES_t TEMP_u16GetValue(u16*Copy_pu16tempvalue)
{
	ES_t Local_ennErrorState=ES_NOK;

	if (NULL!=Copy_pu16tempvalue )
	{
		u16 Local_u16Analogve;

		ADC_enuStartConversion();
		ADC_enuPollingRead(&Local_u16Analogve);
		*Copy_pu16tempvalue=((u64)Local_u16Analogve*150*5)/((u64)1023*1.5);

		Local_ennErrorState=ES_OK;


	}
	else
	{
		Local_ennErrorState=ES_NULL_POINTER;

	}
	return Local_ennErrorState;
}

