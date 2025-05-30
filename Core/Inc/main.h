/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_FULL_GAS_Pin GPIO_PIN_13
#define BUTTON_FULL_GAS_GPIO_Port GPIOC
#define BUTTON_FULL_GAS_EXTI_IRQn EXTI15_10_IRQn
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOC
#define LD3_Pin GPIO_PIN_1
#define LD3_GPIO_Port GPIOC
#define BUTTON_HORN_Pin GPIO_PIN_1
#define BUTTON_HORN_GPIO_Port GPIOA
#define BUTTON_HORN_EXTI_IRQn EXTI1_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define BUTTON_HALF_GAS_Pin GPIO_PIN_4
#define BUTTON_HALF_GAS_GPIO_Port GPIOA
#define BUTTON_HALF_GAS_EXTI_IRQn EXTI4_IRQn
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define BUTTON_MODE1_Pin GPIO_PIN_6
#define BUTTON_MODE1_GPIO_Port GPIOA
#define BUTTON_MODE2_Pin GPIO_PIN_7
#define BUTTON_MODE2_GPIO_Port GPIOA
#define LD4_Pin GPIO_PIN_4
#define LD4_GPIO_Port GPIOC
#define BUTTON_TIME_Pin GPIO_PIN_5
#define BUTTON_TIME_GPIO_Port GPIOC
#define BUTTON_TIME_EXTI_IRQn EXTI9_5_IRQn
#define LCD_DC_Pin GPIO_PIN_0
#define LCD_DC_GPIO_Port GPIOB
#define LCD_RST_Pin GPIO_PIN_1
#define LCD_RST_GPIO_Port GPIOB
#define LCD_CS_Pin GPIO_PIN_2
#define LCD_CS_GPIO_Port GPIOB
#define LCD_SCK_Pin GPIO_PIN_10
#define LCD_SCK_GPIO_Port GPIOB
#define BUTTON_SC_CLOSE_Pin GPIO_PIN_11
#define BUTTON_SC_CLOSE_GPIO_Port GPIOB
#define BUTTON_SC_CLOSE_EXTI_IRQn EXTI15_10_IRQn
#define BUTTON_FUELCELL_RACE_MODE_Pin GPIO_PIN_9
#define BUTTON_FUELCELL_RACE_MODE_GPIO_Port GPIOA
#define BUTTON_FUELCELL_PREPARE_TO_RACE_MODE_Pin GPIO_PIN_10
#define BUTTON_FUELCELL_PREPARE_TO_RACE_MODE_GPIO_Port GPIOA
#define BUTTON_FUELCELL_OFF_MODE_Pin GPIO_PIN_11
#define BUTTON_FUELCELL_OFF_MODE_GPIO_Port GPIOA
#define BUTTON_EMERGENCY_Pin GPIO_PIN_12
#define BUTTON_EMERGENCY_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LD5_Pin GPIO_PIN_10
#define LD5_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
