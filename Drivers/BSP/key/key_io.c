/**
  ******************************************************************************
  * File Name          : Target/key_io.c
  * Description        : This file provides code for the configuration
  *                      of the KEY IO instances.
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

/* Includes ------------------------------------------------------------------*/
#include "key_io.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32G0XX_NUCLEO
  * @{
  */

/** @defgroup STM32G0XX_NUCLEO_KEY STM32G0XX_NUCLEO KEY
  * @brief      This file includes the KEY driver of
  *             STM32G0XX_NUCLEO boards.
  * @{
  */

/** @defgroup STM32G0XX_NUCLEO_KEY_Private_Types Private Types
  * @{
  */
typedef struct
{
  uint32_t Orientation;
}BSP_KEY_Ctx_t;

/** @defgroup STM32G0XX_NUCLEO_KEY_Private_Constants Private Constants
  * @{
  */
/* Number of KEY instances */
#define KEY_INSTANCES_NBR                       1U

/* Pressed state GPIO value */
#define KEY_PRESSED_STATE                       GPIO_PIN_RESET

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_KEY_Private_Macros Private Macros
  * @{
  */
#define BSP_KEY_CHECK_PARAMS(Instance)

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_KEY_Exported_Variables Exported Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_KEY_Private_Variables Private Variables
  * @{
  */
static BSP_KEY_Ctx_t KeyCtx[KEY_INSTANCES_NBR];

/**
  * @}
  */

/** STM32G0XX_NUCLEO_KEY_Private_FunctionPrototypes Private Functions
  */

/**
  * @}
  */

/** @addtogroup STM32G0XX_NUCLEO_KEY_Exported_Functions
  * @{
  */
/**
  * @brief  Initializes the KEY.
  * @param  Instance    KEY Instance
  * @param  Orientation KEY Orientation
  * @retval BSP status
  */
int32_t BSP_KEY_Init(uint32_t Instance, uint8_t Orientation)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_KEY_CHECK_PARAMS(Instance);

  KeyCtx[Instance].Orientation = Orientation;

  return ret;
}

/**
  * @brief  De-Initializes the KEY resources.
  * @param  Instance KEY Instance
  * @retval BSP status
  */
int32_t BSP_KEY_DeInit(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_KEY_CHECK_PARAMS(Instance);

  KeyCtx[Instance].Orientation = 0;

  return ret;
}

/**
  * @brief  Sets the KEY Orientation.
  * @param  Instance KEY Instance
  * @param  pOrientation New KEY Orientation
  * @retval BSP status
  */
int32_t BSP_KEY_SetOrientation(uint32_t Instance, uint32_t Orientation)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_KEY_CHECK_PARAMS(Instance);

  if(KeyCtx[Instance].Orientation != Orientation)
  {
    KeyCtx[Instance].Orientation = Orientation;
  }

  return ret;
}

/**
  * @brief  Read Key State.
  * @param  Instance KEY Instance
  * @param  State pointer to Key State
  * @retval BSP status
  */
int32_t BSP_KEY_GetState(uint32_t Instance, uint8_t *State)
{
  BSP_KEY_CHECK_PARAMS(Instance);

  *State = BSP_KEY_INVALID;

#if defined(KEY_CENTER_GPIO_PIN)
  if (HAL_GPIO_ReadPin(KEY_CENTER_GPIO_PORT, KEY_CENTER_GPIO_PIN) == KEY_PRESSED_STATE)
    *State = BSP_KEY_CENTER;
  else
#endif /* KEY_CENTER_GPIO_PIN */
#if defined(KEY_UP_GPIO_PIN)
  if (HAL_GPIO_ReadPin(KEY_UP_GPIO_PORT, KEY_UP_GPIO_PIN) == KEY_PRESSED_STATE)
    *State =  (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT         ? BSP_KEY_UP :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT_ROT180  ? BSP_KEY_DOWN :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE        ? BSP_KEY_RIGHT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE_ROT180 ? BSP_KEY_LEFT : BSP_KEY_INVALID))));
  else
#endif /* KEY_UP_GPIO_PIN */
#if defined(KEY_DOWN_GPIO_PIN)
  if (HAL_GPIO_ReadPin(KEY_DOWN_GPIO_PORT, KEY_DOWN_GPIO_PIN) == KEY_PRESSED_STATE)
    *State =  (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT         ? BSP_KEY_DOWN :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT_ROT180  ? BSP_KEY_UP :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE        ? BSP_KEY_LEFT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE_ROT180 ? BSP_KEY_RIGHT : BSP_KEY_INVALID))));
  else
#endif /* KEY_DOWN_GPIO_PIN */
#if defined(KEY_LEFT_GPIO_PIN)
  if (HAL_GPIO_ReadPin(KEY_LEFT_GPIO_PORT, KEY_LEFT_GPIO_PIN) == KEY_PRESSED_STATE)
    *State =  (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT         ? BSP_KEY_LEFT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT_ROT180  ? BSP_KEY_RIGHT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE        ? BSP_KEY_DOWN :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE_ROT180 ? BSP_KEY_UP : BSP_KEY_INVALID))));
  else
#endif /* KEY_LEFT_GPIO_PIN */
#if defined(KEY_RIGHT_GPIO_PIN)
  if (HAL_GPIO_ReadPin(KEY_RIGHT_GPIO_PORT, KEY_RIGHT_GPIO_PIN) == KEY_PRESSED_STATE)
    *State =  (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT         ? BSP_KEY_RIGHT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_PORTRAIT_ROT180  ? BSP_KEY_LEFT :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE        ? BSP_KEY_UP :
              (KeyCtx[Instance].Orientation == KEY_ORIENTATION_LANDSCAPE_ROT180 ? BSP_KEY_DOWN : BSP_KEY_INVALID))));
  else
#endif /* KEY_RIGHT_GPIO_PIN */

  if(*State == BSP_KEY_INVALID)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  return BSP_ERROR_NONE;
}

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_KEY_Private_Functions Private Functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
