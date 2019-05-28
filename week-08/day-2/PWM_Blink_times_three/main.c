#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void SystemClock_Config(void);

/* the timer's config structure */
TIM_HandleTypeDef timer_handle_A;
TIM_HandleTypeDef timer_handle_H;
TIM_HandleTypeDef timer_handle_B;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef pwm_config_A;
TIM_OC_InitTypeDef pwm_config_H;
TIM_OC_InitTypeDef pwm_config_B;

/* pin config: we cannot use the green user LED because it's not connected to an output compare channel so we use PA15 */
GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef PH6_LED_config;
GPIO_InitTypeDef PB4_LED_config;

void init_LED_A()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;  /* we need this alternate function to use TIM2 in OC mode */

    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_timer_A()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle_A.Instance = TIM2;
    timer_handle_A.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
    timer_handle_A.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
    timer_handle_A.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_A.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_PWM_Init(&timer_handle_A);
}
void init_LED_H()
{
    __HAL_RCC_GPIOH_CLK_ENABLE();

    PH6_LED_config.Pin = GPIO_PIN_6;
    PH6_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
    PH6_LED_config.Pull = GPIO_NOPULL;
    PH6_LED_config.Speed = GPIO_SPEED_HIGH;
    PH6_LED_config.Alternate = GPIO_AF9_TIM12;  /* we need this alternate function to use TIM2 in OC mode */

    HAL_GPIO_Init(GPIOH, &PH6_LED_config);
}

void init_timer_H()
{
    __HAL_RCC_TIM12_CLK_ENABLE();

    timer_handle_H.Instance = TIM12;
    timer_handle_H.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
    timer_handle_H.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
    timer_handle_H.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_H.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_PWM_Init(&timer_handle_H);
}
void init_LED_B()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    PB4_LED_config.Pin = GPIO_PIN_4;
    PB4_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
    PB4_LED_config.Pull = GPIO_NOPULL;
    PB4_LED_config.Speed = GPIO_SPEED_HIGH;
    PB4_LED_config.Alternate = GPIO_AF2_TIM3;  /* we need this alternate function to use TIM2 in OC mode */

    HAL_GPIO_Init(GPIOB, &PB4_LED_config);
}

void init_timer_B()
{
    __HAL_RCC_TIM3_CLK_ENABLE();

    timer_handle_B.Instance = TIM3;
    timer_handle_B.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
    timer_handle_B.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
    timer_handle_B.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_B.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_PWM_Init(&timer_handle_B);
}

void init_PWM_A()
{
    /*
     * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
     * our eyes are not able to notice that it is a vibrating light
    */
	pwm_config_A.Pulse = 50;
    pwm_config_A.OCMode = TIM_OCMODE_PWM1;
    pwm_config_A.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config_A.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle_A, &pwm_config_A, TIM_CHANNEL_1);
}
void init_PWM_H()
{
    /*
     * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
     * our eyes are not able to notice that it is a vibrating light
    */
	pwm_config_H.Pulse = 50;
	pwm_config_H.OCMode = TIM_OCMODE_PWM1;
	pwm_config_H.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config_H.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle_H, &pwm_config_H, TIM_CHANNEL_1);
}
void init_PWM_B()
{
    /*
     * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
     * our eyes are not able to notice that it is a vibrating light
    */
	pwm_config_B.Pulse = 50;
	pwm_config_B.OCMode = TIM_OCMODE_PWM1;
	pwm_config_B.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config_B.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle_B, &pwm_config_B, TIM_CHANNEL_1);
}


int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_LED_A();
    init_LED_H();
    init_LED_B();
    init_timer_A();
    init_timer_H();
    init_timer_B();
    init_PWM_A();
    init_PWM_H();
    init_PWM_B();

    // Start the timer for PWM
    HAL_TIM_PWM_Start(&timer_handle_A, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&timer_handle_H, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&timer_handle_B, TIM_CHANNEL_1);

    while (1) {
        // We can set the compare value (the pulse width of the signal) like this:
        __HAL_TIM_SET_COMPARE(&timer_handle_A, TIM_CHANNEL_1, 25);
        __HAL_TIM_SET_COMPARE(&timer_handle_H, TIM_CHANNEL_1, 10);
        __HAL_TIM_SET_COMPARE(&timer_handle_B, TIM_CHANNEL_1, 60);
        HAL_Delay(500);
        __HAL_TIM_SET_COMPARE(&timer_handle_A, TIM_CHANNEL_1, 60);
        __HAL_TIM_SET_COMPARE(&timer_handle_H, TIM_CHANNEL_1, 50);
        __HAL_TIM_SET_COMPARE(&timer_handle_B, TIM_CHANNEL_1, 15);
        HAL_Delay(500);
    }
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
