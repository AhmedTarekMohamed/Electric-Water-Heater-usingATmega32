/*
 * TIMER2_priv.h
 *
 *  Created on: Jul 30, 2022
 *      Author: abano
 */

#ifndef MCAL_TIMER2_TIMER2_PRIV_H_
#define MCAL_TIMER2_TIMER2_PRIV_H_


#define TCCR2					*((volatile u8*)0X45)
#define TCNT2					*((volatile u8*)0X44)
#define OCR2					*((volatile u8*)0X43)
#define ASSR					*((volatile u8*)0X42)
#define TIMSK					*((volatile u8*)0X59)
#define TIFR					*((volatile u8*)0X58)
//wave generation moods

#define TIM2_NormalWAVEmood			0X00
#define TIM2_PHASEcorrectWAVmood	0X40
#define TIM2_CTCMood				0X08
#define TIM2_FastPWM				0X48

//OC2 output mood
#define TIM2_OC2NC					0X00
#define TIM2_ToggleOC2				0X10
#define TIM2_CleraONCOMMATCH		0X20
#define TIM2_SETONCOMMATCH			0X30

//prescaler
#define TIM2_PRE1					0X01
#define TIM2_PRE8					0X02
#define TIM2_PRE32					0X03
#define TIM2_PRE64					0X04
#define TIM2_PRE128					0X05
#define TIM2_PRE256					0X06
#define TIM2_PRE1024				0X07

//clock source
#define TIM2_EXITERNALclock			0X08
#define TIM2_CPUclock				0X00
//interrupt moods
#define COMPMATCH_INTER				0X80
#define OVERFLOW_INTER				0X40
#define NON							0X00






#endif /* MCAL_TIMER2_TIMER2_PRIV_H_ */
