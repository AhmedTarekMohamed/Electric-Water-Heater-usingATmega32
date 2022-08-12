/*
 * EEPROM_prog.c
 *
 *  Created on: Aug 5, 2022
 *      Author: Alaa Ibrahim
 */
#include "../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"


#include"EEPROM_priv.h"

ES_t EEPROM_write(u16 copy_u16address,u8 copy_u8data){
	ES_t local_enuErrorState=ES_NOK;

	while (1 == ((EECR>>1)&1));
	EEARH= (u8)(copy_u16address>>8);
	EEARL= (u8) copy_u16address;
	EEDR = copy_u8data;
	EECR|= (1<<2);
	asm("SBI 0x1C,2");
	asm("SBI 0x1C,1");

	return local_enuErrorState;
}
ES_t EEPROM_read(u16 copy_u16address,u8 *copy_u8data){
	ES_t local_enuErrorState=ES_NOK;

	while (1 == ((EECR>>1)&1));
	EEARH= (u8)(copy_u16address>>8);
	EEARL= (u8) copy_u16address;
	EECR|= (1<<0);
	*copy_u8data = EEDR;

	return local_enuErrorState;
}
ES_t EEPROM_ADDString(u16 Copy_u16address,u8 *copy_u8data)
{
	ES_t local_enuErrorState=ES_NOK;
	u8 i = 0;
	do
	{
		while (1 == ((EECR>>1)&1));
		EEARH= (u8)(Copy_u16address+i>>8);
		EEARL= (u8) Copy_u16address+i;
		EEDR = copy_u8data[i];
		EECR|= (1<<2);

		asm("SBI 0x1C,2");
		asm("SBI 0x1C,1");
	}while(copy_u8data[i++]);
		return local_enuErrorState;
}

ES_t EEPROM_ReadString(u16 Copy_u16address,u8 *copy_u8data)
{
	u8 i = 0;
		do
		{
			while (1 == ((EECR>>1)&1));
			EEARH= (u8)(Copy_u16address+i>>8);
			EEARL= (u8) Copy_u16address+i;
			EECR|= (1<<0);
			copy_u8data[i] = EEDR;
		}while(copy_u8data[i++]);
		return ES_OK;
}



ES_t EEPROM_intEnable(void){
	ES_t local_enuErrorState=ES_NOK;

	EECR|= (1<<3);

	return local_enuErrorState;
}
ES_t EEPROM_intDisable(void){
	ES_t local_enuErrorState=ES_NOK;
	EECR &=~(1<<3);
	return local_enuErrorState;
}
