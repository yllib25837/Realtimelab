#include "stm32f4xx.h"
int main(void){
uint32_t ii;

// Initialize GPIO Port for LEDs
RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enable GPIOD clock
GPIOD->MODER |= GPIO_MODER_MODER13_0; // GPIOD pin 13 output
GPIOD->MODER |= GPIO_MODER_MODER12_0; // GPIOD pin 12 output
	
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock

for(;;){

 if(((GPIOA->IDR)&0x0001) == 0x0001){
			GPIOD->BSRR = 1<<12; // Turn on the green LED
	    for(ii=0;ii<26000000;ii++){} //FOR loop to implement a 1 second
			GPIOD->BSRR = 1<<(13+16); // Turn off the green LED
		}
	
	else{
			GPIOD->BSRR = 1<<(12+16); // Turn off the green LED
		}
	
 }
} 