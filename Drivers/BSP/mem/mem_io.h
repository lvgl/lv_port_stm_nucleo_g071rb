/**
  ******************************************************************************
  * File Name          : Target/mem_io.h
  * Description        : This file provides code for the exported APIs
  *                      of the MEM instances.
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
#ifndef __MEM_IO_H__
#define __MEM_IO_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "mem.h"
#include "mem_conf.h"
#include "mx25l6433f.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* BSP Common Error codes */
#ifndef BSP_ERROR_NONE
#define BSP_ERROR_NONE                      0
#define BSP_ERROR_NO_INIT                   -1
#define BSP_ERROR_WRONG_PARAM               -2
#define BSP_ERROR_BUSY                      -3
#define BSP_ERROR_PERIPH_FAILURE            -4
#define BSP_ERROR_COMPONENT_FAILURE         -5
#define BSP_ERROR_UNKNOWN_FAILURE           -6
#define BSP_ERROR_UNKNOWN_COMPONENT         -7
#define BSP_ERROR_BUS_FAILURE               -8
#define BSP_ERROR_CLOCK_FAILURE             -9
#define BSP_ERROR_MSP_FAILURE               -10
#define BSP_ERROR_FEATURE_NOT_SUPPORTED     -11
#endif /* BSP_ERROR_NONE */

#define MEM_BASE_ADDRESS                    0x90000000
#define MEM_FLASH_SIZE                      MX25L6433F_FLASH_SIZE

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
int32_t BSP_MEM_Init(uint32_t Instance);
int32_t BSP_MEM_DeInit(uint32_t Instance);
int32_t BSP_MEM_BlockErase(uint32_t Instance, uint32_t BlockAddress, uint32_t BlockSize);
int32_t BSP_MEM_ChipErase(uint32_t Instance);
int32_t BSP_MEM_ReadData(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size);
int32_t BSP_MEM_ReadDataDMA(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size);
int32_t BSP_MEM_WriteData(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size);
int32_t BSP_MEM_WriteDataDMA(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size);
int32_t BSP_MEM_EnableMemoryMappedMode(uint32_t Instance);
int32_t BSP_MEM_GetStatus(uint32_t Instance);
uint8_t BSP_MEM_GetTransferStatus(uint32_t Instance);
void    BSP_MEM_WaitForTransferToBeDone(uint32_t Instance);
void    BSP_MEM_SignalTransferDone(uint32_t Instance);

/* Deprecated APIs */
MEM_DEPRECATED("Use BSP_MEM_GetTransferStatus(Instance) instead.", uint8_t BSP_MEM_GetTransfertStatus(uint32_t Instance));
MEM_DEPRECATED("Use BSP_MEM_SignalTransferDone(Instance) instead.", void BSP_MEM_SignalTransfertDone(uint32_t Instance, uint8_t Event));

#ifdef __cplusplus
}
#endif
#endif /* __MEM_IO_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
