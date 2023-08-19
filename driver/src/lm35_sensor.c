 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

//#include <util/delay.h> /* For the delay functions */
#include "lm35_sensor.h"


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(uint16 g_adcResult,ADCConfigType* ConfigParamPtr)
{
	uint8 temp_value = 0;

	/* Read ADC channel where the temperature sensor is connected */

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
//	_delay_ms(5);
    for(uint16 i=0;i<7000;i++);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)g_adcResult*SENSOR_MAX_TEMPERATURE*(ConfigParamPtr->ref_volt))/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

