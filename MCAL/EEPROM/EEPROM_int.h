/*
 * EEPROM_int.h
 *
 *  Created on: Aug 5, 2022
 *      Author: Alaa Ibrahim
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_

ES_t EEPROM_write(u16 copy_u16address,u8 copy_u8data);
ES_t EEPROM_read(u16 copy_u16address,u8 *copy_u8data);
ES_t EEPROM_ADDString(u16 * Copy_u16address,u8 *copy_u8data);
ES_t EEPROM_ReadString(u16 * Copy_u16address,u8 *copy_u8data);

ES_t EEPROM_intEnable(void);
ES_t EEPROM_intDisable(void);
//ES_t EEPROM_intSetCallback(void (*localFptr)(void));
#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
