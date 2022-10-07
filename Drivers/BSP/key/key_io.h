/**
  ******************************************************************************
  * File Name          : Target/key_io.h
  * Description        : This file provides code for the exported APIs
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
#ifndef __KEY_IO_H__
#define __KEY_IO_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "key_conf.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
#ifndef BSP_ERROR_NONE
/* BSP Common Error codes */
#define BSP_ERROR_NONE                    0
#define BSP_ERROR_NO_INIT                -1
#define BSP_ERROR_WRONG_PARAM            -2
#define BSP_ERROR_BUSY                   -3
#define BSP_ERROR_PERIPH_FAILURE         -4
#define BSP_ERROR_COMPONENT_FAILURE      -5
#define BSP_ERROR_UNKNOWN_FAILURE        -6
#define BSP_ERROR_UNKNOWN_COMPONENT      -7
#define BSP_ERROR_BUS_FAILURE            -8
#define BSP_ERROR_CLOCK_FAILURE          -9
#define BSP_ERROR_MSP_FAILURE            -10
#define BSP_ERROR_FEATURE_NOT_SUPPORTED      -11
#endif /* BSP_ERROR_NONE */

/* Key state values */
enum
{
  BSP_KEY_INVALID
, BSP_KEY_CENTER
, BSP_KEY_UP
, BSP_KEY_DOWN
, BSP_KEY_LEFT
, BSP_KEY_RIGHT
};

/* KEY Orientation */
enum
{
  KEY_ORIENTATION_PORTRAIT
, KEY_ORIENTATION_PORTRAIT_ROT180
, KEY_ORIENTATION_LANDSCAPE
, KEY_ORIENTATION_LANDSCAPE_ROT180
};

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
int32_t BSP_KEY_Init(uint32_t Instance, uint8_t Orientation);
int32_t BSP_KEY_DeInit(uint32_t Instance);
int32_t BSP_KEY_SetOrientation(uint32_t Instance, uint32_t Orientation);
int32_t BSP_KEY_GetState(uint32_t Instance, uint8_t *State);

#ifdef __cplusplus
}
#endif
#endif /* __KEY_IO_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
