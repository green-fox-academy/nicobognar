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
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>
#include <stdio.h>


static void SystemClock_Config(void);
static void Error_Handler(void);

void init_user_button()
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
}

void init_LCD() {
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(0xFF2ADA25);
	BSP_LCD_SetBackColor(0xFF2ADA25);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
}

void init_touchy_touchy() {
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	__HAL_RCC_RNG_CLK_ENABLE();

	RNG_HandleTypeDef rng;
	rng.Instance = RNG;

	HAL_RNG_Init(&rng);

	init_LCD();
	init_touchy_touchy();

	uint8_t buffer[40];
	TS_StateTypeDef ts_state;
	uint32_t colors_of_the_wind[21] =
	{
			LCD_COLOR_RED, LCD_COLOR_YELLOW, LCD_COLOR_WHITE, LCD_COLOR_MAGENTA, LCD_COLOR_BLUE,
			LCD_COLOR_LIGHTGREEN, LCD_COLOR_LIGHTRED, LCD_COLOR_LIGHTBLUE, LCD_COLOR_LIGHTMAGENTA, LCD_COLOR_CYAN
	};

	while (1) {
		sprintf((char *)buffer, "%s", "Press the screen to start the game!");
		BSP_LCD_DisplayStringAt(BSP_LCD_GetXSize(), (BSP_LCD_GetYSize() / 2), buffer, CENTER_MODE);
		BSP_TS_GetState(&ts_state);
		if (ts_state.touchDetected){
			BSP_LCD_Clear(LCD_COLOR_LIGHTYELLOW);
			while (1){
				uint32_t rand = (HAL_RNG_GetRandomNumber(&rng) % 10 + 1);
				HAL_Delay(rand * 1000);
				BSP_LCD_Clear((colors_of_the_wind[rand])); // biztonsagi torles
				BSP_LCD_SetTextColor(colors_of_the_wind[rand]);
				uint32_t Random_position_x = HAL_RNG_GetRandomNumber(&rng) % BSP_LCD_GetXSize();
				uint32_t Random_position_y = HAL_RNG_GetRandomNumber(&rng) % BSP_LCD_GetYSize();
				BSP_LCD_DrawRect(Random_position_x, Random_position_y, 40, 40);
				BSP_LCD_FillRect(Random_position_x, Random_position_y, 40, 40);
				//BSP_LCD_DrawCircle(Random_position_x, Random_position_y, 20);
				//BSP_LCD_FillCircle(Random_position_x, Random_position_y, 20);
				//BSP_LCD_Clear((colors_of_the_wind[rand]));

			}
		}
	}
}
void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}

static void Error_Handler(void)
{
}


static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
