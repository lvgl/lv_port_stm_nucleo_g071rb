/**
  ******************************************************************************
  * File Name          : lcd_os.c
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
#include "lcd_os.h"
#include "lcd_conf.h"

#include <stm32g0xx_hal.h>

/** @addtogroup LCD OS Wrapper
  * @{
  */

/** @defgroup LCD_OS LCD OS
  * @brief      This file includes the OS driver of
  *             LCD module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/** @defgroup LCD_OS_Private_Types Private Types
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------*/
/** @defgroup LCD_OS_Private_Constants Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup LCD_OS_Private_Macros Private Macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup LCD_OS_Private_Variables Private Variables
  * @{
  */
static volatile uint8_t lcd_sem[LCD_INSTANCES_NBR];

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup LCD_OS_Private_Functions_Prototypes Private Functions Prototypes
  * @{
  */

/* Exported variables --------------------------------------------------------*/
/** @defgroup LCD_OS_Exported_Variables Exported Variables
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/* Deprecated functions ------------------------------------------------------*/
/** @defgroup LCD_OS_Deprecated_Functions Deprecated Functions
  * @{
  */

/**
  * @}
  */

/* Private function ----------------------------------------------------------*/
/** @defgroup LCD_OS_Private_FunctionPrototypes Private Functions
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup LCD_OS_Exported_Functions Exported Functions
  * @{
  */
/**
  * @brief  Initialize the LCD OS ressources.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Initialize(uint32_t Instance)
{
  uint8_t i;
  for(i = 0; i < LCD_INSTANCES_NBR; i++)
  {
    lcd_sem[i] = 0;
  }
  return LCD_OS_ERROR_NONE;
}

/**
  * @brief  Lock the LCD ressources. Blocks until lock is available.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Lock(uint32_t Instance)
{
  while(lcd_sem[Instance]);
  lcd_sem[Instance] = 1;
  return LCD_OS_ERROR_NONE;
}

/**
  * @brief  Unlock the LCD ressources.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Unlock(uint32_t Instance)
{
  lcd_sem[Instance] = 0;
  return LCD_OS_ERROR_NONE;
}

/**
  * @brief  Safe unlock the LCD ressources in interrupt context.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_UnlockFromISR(uint32_t Instance)
{
  lcd_sem[Instance] = 0;
  return LCD_OS_ERROR_NONE;
}

/**
  * @brief  Attempt to lock the LCD. If the lock is not available, do
  *         nothing.
  * @param  Instance LCD Instance
  * @param  Timeout timeout in ms
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_TryLock(uint32_t Instance, uint32_t Timeout)
{
  uint32_t tickstart = HAL_GetTick();

  if(lcd_sem[Instance] == 0)
  {
    lcd_sem[Instance] = 1;
    return LCD_OS_ERROR_NONE;
  }
  else if(Timeout == 0)
  {
    return LCD_OS_ERROR_BUSY;
  }
  else
  {
    do
    {
      if(lcd_sem[Instance] == 0)
      {
        lcd_sem[Instance] = 1;
        return LCD_OS_ERROR_NONE;
      }
    } while ((HAL_GetTick() - tickstart) < Timeout);
    return LCD_OS_ERROR_BUSY;
  }
}

/**
  * @brief  This function checks if the LCD ressources are locked or not.
  * @param  Instance LCD Instance
  * @retval '1' if locked, '0' otherwise
  */
uint8_t LCD_OS_IsLocked(uint32_t Instance)
{
  return lcd_sem[Instance];
}

/**
  * @brief  This function will block until LCD transfer is Done.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_WaitForTransferToBeDone(uint32_t Instance)
{
  while(lcd_sem[Instance]);
  return LCD_OS_ERROR_NONE;
}

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
