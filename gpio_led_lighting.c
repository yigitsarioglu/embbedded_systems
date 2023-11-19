// Led Yakıp Sondüren Kod
// Yaklaşık 1 sn aralıklarla led yanıp söndürecek
// PB5 pin output olarak belirlendi..
#include <stdint.h>


#define AHB2ENR *((volatile uint32_t *) 0x4002104C)
#define GPIOB_MODER *((volatile uint32_t *) 0x42020400)
#define GPIOB_ODR *((volatile uint32_t *) 0x42020414)

init_LED1() //assuming reset conditions
{
    AHB2ENR |= 1 << 1; //clock for GPIOB is enabled
    GPIOB_MODER &= ~(1 << 11); //PB5 is output

}
turn_on_LED1() //assuming reset conditions
{
    GPIOB_ODR |= (1 << 5); //Write 1 to PB5
}

turn_off_LED1() //assuming reset conditions
{
	GPIOB_ODR &= ~(1 << 5); //Write 1 to PB5

}


main()
{
    init_LED1();
    while(1)
    {
    	turn_on_LED1(); //Turn on LED1

        for (volatile int i = 0; i < 200000; i++) {} // Adjust the loop count for your desired delay

        turn_off_LED1(); // turn off

        //Add another delay
        for (volatile int i = 0; i < 200000; i++) {} // Adjust the loop count for your desired delay
    }

}
