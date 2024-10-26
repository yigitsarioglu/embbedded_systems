/**
 ******************************************************************************
 * @file           : main.c
 * @author         : yigitsarioglu
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


// Countdown sevensegment (7-segment) Display
/*
 * 1 sn aralıklarla artarak yanacak
 * Anot bir seven-segment display çalışması
 * pb0 -pb7 output pins
 * STM32L552xE Device from STM32L5 series , ARM CORTEX microcontroller
 */


#include <stdint.h>


// Output 7-segment
# define RCC_AHB2ENR  *((volatile uint32_t *)   0x4002104C)
#define GPIOB_MODER *((volatile uint32_t *) 0x42020400)
#define GPIOB_ODR *((volatile uint32_t *) 0x42020414)

// INPUT REG

# define GPIOC_MODER  *((volatile uint32_t *) 0x42020800)
# define GPIOC_IDR   *((volatile uint32_t *)   0x42020810)



void init_Display(){
	 // Configure PB0 to PB7 as general-purpose output
	 RCC_AHB2ENR |= 1 << 1;  // port B clock open
	 GPIOB_MODER &= ~(0xFFFF); // Clear bits for pins 0-7
	 GPIOB_MODER |= 0b0101010101010101;    // Set bits to '01' for pins 0-7  ( 01010101)
}




void write_to_7s(uint8_t number)
{
static const uint8_t seven_segment[10]={0x3FU,0x06U,0x5BU,0x4FU,0x66U,0x6DU,0x7DU,0x07U,0x7FU,0x6FU};
static const uint8_t seven_segment_anode[10] = {
    0xC0U, // 0
    0xF9U, // 1
    0xA4U, // 2
    0xB0U, // 3
    0x99U, // 4
    0x92U, // 5
    0x82U, // 6
    0xF8U, // 7
    0x80U, // 8
    0x98U  // 9
};

	// For cathode 7-segment
	//GPIOB_ODR &= ~(0x7FU); //clear the 7S
	//GPIOB_ODR |= seven_segment[number] ; //write val to the 7S

	// For anot 7-segment
	GPIOB_ODR &= ~(0xFFU); // Clear the pin interface of 7S
	GPIOB_ODR |= ~ seven_segment[number] ;



}



void wait(){
	for (volatile int i = 0; i < 800000; i++) {}
}

int main(void)
{

   init_Switch();
   init_Display();
   int number=0;
   while (1){
	  
		write_to_7s(number);
		
		wait();
		number = number + 1 ;
		if (number==10){
			number=0;
	 	}
	   
   }
   return 0; // Added for completeness
}