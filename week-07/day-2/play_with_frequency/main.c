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

int main(void) {
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	while (1) {
		for (int i = 1; i < 9; i += i) {
			for (int k = 0; k < 3; k++) {
				BSP_LED_On(LED1);
				HAL_Delay(i * 125);
				BSP_LED_Off(LED1);
				HAL_Delay(i * 125);
			}
		}
		for (int j = 8; j > 1; j = j / 2) {
			for (int l = 0; l < 3; l++) {
				BSP_LED_On(LED1);
				HAL_Delay(j * 125);
				BSP_LED_Off(LED1);
				HAL_Delay(j * 125);
			}
		}
	}
}
