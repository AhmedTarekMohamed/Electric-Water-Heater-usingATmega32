/*
 * Temp_sensor_intr.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Ahmed Tarek
 */

#ifndef HAL_TEMP_SENSOR_TEMP_SENSOR_INTR_H_
#define HAL_TEMP_SENSOR_TEMP_SENSOR_INTR_H_

ES_t TEMP_voidInit(void);
ES_t TEMP_u16GetValue(u16*Copy_pu16tempvalue);

#endif /* HAL_TEMP_SENSOR_TEMP_SENSOR_INTR_H_ */
