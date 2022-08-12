/*
 * GIE_prog.c
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"

#include "GIE_int.h"


ES_t GIE_enuInit(void)
{
	//SREG |=(1<<7); //in this case you must create the priv.h and add register address
	asm("SEI");
	return ES_OK;
}

ES_t GIE_enuEnable(void)
{
	//SREG |=(1<<7);
	asm("SEI");
	return ES_OK;
}

ES_t GIE_enuDisable(void)
{
	//SREG &= ~ (1<<7);
	asm("CLI");
	return ES_OK;
}
