#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"
const int no_rows = 4;
const int no_cols = 3;
char rows[4]={3,4,5,6};
char cols[3]={0,1,2};

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};

char currentvalue;


void KeyPad_INIT(void)
{
	for (int i = 0; i < no_cols; ++i) {
		GPIO_Init (GPIOA,cols[i],1,0);
	}

	for (int j = 0; j < no_rows; ++j) {
		GPIO_Init (GPIOA,rows[j],0,0);
		}

	for (int j = 0; j < no_rows; ++j) {
		pull_up(GPIOA,rows[j]);
			}

}

void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
while(1){
	for (int i = 0; i < no_cols; ++i) {

		for (int var = 0; var < no_cols; ++var) {
			GPIO_Write(GPIOA,cols[var],1);
			}

		GPIO_Write(GPIOA,cols[i],0);

		for (int j = 0; j < no_rows; ++j) {

			if(!GPIO_Read(GPIOA,rows[j])){

				for (int var = 0; var < 50000; ++var);

				if(!GPIO_Read(GPIOA,rows[j])){

				while(!GPIO_Read(GPIOA,rows[j]));

				currentvalue=lookupTable[j][i];

				KeypadCallouts_KeyPressNotificaton();

				break;

				}
			}

		}
	}
 }
}



char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	for (int var = 0; var < 4; ++var) {
		GPIO_Init (GPIOB,var,1,1);
	}

	if(0<=currentvalue && currentvalue<=9 ){

		for (int var = 0; var < 4; ++var) {
			GPIO_Write(GPIOB,var,(currentvalue & (1<<var)));
		}
//		GPIO_Write(GPIOB,0,1);
//		GPIO_Write(GPIOB,1,1);
//		GPIO_Write(GPIOB,2,1);
	}
}



