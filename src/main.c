/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "lm35_sensor.h"
#include "lcd.h"

int main(void)
{

	unsigned char temp;
	unsigned char state;

	ADCConfigType config={5,bit_12,continuous};
//w
	LCD_init();

#if (POLLING==1)

	ADC_Init(&config);
	ADC_StartConv(1);
#else
	config.mode=single;
	ADC_Init(&config);

#endif
	LCD_moveCursor(0,0);
	LCD_displayString("Temp =    C");


for(;;){


#if (POLLING==1)

	do{
		ADC_GetConversionState(& state);
		}while(state==0);



	ADC_ReadData(&data);

#else

	ADC_StartConv(1);

#endif
//z
	temp=LM35_getTemperature(data,&config);
	LCD_moveCursor(0,7);

			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
	    }
	}







