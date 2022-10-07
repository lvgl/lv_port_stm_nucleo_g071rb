/**
  ******************************************************************************
  * File Name          : lcd_os.h
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
#ifndef __LCD_OS_H__
#define __LCD_OS_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
typedef enum
{
  LCD_OS_ERROR_NONE = 0
, LCD_OS_ERROR_WRONG_PARAM
, LCD_OS_ERROR_INIT
, LCD_OS_ERROR_BUSY
, LCD_OS_ERROR_WAIT
, LCD_OS_ERROR_LOCK
, LCD_OS_ERROR_UNLOCK
} LCD_OS_Error_t;

#define LCD_OS_NO_WAIT                      ((uint32_t)  0)
#define LCD_OS_WAIT_FOREVER                 ((uint32_t)  0xFFFFFFFFUL)

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/**
  * @brief  Initialize the LCD OS ressources.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Initialize(uint32_t Instance);

/**
  * @brief  Lock the LCD ressources. Blocks until lock is available.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Lock(uint32_t Instance);

/**
  * @brief  Unlock the LCD ressources.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_Unlock(uint32_t Instance);

/**
  * @brief  Safe unlock the LCD ressources in interrupt context.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_UnlockFromISR(uint32_t Instance);

/**
  * @brief  Attempt to lock the LCD. If the lock is not available, do
  *         nothing.
  * @param  Instance LCD Instance
  * @param  Timeout timeout in ms
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_TryLock(uint32_t Instance, uint32_t Timeout);

/**
  * @brief  This function checks if the LCD ressources are locked or not.
  * @param  Instance LCD Instance
  * @retval '1' if locked, '0' otherwise
  */
uint8_t LCD_OS_IsLocked(uint32_t Instance);

/**
  * @brief  This function will block until LCD transfer is Done.
  * @param  Instance LCD Instance
  * @retval LCD_OS_Error_t
  */
uint8_t LCD_OS_WaitForTransferToBeDone(uint32_t Instance);

#ifdef __cplusplus
}
#endif
#endif /* __LCD_OS_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
