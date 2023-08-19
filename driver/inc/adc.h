/*
 * adc.h
 *
 *  Created on: May 28, 2022
 *      Author: hp
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#define POLLING 0


#include "stm32f4xx.h"
#include "std_types.h"
#include "gpio.h"

extern unsigned short int data;


typedef enum {
	bit_12,	bit_10,	bit_8,bit_6
}resolution;

typedef enum {
	single,continuous

} Conversion_mode;


typedef struct{
	uint8 ref_volt;
	resolution res;
	Conversion_mode mode;
}ADCConfigType;

/*configuration parameters needed to initialize the STM ADC.*/
void ADC_Init(ADCConfigType* ConfigParamPtr);

/*The function is used to start a software conversion in the single conversion mode or start the
first conversion in the continuous mode*/
void ADC_StartConv(unsigned char ChannelNum);

/*The function shall be enabled only when the configuration macro USE_POLLING is set to 1
and is used by the client to check if conversion is done (1) or not (0)*/
void ADC_GetConversionState(unsigned char* ConversionStatePtr);

/*The function shall be used by the client to read the ADC value. The function shall return 0 when
there is a valid ADC value and the DataPtr is Dereferenced.. The function shall return 1 when
there is no valid ADC value and the DataPtr is not dereferenced.*/
unsigned char ADC_ReadData(unsigned short int* DataPtr);



#endif /* INC_ADC_H_ */
