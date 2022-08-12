/*
 * EXTI_priv.h
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define INT0			0
#define INT1			1
#define INT2			2


#define LOW_LEVEL		65
#define ANY_LOGIC		23
#define FALLING			31
#define RISING			98

#define ENABLED			47
#define POLLING			92


#define MCUCR			*((volatile u8*)0x55)
#define MCUCSR			*((volatile u8*)0x54)
#define GICR			*((volatile u8*)0x5B)
#define GIFR			*((volatile u8*)0x5A)


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
