/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */



#include <stdint.h>

#include "structs.h"
#include <string.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



void init_userleds (void){
	RCC_AHB2ENR |= (1<<0) ;
	RCC_AHB2ENR |= (1<<1) ;
	RCC_AHB2ENR |= (1<<2) ;


	GPIOC->MODER &= ~ (1<< 15);  // PC7 output mode açılır
	GPIOA->MODER &= ~ (1<< 19);   // PA9 output mode açılır
	GPIOB->MODER &= ~ (1<< 15);   // PB7 output mode açılır

	GPIOA->MODER &= ~ (3<< 6); // pa3 clear bits
	GPIOA->MODER  |= (1<<6) ;  // pa3 output mode

	GPIOC->MODER &= ~(3 << 2*1);   //  // PC1 input for IR sensor

	 // Pull-up/Pull-down settings
	 //GPIOC->PUPDR &= ~(3 << (2 * 1)); // Clear pull-up/down for PC1
	 //GPIOC->PUPDR |= (1 << (2 * 1));  // Enable pull-up for PC1
}


void turn_on_red(void ){

	GPIOA->ODR  |= (1<<9) ;  // pa9 açılır _red led yanar
}

void turn_off_red(void ){

	GPIOA->ODR   &= ~ (1<<9) ;  // pa9 kapanır _red led söner
}

uint32_t check_IR_Sensor (void){
    // Debug amaçlı GPIOC IDR değerini gözlemlemek
	return (GPIOC->IDR & (1 << 1)) >> 1; // Read PC1 pin status
}

int main(void)
{


	 init_userleds();
	 uint32_t sensor_val; // Sensör değerini gözlemlemek için değişken tanımla

   while(1){


	  sensor_val = check_IR_Sensor(); // Sensörden okunan değeri sakla

	  if (sensor_val == 0) { // Eğer değer sıfırsa obje algılanacak
		  turn_on_red();
		  GPIOA->ODR  |= (1<<3) ; // pa3 open
	  }
	  else {
	     turn_off_red();
	     GPIOA->ODR   &= ~ (1<<3) ;  //pa3 close
	   }

	  for (volatile int i = 0; i < 200000; i++) {} // Adjust the loop count for your desired delay


   }
}


