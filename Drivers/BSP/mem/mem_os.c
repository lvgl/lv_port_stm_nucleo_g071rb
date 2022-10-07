/**
  ******************************************************************************
  * File Name          : mem_os.c
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
#include "mem_os.h"
#include "mem_conf.h"

#include <stm32g0xx_hal.h>

/** @addtogroup MEM OS Wrapper
  * @{
  */

/** @defgroup MEM_OS MEM OS
  * @brief      This file includes the OS driver of
  *             MEM module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/** @defgroup MEM_OS_Private_Types Private Types
  * @{
  */

/**
  * @}
  */

/* Private define ------------------------------------------------------------*/
/** @defgroup MEM_OS_Private_Constants Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup MEM_OS_Private_Macros Private Macros
  * @{
  */

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup MEM_OS_Private_Variables Private Variables
  * @{
  */
static volatile uint8_t mem_sem[MEM_INSTANCES_NBR];

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup MEM_OS_Private_Functions_Prototypes Private Functions Prototypes
  * @{
  */

/* Exported variables --------------------------------------------------------*/
/** @defgroup MEM_OS_Exported_Variables Exported Variables
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/* Deprecated functions ------------------------------------------------------*/
/** @defgroup MEM_OS_Deprecated_Functions Deprecated Functions
  * @{
  */

/**
  * @}
  */

/* Private function ----------------------------------------------------------*/
/** @defgroup MEM_OS_Private_FunctionPrototypes Private Functions
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup MEM_OS_Exported_Functions Exported Functions
  * @{
  */
/**
  * @brief  Initialize the MEM OS ressources.
  * @param  Instance MEM Instance
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_Initialize(uint32_t Instance)
{
  uint8_t i;
  for(i = 0; i < MEM_INSTANCES_NBR; i++)
  {
    mem_sem[i] = 0;
  }
  return MEM_OS_ERROR_NONE;
}

/**
  * @brief  Lock the MEM ressources. Blocks until lock is available.
  * @param  Instance MEM Instance
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_Lock(uint32_t Instance)
{
  while(mem_sem[Instance]);
  mem_sem[Instance] = 1;
  return MEM_OS_ERROR_NONE;
}

/**
  * @brief  Unlock the MEM ressources.
  * @param  Instance MEM Instance
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_Unlock(uint32_t Instance)
{
  mem_sem[Instance] = 0;
  return MEM_OS_ERROR_NONE;
}

/**
  * @brief  Safe unlock the MEM ressources in interrupt context.
  * @param  Instance MEM Instance
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_UnlockFromISR(uint32_t Instance)
{
  mem_sem[Instance] = 0;
  return MEM_OS_ERROR_NONE;
}

/**
  * @brief  Attempt to lock the MEM. If the lock is not available, do
  *         nothing.
  * @param  Instance MEM Instance
  * @param  Timeout timeout in ms
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_TryLock(uint32_t Instance, uint32_t Timeout)
{
  uint32_t tickstart = HAL_GetTick();

  if(mem_sem[Instance] == 0)
  {
    mem_sem[Instance] = 1;
    return MEM_OS_ERROR_NONE;
  }
  else if(Timeout == 0)
  {
    return MEM_OS_ERROR_BUSY;
  }
  else
  {
    do
    {
      if(mem_sem[Instance] == 0)
      {
        mem_sem[Instance] = 1;
        return MEM_OS_ERROR_NONE;
      }
    } while ((HAL_GetTick() - tickstart) < Timeout);
    return MEM_OS_ERROR_BUSY;
  }
}

/**
  * @brief  This function checks if the MEM ressources are locked or not.
  * @param  Instance MEM Instance
  * @retval '1' if locked, '0' otherwise
  */
uint8_t MEM_OS_IsLocked(uint32_t Instance)
{
  return mem_sem[Instance];
}

/**
  * @brief  This function will block until MEM transfer is Done.
  * @param  Instance MEM Instance
  * @retval MEM_OS_Error_t
  */
uint8_t MEM_OS_WaitForTransferToBeDone(uint32_t Instance)
{
  while(mem_sem[Instance]);
  return MEM_OS_ERROR_NONE;
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
