/*
 * adc.c
 *
 *  Created on: May 28, 2022
 *      Author: hp
 */

#include "adc.h"

unsigned short int data ;

void ADC_Init(ADCConfigType* ConfigParamPtr){

//-----------------------------------------------------------------------------------------------
	// Enable clock access to ADC1
	RCC->APB2ENR |=(1<<8);
	// Enable the ADC
	ADC1->CR2 |=(1u<<0);
//-----------------------------------------------------------------------------------------------

	//set the number of channels
	//	ADC1->SQR1 |=(1u<<20); // 0000: 1 conversion ----- 0001: 2 conversions

//-----------------------------------------------------------------------------------------------
	// set the order of chanels using SQR register
	// for example channel 1 to be the first
	ADC1->SQR3 |= (1u<<0); // PA1

//-----------------------------------------------------------------------------------------------
	// set the resolution of the adc
	ADC1->CR1=(ADC1->CR1&0xFCFFFFFF)|((ConfigParamPtr->res)<<24);

//-----------------------------------------------------------------------------------------------

//	ADC prescaler 8
//	ADC->CCR|=(1u<<16)|(1u<<17);

//-----------------------------------------------------------------------------------------------

// EOCS
//	ADC1->CR2|= (1<<10);

//-----------------------------------------------------------------------------------------------

#if (POLLING==0)
ADC1->CR2 &=~((ConfigParamPtr->mode)<<1);//set cont bit
//-----------------------------------------------------------------------------------------------
NVIC->ISER[0] |= (1u <<18 );// enable global interrupt
ADC1->CR1|=(1<<5); // enable adc interrupt
//-----------------------------------------------------------------------------------------------

#else
//-----------------------------------------------------------------------------------------------
ADC1->CR2 |=((ConfigParamPtr->mode)<<1);//set cont bit

ADC1->CR1 &=~(1<<5);// disable adc interrupt
//-----------------------------------------------------------------------------------------------
#endif


}

void ADC_StartConv(unsigned char ChannelNum){
	//set swstart bit to start the adc conversion
	ADC1->CR2 |=(1u<<30) ;

	// set the adc pin to analoge
	GPIO_Init(GPIOA,ChannelNum,3,0);
}


#if (POLLING==1)

void ADC_GetConversionState(unsigned char* ConversionStatePtr){
	*ConversionStatePtr= (ADC1->SR) & (1u<<1); // end of conversion flag EOC
}

#endif


unsigned char ADC_ReadData(unsigned short int* DataPtr){
	// check on end of conversion flag EOC
	if((ADC1->SR) & (1u<<1)) {

	* DataPtr= ADC1->DR;
		return 0;
	}

	else{
		return 1;
	}


}



// interrupt function
void ADC_IRQHandler(void){
	ADC_ReadData(&data);
}




