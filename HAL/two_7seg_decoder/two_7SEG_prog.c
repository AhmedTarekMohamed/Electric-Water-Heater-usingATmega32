/*
 * 2_7SEG_prog.c
 *
 *  Created on: Aug 10, 2022
 *      Author: abano
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"

#include "two_7SEG_priv.h"
#include "two_7SEG_config.h"
ES_t S7SEG2_enuInit(void)
{
	ES_t Local_enuErrorState= ES_NOK;

	Group_dir = DIO_u8GROUPOUTPUT;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}

ES_t S7SEG2_enuSendInteger(u8 Copy_u8Integer)
{
	ES_t Local_enuErrorState= ES_NOK;
	if(Copy_u8Integer<=99)
	{
		Group = (Copy_u8Integer % 10)|(((Copy_u8Integer/10)%10)<<4);
		Local_enuErrorState=ES_OK;

	}

	return Local_enuErrorState;

}


