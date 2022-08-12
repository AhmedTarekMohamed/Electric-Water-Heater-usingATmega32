/*
 * ADC_int.h
 *
 *  Created on: Jun 21, 2022
 *      Author: abano
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

//ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuRead(u16 * Copy_pu16Value);

/*ES_t ADC_enuReadHigh(u8 * Copy_pu8Value);

ES_t ADC_enuSetAutoTrigger(u8 Copy_u8TriggerSource);

ES_t ADC_enuDisableAutoTrigger(void);

ES_t ADC_enuCallBack(void (*Copy_pfunAppFun)(void*),  void * Copy_pvidParameter);*/

ES_t ADC_enuPollingRead(u16 * Copy_pu16ADCValue);
/*
ES_t ADC_enuEnableInterrupt(void);
ES_t ADC_enuDisableInterrupt(void);

ES_t ADC_enuEnable(void);
ES_t ADC_enuDisable(void);
*/



#endif /* MCAL_ADC_ADC_INT_H_ */
