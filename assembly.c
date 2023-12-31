/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define N 5

void init(void)
{
	//no init
}

void update(void)
{
	int32_t x=5,y=7,sumx=0,sumxsq=0,sumy=0,sumxy=0;
	int32_t d,m,c=1;
	for(int i=0; i < N;i++)
	{
		sumx=sumx+x;
		sumy=sumy+y;
		// sumxsq=sumxsq+(x*x);
		//sumxy=sumxy+(x*y);
		   __asm
		   (
				   "MLA %[res2], %[in1], %[in2], %[b] \n\t" // MLA     R10, R2, R1, R5 => R10 = (R2 × R1) + R5
				   "MLA %[res1], %[in1], %[in1], %[a] \n\t" // MLA     R10, R2, R1, R5 => R10 = (R2 × R1) + R5
				   : [res1] "=&r" (sumxsq) , [res2] "=&r" (sumxy)
		 			: [in1] "r" (x), [in2] "r" (y), [a] "r" (sumxsq), [b] "r" (sumxy)
		 			  );
	}

	d=N*sumxsq-sumx*sumx;
	m=(N*sumxy-sumx*sumy)/d;
	c=(sumy*sumxsq-sumx*sumxy)/d;
	x=m;
	y=c;
}

int main(void)
{
    /* Loop forever */
	init();
	for(;;)
	{
		update();
	}

}

