/*
 * 2_7SEG_priv.h
 *
 *  Created on: Aug 10, 2022
 *      Author: abano
 */

#ifndef HAL_TWO_7SEG_DECODER_TWO_7SEG_PRIV_H_
#define HAL_TWO_7SEG_DECODER_TWO_7SEG_PRIV_H_

#define PORTA 		*((volatile u8*)0x3B)
#define DDRA 		*((volatile u8*)0x3A)
#define PINA 		*((volatile u8*)0x39)

#define PORTB 		*((volatile u8*)0X56)
#define DDRB 		*((volatile u8*)0x37)
#define PINB 		*((volatile u8*)0x36)

#define PORTC 		*((volatile u8*)0x35)
#define DDRC 		*((volatile u8*)0x34)
#define PINC 		*((volatile u8*)0x33)

#define PORTD 		*((volatile u8*)0x32)
#define DDRD 		*((volatile u8*)0x31)
#define PIND 		*((volatile u8*)0x30)

#define GROUPA_Dir	DDRA
#define GROUPB_Dir	DDRB
#define GROUPC_Dir	DDRC
#define GROUPD_Dir	DDRD

#define GROUPA		PORTA
#define GROUPB		PORTB
#define GROUPC		PORTC
#define GROUPD		PORTD

#define DIO_u8GROUPOUTPUT		255
#endif /* HAL_TWO_7SEG_DECODER_TWO_7SEG_PRIV_H_ */
