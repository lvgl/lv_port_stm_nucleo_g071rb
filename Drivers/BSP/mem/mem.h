/**
  ******************************************************************************
  * @file    mem.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the external
  *          Memory driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MEM_H
#define MEM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup MEM
  * @{
  */

/** @defgroup MEM_Exported_Constants MEM Exported Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup MEM_Exported_Types
  * @{
  */

/** @defgroup MEM_Exported_Macros
  * @{
  */
/**
 * Compiler specific macros.
 * MEM_DEPRECATED is used to mark a function deprecated.
 */
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
// xgcc
#define MEM_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#elif defined __ICCARM__
// IAR
#if __IAR_SYSTEMS_ICC__ >= 9
#define MEM_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#else
#define MEM_DEPRECATED(message, decl) decl
#endif
#elif defined(__ARMCC_VERSION)
// Keil
#if __ARMCC_VERSION >= 6000000
// Only newer Keil support message to be given
#define MEM_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#else
#define MEM_DEPRECATED(message, decl) decl __attribute__((deprecated))
#endif
#else
// Other/Unknown
#define MEM_DEPRECATED(message, decl) decl
#endif

/** @defgroup MEM_Driver_structure  MEM Driver structure
  * @{
  */
typedef enum {
  MEM_INTERFACE_SPI_MODE = 0,                                     /*!< 1-1-1 commands, Poweron H/W default setting */
  MEM_INTERFACE_DUAL_OUT_MODE,                                    /*!< 1-1-2 commands                              */
  MEM_INTERFACE_DUAL_IO_MODE,                                     /*!< 1-2-2 commands                              */
  MEM_INTERFACE_QUAD_OUT_MODE,                                    /*!< 1-1-4 commands                              */
  MEM_INTERFACE_QUAD_IO_MODE                                      /*!< 1-4-4 commands                              */
} MEM_Interface_t;

typedef struct {
  uint32_t FlashSize;                                          /*!< Size of the flash                           */
  uint32_t EraseBlockSize;                                     /*!< Size of block for the erase operation       */
  uint32_t EraseBlocksNumber;                                  /*!< Number of block for the erase operation     */
  uint32_t EraseSubBlockSize;                                  /*!< Size of sub-block for the erase operation   */
  uint32_t EraseSubBlocksNumber;                               /*!< Number of sub-block for the erase operation */
  uint32_t EraseSectorSize;                                    /*!< Size of sectors for the erase operation     */
  uint32_t EraseSectorsNumber;                                 /*!< Number of sectors for the erase operation   */
  uint32_t ProgPageSize;                                       /*!< Size of pages for the program operation     */
  uint32_t ProgPagesNumber;                                    /*!< Number of pages for the program operation   */
} MEM_Info_t;

typedef struct
{
  /* Control functions */
  int32_t (*Init                    )(void*);
  int32_t (*DeInit                  )(void*);
  int32_t (*ReadID                  )(void*, uint32_t*);
  int32_t (*GetFlashInfo            )(MEM_Info_t*);
  int32_t (*Read                    )(void*, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*ReadDMA                 )(void*, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*Program                 )(void*, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*ProgramDMA              )(void*, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*BlockErase              )(void*, uint32_t, uint32_t);
  int32_t (*ChipErase               )(void*);
  int32_t (*EnableMemoryMappedMode  )(void*, uint32_t);
  int32_t (*ResetEnable             )(void*);
  int32_t (*ResetMemory             )(void*);
} MEM_Drv_t;

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

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* MEM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
