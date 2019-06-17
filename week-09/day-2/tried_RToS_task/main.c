#include "stm32f7xx.h"
#include "stm32f7xx_hal_gpio.h"
#include "main.h"
#include "cmsis_os.h"

osThreadId Thread1Handle;
osThreadId Thread2Handle;
TIM_HandleTypeDef timer_handle;
GPIO_InitTypeDef user_led_handle;

TickType_t tick_tock;

typedef enum {
    PULSE_ONE, PULSE_TWO
} pulse_state_t;

volatile pulse_state_t pulse_state;
volatile uint8_t counter;

void SystemClock_Config(void);
void init_user_led(void);
void StartThreadOne(void const * argument);
void StartThreadTwo(void const * argument);


int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_user_led();

    osThreadDef(Thread1, StartThreadOne, osPriorityNormal, 0, 128);
    Thread1Handle = osThreadCreate(osThread(Thread1), NULL);

    osThreadDef(Thread2, StartThreadTwo, osPriorityIdle, 0, 128);
    Thread2Handle = osThreadCreate(osThread(Thread2), NULL);

    pulse_state = PULSE_ONE;
        counter = 0;

    osKernelStart();


    while (1) {

    }
}


void StartThreadOne(void const * argument)
{
	tick_tock = osKernelSysTick();
	while (1) {
		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
		counter++;
		if (pulse_state == PULSE_ONE) {
			osDelayUntil(&tick_tock, 200);
			if (counter == 25) {
				osThreadSuspend(Thread1Handle);
				counter = 0;
			}
		}
		if (pulse_state == PULSE_TWO) {
			osDelayUntil(&tick_tock, 400);
			if (counter == 13) {
				osThreadSuspend(Thread1Handle);
				counter = 0;
			}
		}
	}
}

void StartThreadTwo(void const * argument)
{
	tick_tock = osKernelSysTick();
	while (1) {
		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
		counter++;
		osDelayUntil(&tick_tock, 500);
		if (counter == 20) {
			if (pulse_state == PULSE_ONE) {
				pulse_state = PULSE_TWO;
			} else if (pulse_state == PULSE_TWO) {
				pulse_state = PULSE_ONE;
			}
			counter = 0;
			osThreadResume(Thread1Handle);
		}
	}
}


void init_user_led(void)
{
    __HAL_RCC_GPIOI_CLK_ENABLE();

	user_led_handle.Pin = GPIO_PIN_1;
	user_led_handle.Pull = GPIO_NOPULL;
	user_led_handle.Speed = GPIO_SPEED_FAST;
	user_led_handle.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(GPIOI, &user_led_handle);
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE()
    ;
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
    /** Initializes the CPU, AHB and APB busses clocks
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 10;
    RCC_OscInitStruct.PLL.PLLN = 210;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB busses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
            | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
        Error_Handler();
    }
}

void Error_Handler(void)
{

}
