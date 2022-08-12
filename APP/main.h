/*
 * main.h
 *
 *  Created on: Aug 12, 2022
 *      Author: Ahmed Tarek
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#define TepretureADD	0

#define UP_Button	DIO_u8GROUP_D,DIO_u8PIN2
#define DOWN_Button	DIO_u8GROUP_D,DIO_u8PIN3
#define ONOFF_Button	DIO_u8GROUP_B,DIO_u8PIN2
#define Heater_Pin		DIO_u8GROUP_A,DIO_u8PIN1
#define HeaterLed_Pin	DIO_u8GROUP_B,DIO_u8PIN1
#define Coolant_Pin		DIO_u8GROUP_B,DIO_u8PIN0
#define CoolantLed_Pin	DIO_u8GROUP_B,DIO_u8PIN3

#define	TempSetTime			5000		//ms
#define TempReadperiod		100

#define TOP					256

#define PRESCALLER			1024

#define OVFSTempSetCounts	((u64)TempSetTime * (F_CPU/1000)/((u64)PRESCALLER*TOP))
#define TempReadCounts		((u64)TempReadperiod * (F_CPU/1000)/((u64)PRESCALLER*TOP))
#define One_secound			((u64)1000 * (F_CPU/1000)/((u64)PRESCALLER*TOP))

#endif /* APP_MAIN_H_ */
