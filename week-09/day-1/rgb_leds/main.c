#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef timer_handle_red;
TIM_HandleTypeDef timer_handle_green;
TIM_HandleTypeDef timer_handle_blue;

TIM_OC_InitTypeDef pwm_config_red;
TIM_OC_InitTypeDef pwm_config_green;
TIM_OC_InitTypeDef pwm_config_blue;

GPIO_InitTypeDef B15_LED_config;
GPIO_InitTypeDef A8_LED_config;
GPIO_InitTypeDef A15_LED_config;

void SystemClock_Config(void);
void Error_Handler();

void init_uart()
{
	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	/* defining the UART configuration structure */
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void init_RGB_LED_blue()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	A15_LED_config.Pin = GPIO_PIN_15;
	A15_LED_config.Mode = GPIO_MODE_AF_PP;
	A15_LED_config.Pull = GPIO_NOPULL;
	A15_LED_config.Speed = GPIO_SPEED_HIGH;
	A15_LED_config.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &A15_LED_config);
}

void init_RGB_LED_red()
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	B15_LED_config.Pin = GPIO_PIN_15;
	B15_LED_config.Mode = GPIO_MODE_AF_PP;
	B15_LED_config.Pull = GPIO_NOPULL;
	B15_LED_config.Speed = GPIO_SPEED_HIGH;
	B15_LED_config.Alternate = GPIO_AF9_TIM12;

	HAL_GPIO_Init(GPIOB, &B15_LED_config);
}

void init_RGB_LED_green()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	A8_LED_config.Pin = GPIO_PIN_8;
	A8_LED_config.Mode = GPIO_MODE_AF_PP;
	A8_LED_config.Pull = GPIO_NOPULL;
	A8_LED_config.Speed = GPIO_SPEED_HIGH;
	A8_LED_config.Alternate = GPIO_AF1_TIM1;

	HAL_GPIO_Init(GPIOA, &A8_LED_config);
}


void init_timer_blue()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer_handle_red.Instance = TIM2;
	timer_handle_red.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 s = 0.1 ms
	timer_handle_red.Init.Period = 10000 - 1; // 1000 x 0.1 ms = 100 ms = 1.0 s period
	timer_handle_red.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_red.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle_blue);
}

void init_timer_red()
{
	__HAL_RCC_TIM12_CLK_ENABLE()
	;

	timer_handle_green.Instance = TIM12;
	timer_handle_green.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 s = 0.1 ms
	timer_handle_green.Init.Period = 10000 - 1; // 1000 x 0.1 ms = 100 ms = 1.0 s period
	timer_handle_green.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_green.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle_red);
}

void init_timer_green()
{
	__HAL_RCC_TIM1_CLK_ENABLE()
	;

	timer_handle_blue.Instance = TIM1;
	timer_handle_blue.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 s = 0.1 ms
	timer_handle_blue.Init.Period = 10000 - 1; // 1000 x 0.1 ms = 100 ms = 1.0 s period
	timer_handle_blue.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_blue.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle_green);
}

void init_pwm_blue()
{
	pwm_config_red.Pulse = 0;
	pwm_config_red.OCMode = TIM_OCMODE_PWM1;
	pwm_config_red.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config_red.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle_blue, &pwm_config_blue, TIM_CHANNEL_1);
}

void init_pwm_red()
{
	pwm_config_green.Pulse = 0;
	pwm_config_green.OCMode = TIM_OCMODE_PWM1;
	pwm_config_green.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config_green.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle_red, &pwm_config_red, TIM_CHANNEL_2);
}

void init_pwm_green()
{
	pwm_config_blue.Pulse = 0;
	pwm_config_blue.OCMode = TIM_OCMODE_PWM1;
	pwm_config_blue.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config_blue.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle_green, &pwm_config_green, TIM_CHANNEL_1);
}

void init_adc()
{
	/* configuring A0 pin as analog input */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	/* there is no need for setting the Alternate datafield like other peripherals*/
	gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
	gpio_adc_pin.Pin = GPIO_PIN_0;
	gpio_adc_pin.Speed = GPIO_SPEED_FAST;
	gpio_adc_pin.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	gpio_adc_pin.Pin = GPIO_PIN_10;

	HAL_GPIO_Init(GPIOF, &gpio_adc_pin);

	/* configuring ADC3, as it is the only ADC wired out to the headers */
	__HAL_RCC_ADC3_CLK_ENABLE()
	;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

	/* these 5 settings are closely related */
	adc_handle.Init.ScanConvMode = ENABLE;
	adc_handle.Init.ContinuousConvMode = ENABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.NbrOfConversion = 2;

	HAL_ADC_Init(&adc_handle);

	/* configuring a channel belonging to ADC3 */
	// X axis
	adc_channel_config.Channel = ADC_CHANNEL_0;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	adc_channel_config.Rank = 1;

	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

	// Y axis
	adc_channel_config.Channel = ADC_CHANNEL_8;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	adc_channel_config.Rank = 2;

	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_uart();
	init_adc();
	init_RGB_LED_blue();
	init_RGB_LED_red();
	init_RGB_LED_green();
	init_timer_blue();
	init_timer_red();
	init_timer_green();
	init_pwm_blue();
	init_pwm_red();
	init_pwm_green();

	HAL_TIM_PWM_Start(&timer_handle_red, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&timer_handle_green, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&timer_handle_blue, TIM_CHANNEL_1);

	int adc_val_x;
	int adc_val_y;

	while (1) {
		HAL_ADC_Start(&adc_handle);
		HAL_Delay(500);
		for (int i = 0; i < 10; i++){
			__HAL_TIM_SET_COMPARE(&timer_handle_blue, TIM_CHANNEL_1, i * 10);
		}
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
			adc_val_x = HAL_ADC_GetValue(&adc_handle);
		}
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
			adc_val_y = HAL_ADC_GetValue(&adc_handle);
		}
		// szinvaltas
		__HAL_TIM_SET_COMPARE(&timer_handle_red, TIM_CHANNEL_1, (adc_val_x % 100 + 1));
		__HAL_TIM_SET_COMPARE(&timer_handle_green, TIM_CHANNEL_2, (adc_val_y % 100 + 1));
		__HAL_TIM_SET_COMPARE(&timer_handle_blue, TIM_CHANNEL_1, (adc_val_x % 100 + 1));

	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
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
