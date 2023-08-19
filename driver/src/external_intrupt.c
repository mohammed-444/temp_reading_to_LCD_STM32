#include "external_intrupt.h"
#include "gpio.h"

char num=0;
void external_interrupt_init(char port, char pin ){
//  enable external interrupt (SYSCFG)
	RCC->APB2ENR|=(1u<<14);
// clear every bits
	for (int var = 0; var < 4; ++var) {
			SYSCFG->EXTICR[pin] &=~(1u<<var);
			}
// enable the pin port we want to use
//	note in all port except H
	for (int var = 0; var < 4; ++var) {
		SYSCFG->EXTICR[pin] |=(port<<var);
		}
// enable the pin interrupt we want to use
	EXTI->IMR |=(1u<<pin);
// interrupts to be configured on GPIO falling edge
	EXTI->FTSR |=(1u<<pin);
//  enable the interrupt model for the pin interrupt we want to use
// note work only from pin 0-4
	NVIC->ISER[0]|=(1u<<(6+pin));
}

void display_7seg(){
	for (int var = 0; var < 4; ++var) {
			GPIO_Write(GPIOB,var,(num & (1<<var)));
			}
}

void EXTI0_IRQHandler(void){
	if(num<9){num++;}
}
void EXTI1_IRQHandler(void){
	if(num>0){num--;}
}

