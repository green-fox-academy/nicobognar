/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN; /* GPIOI clock enable */

	//
	//GPIOI->MODER |= (GPIO_MODER_MODER1_0);   /* configure PI1 in output mode */
	//GPIOI->OTYPER &= ~(GPIO_OTYPER_OT_1);    /* ensure push pull mode selected default */
	//GPIOI->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1); /* ensure maximum speed setting (even though it is unnecessary) */
	//GPIOI->PUPDR &= ~(GPIO_PUPDR_PUPDR1);   /* ensure all pull up pull down resistors are disabled */

	// Init user button (I 11)
	GPIOI->MODER |= 0b0000100000000000; /* configure PI11 in input mode */
}
void init_pins_for_led() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOF clock enable */

	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

	GPIOF->MODER |= (GPIO_MODER_MODER7_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);

	GPIOF->MODER |= (GPIO_MODER_MODER6_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);
}

int main(void) {
	HAL_Init();
	init_pins();
	init_pins_for_led();

	while (1) {
		uint32_t base_led = (1 << 6);
		for (int i = 0; i < 5; ++i) {
			GPIOF->BSRR = base_led;
			HAL_Delay(100);
			GPIOF->BSRR = base_led << 16;
			base_led = base_led << 1;
		}
	}
}
