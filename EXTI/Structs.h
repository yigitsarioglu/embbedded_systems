

#define RCC_BASE 0X40021000
#define RCC_AHB2ENR *((volatile uint32_t *) 0x4002104C)
#define RCC_APB2ENR *((volatile uint32_t *) 0X40021060 )

#define RCC_APB1ENR1 *( (volatile uint32_t *) 0X40021058)
#define RCC_APB1ENR2  (*((volatile uint32_t *)(0x4002105C)))
#define RCC_CCIPR1 *((volatile uint32_t *) 0x40021088)

#define RCC_BDCR *((volatile uint32_t *) 0x40021090)

#define RCC_CR *((volatile uint32_t *)  0x40021000 )


typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
	uint32_t reserved;
	volatile uint32_t SECCFGR;
} GPIO_Type;
#define GPIO_BASE 0x42020000
#define GPIOA ((GPIO_Type *) 0x42020000)
#define GPIOB ((GPIO_Type *) 0x42020400)
#define GPIOC ((GPIO_Type *) 0x42020800)
#define GPIOD ((GPIO_Type *) 0x42020C00)
#define GPIOG ((GPIO_Type *)   0x42021800)


// TIM15 structure definition
typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	uint32_t reserved1;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	uint32_t reserved2;
	uint32_t reserved3;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR1;
	uint32_t reserved4[3];
	volatile uint32_t OR2;

}TIM15_Type;
#define TIM15 ((TIM15_Type *) 0x40014000)

// page 90 -memory organization




// TIM6 structure definition
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
		uint32_t reserved;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
		uint32_t reserved1;
		uint32_t reserved2;
		uint32_t reserved3;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
}TIM6_Type ;
#define TIM6 ((TIM6_Type *)  0x40001000  )
// page 90 -memory organization


typedef struct {
	volatile uint32_t ISER[16];	// Interrupt Set Enable Registers
	uint32_t reserved0[16];
	volatile uint32_t ICER[16];	// Interrupt Clear Enable Registers
	uint32_t reserved1[16];
	volatile uint32_t ISPR[16];	// Interrupt Set Pending Registers
	uint32_t reserved2[16];
	volatile uint32_t ICPR[16];	// Interrupt Clear Pending Registers
	uint32_t reserved3[16];
	volatile uint32_t IABR[16];	// Interrupt Active Bit Registers
	uint32_t reserved4[16];
	volatile uint32_t ITNS[16];	// Interrupt Target Non-secure Registers
	uint32_t reserved5[16];
	volatile uint32_t IPR[119];	// Interrupt Priority Registers
	//uint32_t reserved5[584];
	//volatile uint32_t STIR;		// Software Trigger Interrupt Register
}NVIC_Type;

#define NVIC ((NVIC_Type *) (0xE000E100UL))


// Struct for LPUART
typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t BRR;
	uint32_t reserved1;
	uint32_t reserved2;
	volatile uint32_t RQR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t RDR;
	volatile uint32_t TDR;
	volatile uint32_t PRESC;
}LPUART_Type;

#define LPUART ((LPUART_Type *) (0x40008000))


// pwr adress : --- 0x4000 7000  (sayfa 93)
#define PWR_BASE_ADDR 0x40007000
#define PWR_CR1_BASE 0x40007000
#define PWR_CR2_BASE 0x40007004

#define PWR_CR1 *((volatile uint32_t *) PWR_CR1_BASE)
#define PWR_CR2 *((volatile uint32_t *) PWR_CR2_BASE)


// Struct for USART
typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t BRR;
	volatile uint32_t GTPR;
	volatile uint32_t RTOR;
	volatile uint32_t RQR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t RDR;
	volatile uint32_t TDR;
	volatile uint32_t PRESC;
}USART_Type;

#define USART3 ((USART_Type *) (0x40004800))  // USART adresi :  0x4000 4800
#define ISER1 *((volatile uint32_t*) (0xE000E104))

#define ISER0 *((volatile uint32_t*) (0xE000E100))
