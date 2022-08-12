/*
 * ADC_priv.h
 *
 *  Created on: Jun 21, 2022
 *      Author: abano
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define AVCC_REF			1
#define AREF_REF			0
#define	INTERNAL_REF		3

#define PRES_2				1
#define PRES_4				2
#define PRES_8				3
#define PRES_16				4
#define PRES_32				5
#define PRES_64				6
#define PRES_128			7

#define ADC_INTERUPT		1
#define ADC_POLLING			0

#define SINGLE				99
#define FREE_RUN			0
#define	ANA_COMPARA			1
#define EXTI_0				2
#define COM_MATCH_T0		3
#define OVERFLOW_T0			4
#define COM_MATCH_B			5
#define OVERFLOW_T1			6
#define CAPTUREEVENT_T1		7

#define LEFT_ADJ		1
#define	RIGHT_ADJ		0

#define SFIOR 			*((volatile u8 *)0X50)
#define ADMUX			*((volatile u8 *)0X27)
#define ADCSRA			*((volatile u8 *)0X26)
#define ADCH			*((volatile u8 *)0X25)
#define ADCL			*((volatile u8 *)0X24)


#endif /* MCAL_ADC_ADC_PRIV_H_ */
