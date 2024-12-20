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

// LPUART INTEGRATION WİTH HSI16 CLOCK SET
// BAUD RATE :1152OO

// PG7 LPUART1_TX  AF8
// PG8 LPUART1_RX   AF8

void initGPIO(){

	// RCC_AHB2ENR  |=  1 << 0;  // gpoa port enable
	RCC_AHB2ENR  |=  1 << 6;  // gpoa port enable

	GPIOG->MODER &= ~(3 << 2*7);  // PG7 alternatif fonksiyon moduna alınır pg7: LPUART1_TX
	GPIOG->MODER |=  2 << (2*7) ;  //pg7 port alternate function mode

	GPIOG->MODER &= ~(3 << 2*8);  // PG8 alternatif fonksiyon moduna alınır pg8: LPUART1_RX
	GPIOG->MODER |=  2 << (2*8) ;  //pg8 port alternate function mode

	GPIOG->AFRL |= 8 << (4*7) ;  // PG7 Alternate mode AF8
	GPIOG->AFRH |= 8 << (4*0) ;  // PG7 Alternate mode AF8
}




void initLPUART(){

	RCC_APB1ENR1 |= 1<<28; //Enable Clock for Power Interface
	PWR_CR1 |= 1<< 14; //Change the regulator mode to Low-power mode
	PWR_CR2 |= 1<< 9; //Make VDDIO2 valid

	//lpuart ve gpıo clockların aktif etmemiz lazım

   // RCC_BDCR |= (1 << 7);  // LSE Clock Enable
   // while (!(RCC_BDCR & (1 << 11)));  // LSE Ready Flag

	RCC_CR |= 1<<8;
	while  ( !( RCC_CR & (1<<10) ) );


	RCC_APB1ENR2 |=  1 ;   // lpuart clock enable edildi
	RCC_CCIPR1  |=   2 << 10 ;  // hsi clock selected 10 olunca


	LPUART->CR1 &= ~ ( 1 <<28) ;   //  M[1:0] = ‘00’: 1 Start bit, 8 Data bits, n Stop bit
	LPUART->CR1 &= ~(1 << 12);  // M0: Word length **

	 // Baud rate hesaplama (HSI16 = 16 MHz, Baud Rate = 115200)
	LPUART->BRR = 0x8AE3;  // HSI16 clock  - 8AE3

	LPUART->CR2   &= ~ ( 3 <<12) ;   //STOP[1:0]: STOP bits 00: 1 stop bit




	LPUART->CR1 &= ~(1 << 10); // Parity control disabled **


	LPUART->CR1  |=  1<<2 ;  //  Receiver enable
	LPUART->CR1  |=  1<<3 ;  //  TE: Transmitter enable

	LPUART->CR1  |=  1 ;   // UE: LPUART enable

	// NVIC->ISER[2] |=   1 << 2 ;   // lpuart ırq handler

}

void charSender(uint8_t c){

	//sending data
	LPUART->TDR =  c ; // lpuart TDR registerine yazılır
	while ( ! (LPUART->ISR & (1<<6) ) );
}



void sendString(char *str){

	while(*str){
		charSender(*str++);
	}
}

uint8_t recvChar(void){
	uint8_t temp;

	while (! (LPUART->ISR & (1<<5) )   );   // RXNE 1: Received data is ready to be read
	temp = LPUART->RDR;

	return temp;
}

// 66 74 Settable LPUART1 LPUART1 global interrupt
// 66/32 = 2   ISER2 , 2.bit
void LPUART1_IRQHandler(void){


}

int main(void)
{

	initGPIO();
	initLPUART();

   while(1){


	   charSender('d');
	   for (volatile int i = 0; i < 200000; i++) {} // Adjust the loop count for your desired delay


   }
}

