/*
 * EXTI_int.h
 *
 *  Created on: Jun 18, 2022
 *      Author: abano
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit(void);

ES_t EXTI_enuSetSenseLevel(EXTI_t * Copy_pstrEXTIInfo , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableInterrupt(EXTI_t * Copy_pstrEXTIInfo);

ES_t EXTI_enuDisableInterrupt(EXTI_t * Copy_pstrEXTIInfo);

ES_t EXTI_enuCallBack(EXTI_t * Copy_pstrEXTIInfo , void (*Copy_pfunAppFun)(void*) , void * Copy_pvidParameter);

#define LOW_LEVEL		65
#define ANY_LOGIC		23
#define FALLING			31
#define RISING			98

#define ENABLED			47
#define POLLING			92


#endif /* MCAL_EXTI_EXTI_INT_H_ */
