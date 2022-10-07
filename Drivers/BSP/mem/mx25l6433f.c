/**
 ******************************************************************************
 * @file    mx25l6433f.c
 * @modify  MCD Application Team
 * @brief   This file provides the MX25L6433F QSPI driver.
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

/* Includes ------------------------------------------------------------------*/
#include "mx25l6433f.h"
#include "mem_conf.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @defgroup MX25L6433F MX25L6433F
  * @{
  */

/** @defgroup MX25L6433F_Exported_Variables MX25L6433F Exported Variables
  * @{
  */
const MX25L6433F_MEM_Drv_t MX25L6433F_MEM_Driver =
{
  MX25L6433F_Init,
  MX25L6433F_DeInit,
  MX25L6433F_ReadID,
  MX25L6433F_GetFlashInfo,
  MX25L6433F_Read,
  MX25L6433F_ReadDMA,
  MX25L6433F_PageProgram,
  MX25L6433F_PageProgramDMA,
  MX25L6433F_BlockErase,
  MX25L6433F_ChipErase,
  NULL, /* EnableMemoryMappedMode */
  MX25L6433F_ResetEnable,
  MX25L6433F_ResetMemory
};

/** @defgroup MX25L6433F_Exported_Functions MX25L6433F Exported Functions
  * @{
  */
/**
  * @brief  Register component IO bus
  * @param  pObj Component object pointer
  * @param  pIO  Component IO structure pointer
  * @retval Component status
  */
int32_t MX25L6433F_RegisterBusIO(MX25L6433F_Object_t *pObj, MX25L6433F_IO_t *pIO)
{
  int32_t ret;

  if(pObj == NULL)
  {
    ret = MX25L6433F_ERROR;
  }
  else
  {
    pObj->IO.Init         = pIO->Init;
    pObj->IO.DeInit       = pIO->DeInit;
    pObj->IO.Address      = pIO->Address;
    pObj->IO.SendData     = pIO->SendData;
    pObj->IO.SendDataDMA  = pIO->SendDataDMA;
    pObj->IO.RecvData     = pIO->RecvData;
    pObj->IO.RecvDataDMA  = pIO->RecvDataDMA;
    pObj->IO.GetTick      = pIO->GetTick;

    if(pObj->IO.Init != NULL)
    {
      ret = pObj->IO.Init();
    }
    else
    {
      ret = MX25L6433F_ERROR;
    }
  }

  return ret;
}

/**
  * @brief  Initialize the MX25L6433F device
  * @param  Ctx Component object pointer
  * @retval error status
  */
int32_t MX25L6433F_Init(MX25L6433F_Object_t *pObj)
{
  int32_t ret = MX25L6433F_OK;

  if(pObj == NULL)
  {
    ret = MX25L6433F_ERROR;
  }
  else if (pObj->IsInitialized == 0)
  {
    pObj->IsInitialized = 1;
    
    /* Nothing to do in SPI mode */
  }

  return ret;
}

/**
  * @brief  De-Initialize the ili9341 LCD Component.
  * @param  pObj Component object
  * @retval Component status
  */
int32_t MX25L6433F_DeInit(MX25L6433F_Object_t *pObj)
{
  return pObj->IO.DeInit();
}

/**
  * @brief  Get Flash information
  * @param  pInfo pointer to information structure
  * @retval error status
  */
int32_t MX25L6433F_GetFlashInfo(MX25L6433F_Info_t *pInfo)
{
  /* Configure the structure with the memory configuration */
  pInfo->FlashSize              = MX25L6433F_FLASH_SIZE;
  pInfo->EraseBlockSize         = MX25L6433F_BLOCK_64K;
  pInfo->EraseBlocksNumber      = (MX25L6433F_FLASH_SIZE/MX25L6433F_BLOCK_64K);
  pInfo->EraseSubBlockSize      = MX25L6433F_BLOCK_32K;
  pInfo->EraseSubBlocksNumber   = (MX25L6433F_FLASH_SIZE/MX25L6433F_BLOCK_32K);
  pInfo->EraseSectorSize        = MX25L6433F_SECTOR_4K;
  pInfo->EraseSectorsNumber     = (MX25L6433F_FLASH_SIZE/MX25L6433F_SECTOR_4K);
  pInfo->ProgPageSize           = MX25L6433F_PAGE_SIZE;
  pInfo->ProgPagesNumber        = (MX25L6433F_FLASH_SIZE/MX25L6433F_PAGE_SIZE);

  return MX25L6433F_OK;
};

/* Read/Write Array Commands ****************************************************/
/**
  * @brief  Reads an amount of data from the QSPI memory.
  *         SPI/DUAL_OUT/DUAL_INOUT/QUAD_OUT/QUAD_INOUT/; 1-1-1/1-1-2/1-2-2/1-1-4/1-4-4
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @param  pData Pointer to data to be read
  * @param  ReadAddr Read start address
  * @param  Size Size of data to read
  * @retval QSPI memory status
  */
int32_t MX25L6433F_Read(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
{
  int32_t ret = MX25L6433F_OK;

  switch(Mode)
  {
    case MX25L6433F_SPI_MODE :
      ret = pObj->IO.RecvData(pData, ReadAddr, Size);
      break;

    case MX25L6433F_DUAL_OUT_MODE :
    case MX25L6433F_DUAL_IO_MODE :
    case MX25L6433F_QUAD_OUT_MODE :
    case MX25L6433F_QUAD_IO_MODE :
    default :
      return MX25L6433F_ERROR;
  }

  return ret;
}

/**
  * @brief  Reads an amount of data using DMA from the QSPI memory.
  *         SPI/DUAL_OUT/DUAL_INOUT/QUAD_OUT/QUAD_INOUT/; 1-1-1/1-1-2/1-2-2/1-1-4/1-4-4
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @param  pData Pointer to data to be read
  * @param  ReadAddr Read start address
  * @param  Size Size of data to read
  * @retval QSPI memory status
  */
int32_t MX25L6433F_ReadDMA(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
{
  int32_t ret = MX25L6433F_OK;

  switch(Mode)
  {
    case MX25L6433F_SPI_MODE :
      ret = pObj->IO.RecvDataDMA(pData, ReadAddr, Size);
      break;

    case MX25L6433F_DUAL_OUT_MODE :
    case MX25L6433F_DUAL_IO_MODE :
    case MX25L6433F_QUAD_OUT_MODE :
    case MX25L6433F_QUAD_IO_MODE :
    default :
      return MX25L6433F_ERROR;
  }

  return ret;
}

/**
  * @brief  Writes an amount of data to the QSPI memory.
  *         SPI/QUAD_INOUT/; 1-1-1/1-4-4
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @param  pData Pointer to data to be written
  * @param  WriteAddr Write start address
  * @param  Size Size of data to write. Range 1 ~ MX25L6433F_PAGE_SIZE
  * @note   Address size is forced to 3 Bytes when the 4 Bytes address size
  *         command is not available for the specified interface mode
  * @retval QSPI memory status
  */
int32_t MX25L6433F_PageProgram(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size)
{
  int32_t ret = MX25L6433F_OK;

  switch(Mode)
  {
    case MX25L6433F_SPI_MODE :
      ret = pObj->IO.SendData(pData, WriteAddr, Size);
      break;

    case MX25L6433F_QUAD_IO_MODE :
    default :
      ret = MX25L6433F_ERROR;
  }

  return ret;
}

/**
  * @brief  Writes an amount of data using DMA to the QSPI memory.
  *         SPI/QUAD_INOUT/; 1-1-1/1-4-4
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @param  pData Pointer to data to be written
  * @param  WriteAddr Write start address
  * @param  Size Size of data to write. Range 1 ~ MX25L6433F_PAGE_SIZE
  * @note   Address size is forced to 3 Bytes when the 4 Bytes address size
  *         command is not available for the specified interface mode
  * @retval QSPI memory status
  */
int32_t MX25L6433F_PageProgramDMA(MX25L6433F_Object_t *pObj, MX25L6433F_Interface_t Mode, uint8_t *pData, uint32_t WriteAddr, uint32_t Size)
{
  int32_t ret = MX25L6433F_OK;

  switch(Mode)
  {
    case MX25L6433F_SPI_MODE :
      ret = pObj->IO.SendDataDMA(pData, WriteAddr, Size);
      break;

    case MX25L6433F_QUAD_IO_MODE :
    default :
      ret = MX25L6433F_ERROR;
  }

  return ret;
}

/**
  * @brief  Erases the specified block of the QSPI memory.
  *         MX25L6433F support 4K, 32K and 64K size block erase commands.
  * @param  Ctx Component object pointer
  * @param  BlockAddress Block address to erase
  * @param  BlockSize Block size to erase
  * @retval QSPI memory status
  */
int32_t MX25L6433F_BlockErase(MX25L6433F_Object_t *pObj, uint32_t BlockAddress, MX25L6433F_Erase_t BlockSize)
{
  int32_t ret = MX25L6433F_OK;

  switch(BlockSize)
  {
    case MX25L6433F_ERASE_4K :
      /* Send the command MX25L6433F_SECTOR_ERASE_CMD */
      // break;
    case MX25L6433F_ERASE_32K :
      /* Send the command MX25L6433F_SUBBLOCK_ERASE_CMD */
      // break;
    case MX25L6433F_ERASE_64K :
      /* Send the command MX25L6433F_BLOCK_ERASE_CMD */
      // break;
    default :
      ret = MX25L6433F_ERROR;	  
  }

  return ret;
}

/**
  * @brief  Whole chip erase.
  * @param  Ctx Component object pointer
  * @param  Mode Interface mode
  * @retval error status
  */
int32_t MX25L6433F_ChipErase(MX25L6433F_Object_t *pObj)
{
  int32_t ret = MX25L6433F_OK;
  
  /* Send the command MX25L6433F_CHIP_ERASE_CMD */
  ret = MX25L6433F_ERROR;

  return ret;
}

/* ID Commands ****************************************************************/
/**
  * @brief  Read Flash 3 Byte IDs.
  *         Manufacturer ID, Memory type, Memory density
  * @param  Ctx Component object pointer
  * @param  ID 3 bytes IDs pointer
  * @retval error status
  */
int32_t MX25L6433F_ReadID(MX25L6433F_Object_t *pObj, uint8_t *ID)
{
  int32_t ret = MX25L6433F_OK;
  
  /* Send the command MX25L6433F_READ_ID_CMD */
  ret = MX25L6433F_ERROR;

  return ret;
}

/* Reset Commands *************************************************************/
/**
  * @brief  Flash reset enable command
  * @param  Ctx Component object pointer
  * @retval error status
  */
int32_t MX25L6433F_ResetEnable(MX25L6433F_Object_t *pObj)
{
  int32_t ret = MX25L6433F_OK;
  
  /* Send the command MX25L6433F_RESET_ENABLE_CMD */
  ret = MX25L6433F_ERROR;

  return ret;
}

/**
  * @brief  Flash reset memory command
  * @param  Ctx Component object pointer
  * @retval error status
  */
int32_t MX25L6433F_ResetMemory(MX25L6433F_Object_t *pObj)
{
  int32_t ret = MX25L6433F_OK;
  
  /* Send the command MX25L6433F_RESET_MEMORY_CMD */
  ret = MX25L6433F_ERROR;

  return ret;
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

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
