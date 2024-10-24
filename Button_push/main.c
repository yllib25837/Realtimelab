#include "stm32f4xx.h"
int main(void){
// Initialize GPIO Port for LEDs
RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable GPIOD clock
GPIOD->MODER |= GPIO_MODER_MODER12_0; // GPIOD pin 12 output - green LED

RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
//GPIOA->MODER |= GPIO_MODER_MODER0; // GPIOA pin 0 input mode - push button
	
	
	for(;;){
		
		if(((GPIOA->IDR)&0x0001) == 0x0001){
			GPIOD->BSRR = 1<<12; // Turn on the green LED
		}
		
		else{
			GPIOD->BSRR = 1<<(12+16); // Turn off the green LED
		}
	}





}