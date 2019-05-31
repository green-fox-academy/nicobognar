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

void init_button_pin() {
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef gpio_button_config;
	gpio_button_config.Pin = GPIO_PIN_4;
	gpio_button_config.Mode = GPIO_MODE_IT_RISING;
	gpio_button_config.Pull = GPIO_NOPULL;
	gpio_button_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &gpio_button_config);

	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	HAL_NVIC_SetPriority(EXTI4_IRQn, 16, 0);
}
void init_pins_for_led() {
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_led_config;
	gpio_led_config.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6;
	gpio_led_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_led_config.Pull = GPIO_NOPULL;
	gpio_led_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_led_config);
}

int main(void) {
	HAL_Init();
	init_button_pin();
	init_pins_for_led();
	//uint16_t pins[5] = {GPIO_PIN_10,GPIO_PIN_9,GPIO_PIN_8,GPIO_PIN_7,GPIO_PIN_6};
	while (1) {
		/*for (int i = 0; i < 5; ++i){
			HAL_GPIO_TogglePin(GPIOF, pins[i]);
			HAL_Delay(125);
			HAL_GPIO_TogglePin(GPIOF, pins[i]);
		}*/
	}
}
void EXTI4_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8);
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_6);
}

