/**
  ******************************************************************************
  * File Name          : Target/key_conf.h
  * Description        : This file provides code for the configuration
  *                      of the KEY instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_CONF_H__
#define __KEY_CONF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx.h"

/* KEY_CENTER Pin mapping */
#define KEY_CENTER_GPIO_PORT     GPIOC
#define KEY_CENTER_GPIO_PIN      GPIO_PIN_7
#define KEY_CENTER_GPIO_LINE     7
#define KEY_CENTER_GPIO_IRQn     EXTI4_15_IRQn

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* KEY_DOWN Pin mapping */
#define KEY_DOWN_GPIO_PORT       GPIOB
#define KEY_DOWN_GPIO_PIN        GPIO_PIN_4
#define KEY_DOWN_GPIO_LINE       4
#define KEY_DOWN_GPIO_IRQn       EXTI4_15_IRQn

/* KEY_LEFT Pin mapping */
#define KEY_LEFT_GPIO_PORT       GPIOB
#define KEY_LEFT_GPIO_PIN        GPIO_PIN_0
#define KEY_LEFT_GPIO_LINE       0
#define KEY_LEFT_GPIO_IRQn       EXTI0_1_IRQn

/* KEY_RIGHT Pin mapping */
#define KEY_RIGHT_GPIO_PORT      GPIOB
#define KEY_RIGHT_GPIO_PIN       GPIO_PIN_1
#define KEY_RIGHT_GPIO_LINE      1
#define KEY_RIGHT_GPIO_IRQn      EXTI4_15_IRQn

/* KEY_UP Pin mapping */
#define KEY_UP_GPIO_PORT         GPIOB
#define KEY_UP_GPIO_PIN          GPIO_PIN_12
#define KEY_UP_GPIO_LINE         12
#define KEY_UP_GPIO_IRQn         EXTI4_15_IRQn

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* __KEY_CONF_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
