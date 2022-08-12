/*
 * EXTI_config.h
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

// don't exceed   [ 3 ]
#define EXTI_NUM		3

typedef struct
{
	u8 intPin;
	u8 IntMode;
	u8 senseLvl;
}EXTI_t;

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
