/*
 * EXTI_config.c
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"


#include "EXTI_config.h"
#include "EXTI_priv.h"

u8 EXTI_u8EXTINum	=  EXTI_NUM;

EXTI_t EXTI_AstrEXTIConfig [ EXTI_NUM ]=
{
		{INT0 , ENABLED , FALLING},
		{INT1 , ENABLED , FALLING},
		{INT2 , ENABLED , RISING}
};

