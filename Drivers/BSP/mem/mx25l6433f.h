/**
  ******************************************************************************
  * @file    mx25l6433f.h
  * @author  MCD Application Team
  * @brief   This file contains all the description of the MX25L6433F QSPI memory.
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
#ifndef MX25L6433F_H
#define MX25L6433F_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup MX25L6433F
  * @{
  */

/** @defgroup MX25L6433F_Exported_Constants MX25L6433F Exported Constants
  * @{
  */
/**
  * @brief  MX25L6433F Size configuration
  */
#define MX25L6433F_BLOCK_64K                            (uint32_t)(64 * 1024)        /* 128 blocks of 64KBytes      */
#define MX25L6433F_BLOCK_32K                            (uint32_t)(32 * 1024)        /* 256 blocks of 32KBytes      */
#define MX25L6433F_SECTOR_4K                            (uint32_t)(4  * 1024)        /* 2048 sectors of 4KBytes     */

#define MX25L6433F_FLASH_SIZE                           (uint32_t)(64*1024*1024/8)   /* 64 Mbits => 8MBytes         */
#define MX25L6433F_PAGE_SIZE                            (uint32_t)256                /* 32768 pages of 256 Bytes    */

/**
  * @brief  MX25L6433F Timing configuration
  */

#define MX25L6433F_CHIP_ERASE_MAX_TIME                  60000U
#define MX25L6433F_BLOCK_64K_ERASE_MAX_TIME             1000U
#define MX25L6433F_BLOCK_32K_ERASE_MAX_TIME             600U
#define MX25L6433F_SECTOR_4K_ERASE_MAX_TIME             200U
#define MX25L6433F_WRITE_REG_MAX_TIME                   40U

#define MX25L6433F_RESET_MAX_TIME                       10U     /* when SWreset during chip erase operation */
#define MX25L6433F_AUTO_POLLING_INTERVAL                16U

/* MEM Wrap Around depth */
#define MX25L6433F_WRAP_AROUND_8BYTE                    0x00U   /* 8-bit Wrap Depth */
#define MX25L6433F_WRAP_AROUND_16BYTE                   0x01U   /* 16-bit Wrap Depth */
#define MX25L6433F_WRAP_AROUND_32BYTE                   0x02U   /* 32-bit Wrap Depth */
#define MX25L6433F_WRAP_AROUND_64BYTE                   0x03U   /* 64-bit Wrap Depth */
#define MX25L6433F_WRAP_AROUND_DISABLE                  0x10U   /* No Wrap Depth */

/**
  * @brief  MX25L6433F Error codes
  */
#define MX25L6433F_MANUFACTURER_ID                      0xC2
#define MX25L6433F_MEMORY_TYPE_ID                       0x20
#define MX25L6433F_MEMORY_DENSITY_ID                    0x17
#define MX25L6433F_ID                                   0x001720C2

/**
  * @brief  MX25L6433F Error codes
  */
#define MX25L6433F_OK                                   (0)
#define MX25L6433F_ERROR                                (-1)

/******************************************************************************
  * @brief  MX25L6433F Commands
  ****************************************************************************/
/* Read Operations */
#define MX25L6433F_READ_CMD                             0x03U  /*!< Normal Read                                 */
#define MX25L6433F_FAST_READ_CMD                        0x0BU  /*!< Fast Read Data                              */
#define MX25L6433F_DUAL_OUT_READ_CMD                    0x3BU  /*!< 1I / 20 Read                                */
#define MX25L6433F_DUAL_INOUT_READ_CMD                  0xBBU  /*!< 2 x I/O Read                                */
#define MX25L6433F_QUAD_OUT_READ_CMD                    0x6BU  /*!< 1I / 4O Read                                */
#define MX25L6433F_QUAD_INOUT_READ_CMD                  0xEBU  /*!< 4 x I/O Read                                */

/* Program Operations */
#define MX25L6433F_PAGE_PROG_CMD                        0x02U  /*!< Page Program                                */
#define MX25L6433F_QUAD_PAGE_PROG_CMD                   0x38U  /*!< Quad Page Program                           */

/* Erase Operations */
#define MX25L6433F_SECTOR_ERASE_CMD                     0x20U  /*!< Sector Erase                                */
#define MX25L6433F_SUBBLOCK_ERASE_CMD                   0x52U  /*!< Block Erase 32KB                            */
#define MX25L6433F_BLOCK_ERASE_CMD                      0xD8U  /*!< Block Erase 64KB                            */
#define MX25L6433F_CHIP_ERASE_CMD                       0x60U  /*!< Chip Erase                                  */
#define MX25L6433F_CHIP_ERASE_CMD_2                     0xC7U  /*!< Chip Erase                                  */

#define MX25L6433F_PROG_ERASE_RESUME_CMD                0x7AU  /*!< Resume Program/Erase                        */
#define MX25L6433F_PROG_ERASE_RESUME_CMD_2              0x30U  /*!< Resume Program/Erase                        */
#define MX25L6433F_PROG_ERASE_SUSPEND_CMD               0x75U  /*!< Suspend Program/Erase                       */
#define MX25L6433F_PROG_ERASE_SUSPEND_CMD_2             0xB0U  /*!< Suspend Program/Erase                       */

/* Identification Operations */
#define MX25L6433F_READ_ID_CMD                          0x9FU  /*!< Read Identification                         */
#define MX25L6433F_READ_ELECTRONIC_ID_CMD               0xABU  /*!< Read Electronic ID                          */
#define MX25L6433F_READ_ELEC_MANUFACTURER_DEVICE_ID_CMD 0x90U  /*!< Read Electronic Manufacturuer & Device ID   */
#define MX25L6433F_READ_SERIAL_FLASH_DISCO_PARAM_CMD    0x5AU  /*!< Read SFDP                                   */

/* Write Operations */
#define MX25L6433F_WRITE_ENABLE_CMD                     0x06U  /*!< Write Enable                                */
#define MX25L6433F_WRITE_DISABLE_CMD                    0x04U  /*!< Write Disable                               */

/* Register Operations */
#define MX25L6433F_READ_STATUS_REG_CMD                  0x05U  /*!< Read Status Register                        */
#define MX25L6433F_READ_CFG_REG_CMD                     0x15U  /*!< Read Configuration Register                 */
#define MX25L6433F_WRITE_STATUS_CFG_REG_CMD             0x01U  /*!< Write Status Register                       */

#define MX25L6433F_READ_SEC_REG_CMD                     0x2BU  /*!< Read Security Register                      */
#define MX25L6433F_WRITE_SEC_REG_CMD                    0x2FU  /*!< Write Security Register                     */

/* Power Down Operations */
#define MX25L6433F_DEEP_POWER_DOWN_CMD                  0xB9U  /*!< Deep Power Down                             */

/* Burst Operations */
#define MX25L6433F_SET_BURST_LENGTH_CMD                 0xC0U  /*!< Set Burst Length                            */

/* One-Time Programmable Operations */
#define MX25L6433F_ENTER_SECURED_OTP_CMD                0xB1U  /*!< Enter Secured OTP                           */
#define MX25L6433F_EXIT_SECURED_OTP_CMD                 0xC1U  /*!< Exit Secured OTP                            */

/* No Operation */
#define MX25L6433F_NO_OPERATION_CMD                     0x00U  /*!< No Operation                                */

/* Reset Operations */
#define MX25L6433F_RESET_ENABLE_CMD                     0x66U  /*!< Reset Enable                                */
#define MX25L6433F_RESET_MEMORY_CMD                     0x99U  /*!< Reset Memory                                */
#define MX25L6433F_RELEASE_READ_ENHANCED_CMD            0xFFU  /*!< Release Read Enhanced                       */

/******************************************************************************
  * @brief  MX25L6433F Registers
  ****************************************************************************/
/* Status Register */
#define MX25L6433F_SR_WIP                               0x01U  /*!< Write in progress                           */
#define MX25L6433F_SR_WEL                               0x02U  /*!< Write enable latch                          */
#define MX25L6433F_SR_BP                                0x3CU  /*!< Block protect                               */
#define MX25L6433F_SR_QE                                0x40U  /*!< Quad enable                                 */
#define MX25L6433F_SR_SRWD                              0x80U  /*!< Status register write disable               */

/* Configuration Register 1 */
#define MX25L6433F_CR1_TB                               0x08U  /*!< Top / bottom selected                       */

/* Configuration Register 2 */
#define MX25L6433F_CR2_LH_SWITCH                        0x02U  /*!< Low power / high performance switch         */

/* Security Register */
#define MX25L6433F_SECR_SOI                             0x01U  /*!< Secured OTP indicator                       */
#define MX25L6433F_SECR_LDSO                            0x02U  /*!< Lock-down secured OTP                       */
#define MX25L6433F_SECR_PSB                             0x04U  /*!< Program suspend bit                         */
#define MX25L6433F_SECR_ESB                             0x08U  /*!< Erase suspend bit                           */
#define MX25L6433F_SECR_P_FAIL                          0x20U  /*!< Program fail flag                           */
#define MX25L6433F_SECR_E_FAIL                          0x40U  /*!< Erase fail flag                             */

#define MX25L6433F_WRITE_ENABLE_MATCH_VALUE             MX25L6433F_SR_WEL
#define MX25L6433F_WRITE_ENABLE_MASK_VALUE              MX25L6433F_SR_WEL
#define MX25L6433F_MEMORY_READY_MATCH_VALUE             0x00U
#define MX25L6433F_MEMORY_READY_MASK_VALUE              MX25L6433F_SR_WIP
#define MX25L6433F_QUAD_ENABLE_MATCH_VALUE              MX25L6433F_SR_QE
#define MX25L6433F_QUAD_ENABLE_MASK_VALUE               MX25L6433F_SR_QE

/**
  * @}
  */

/** @defgroup MX25L6433F_Exported_Types MX25L6433F Exported Types
  * @{
  */
typedef int32_t (*MX25L6433F_Init_Func)     (void);
typedef int32_t (*MX25L6433F_DeInit_Func)   (void);
typedef int32_t (*MX25L6433F_GetTick_Func)  (void);
typedef int32_t (*MX25L6433F_Delay_Func)    (uint32_t);
typedef int32_t (*MX25L6433F_SendData_Func) (uint8_t*, uint32_t, uint32_t);
typedef int32_t (*MX25L6433F_RecvData_Func) (uint8_t*, uint32_t, uint32_t);

typedef struct
{
  MX25L6433F_Init_Func          Init;
  MX25L6433F_DeInit_Func        DeInit;
  uint32_t                      Address;
  MX25L6433F_SendData_Func      SendData;
  MX25L6433F_SendData_Func      SendDataDMA;
  MX25L6433F_RecvData_Func      RecvData;
  MX25L6433F_RecvData_Func      RecvDataDMA;
  MX25L6433F_GetTick_Func       GetTick;
} MX25L6433F_IO_t;

typedef struct
{
  MX25L6433F_IO_t         IO;
  uint8_t                 IsInitialized;
  void                    *handle;
} MX25L6433F_Object_t;

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
} MX25L6433F_Info_t;

typedef enum {
  MX25L6433F_SPI_MODE = 0,                                     /*!< 1-1-1 commands, Poweron H/W default setting */
  MX25L6433F_DUAL_OUT_MODE,                                    /*!< 1-1-2 commands                              */
  MX25L6433F_DUAL_IO_MODE,                                     /*!< 1-2-2 commands                              */
  MX25L6433F_QUAD_OUT_MODE,                                    /*!< 1-1-4 commands                              */
  MX25L6433F_QUAD_IO_MODE                                      /*!< 1-4-4 commands                              */
} MX25L6433F_Interface_t;

typedef enum {
  MX25L6433F_ERASE_4K = 0,                                    /*!< 4K size Sector erase                          */
  MX25L6433F_ERASE_32K,                                       /*!< 32K size Block erase                          */
  MX25L6433F_ERASE_64K,                                       /*!< 64K size Block erase                          */
  MX25L6433F_ERASE_CHIP                                       /*!< Whole chip erase                              */
} MX25L6433F_Erase_t;

typedef struct
{
  /* Control functions */
  int32_t (*Init                    )(MX25L6433F_Object_t*);
  int32_t (*DeInit                  )(MX25L6433F_Object_t*);
  int32_t (*ReadID                  )(MX25L6433F_Object_t*, uint8_t*);
  int32_t (*GetFlashInfo            )(MX25L6433F_Info_t*);
  int32_t (*Read                    )(MX25L6433F_Object_t*, MX25L6433F_Interface_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*ReadDMA                 )(MX25L6433F_Object_t*, MX25L6433F_Interface_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*Program                 )(MX25L6433F_Object_t*, MX25L6433F_Interface_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*ProgramDMA              )(MX25L6433F_Object_t*, MX25L6433F_Interface_t, uint8_t*, uint32_t, uint32_t);
  int32_t (*BlockErase              )(MX25L6433F_Object_t*, uint32_t, MX25L6433F_Erase_t);
  int32_t (*ChipErase               )(MX25L6433F_Object_t*);
  int32_t (*EnableMemoryMappedMode  )(MX25L6433F_Object_t*, MX25L6433F_Interface_t);
  int32_t (*ResetEnable             )(MX25L6433F_Object_t*);
  int32_t (*ResetMemory             )(MX25L6433F_Object_t*);
} MX25L6433F_MEM_Drv_t;

/**
  * @}
  */

/** @defgroup ST7789H2_Exported_Variables MX25L6433F Exported Variables
  * @{
  */
extern const MX25L6433F_MEM_Drv_t MX25L6433F_MEM_Driver;
/**
  * @}
  */

/** @defgroup MX25L6433F_Exported_Functions MX25L6433F Exported Functions
  * @{
  */
/* Function by commands combined */
int32_t MX25L6433F_GetFlashInfo(MX25L6433F_Info_t *pInfo);
int32_t MX25L6433F_AutoPollingMemReady(MX25L6433F_Object_t *pObj);

/* Read/Write Array Commands **************************************************/
int32_t MX25L6433F_RegisterBusIO(MX25L6433F_Object_t *pObj, MX25L6433F_IO_t *pIO);
int32_t MX25L6433F_Init(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_DeInit(MX25L6433F_Object_t *pObj);

int32_t MX25L6433F_Read(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t MX25L6433F_ReadDMA(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t MX25L6433F_PageProgram(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t MX25L6433F_PageProgramDMA(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t MX25L6433F_BlockErase(MX25L6433F_Object_t *pObj, uint32_t BlockAddress, MX25L6433F_Erase_t BlockSize);
int32_t MX25L6433F_ChipErase(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_DisableQuadMode(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_EnableQuadMode(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_EnableMemoryMappedMode(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode);
int32_t MX25L6433F_Suspend(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_Resume(MX25L6433F_Object_t *pObj);

/* Register/Setting Commands **************************************************/
int32_t MX25L6433F_WriteEnable(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_WriteDisable(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_ReadStatusRegister(MX25L6433F_Object_t *pObj, uint8_t *Value);
int32_t MX25L6433F_WriteStatusRegister(MX25L6433F_Object_t *pObj, uint8_t Value);
int32_t MX25L6433F_WriteCfgRegister(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t Value);
int32_t MX25L6433F_ReadCfgRegister(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *Value);
int32_t MX25L6433F_WriteCfg2Register(MX25L6433F_Object_t *pObj, uint8_t Value);
int32_t MX25L6433F_ReadCfg2Register(MX25L6433F_Object_t *pObj, uint8_t *Value);
int32_t MX25L6433F_WriteSecurityRegister(MX25L6433F_Object_t *pObj, uint8_t Value);
int32_t MX25L6433F_ReadSecurityRegister(MX25L6433F_Object_t *pObj, uint8_t *Value);

/* ID/Security Commands *******************************************************/
int32_t MX25L6433F_ReadID(MX25L6433F_Object_t *pObj, uint8_t *ID);

/* Reset Commands *************************************************************/
int32_t MX25L6433F_ResetEnable(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_ResetMemory(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_NoOperation(MX25L6433F_Object_t *pObj);
int32_t MX25L6433F_EnterPowerDown(MX25L6433F_Object_t *pObj);

int32_t MX25L6433F_Delay(uint32_t Delay);

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

#endif /* MX25L6433F_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
