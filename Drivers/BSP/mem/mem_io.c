/**
  ******************************************************************************
  * File Name          : Target/mem_io.c
  * Description        : This file provides code for the configuration
  *                      of the MEM IO instances.
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
#include "mem_io.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32G0XX_NUCLEO
  * @{
  */

/** @defgroup STM32G0XX_NUCLEO_MEM STM32G0XX_NUCLEO MEM
  * @brief      This file includes the MEM driver of
  *             STM32G0XX_NUCLEO boards.
  * @{
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_Types Private Types
  * @{
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_Constants Private Constants
  * @{
  */
/* Wrap Around value */
#define MEM_WRAP_AROUND_64BYTE                  MX25L6433F_WRAP_AROUND_64BYTE
/* Used Memory Commands */
#define MEM_READ_CMD                            MX25L6433F_READ_CMD
#define MEM_SET_BURST_LENGTH_CMD                MX25L6433F_SET_BURST_LENGTH_CMD

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_Macros Private Macros
  * @{
  */
#define BSP_MEM_CHECK_PARAMS(Instance)

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Exported_Variables Exported Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_Variables Private Variables
  * @{
  */
static void                 *MemCompObj;
static MEM_Drv_t            *MemDrv;
static MX25L6433F_IO_t      IOCtx;
static MX25L6433F_Object_t  ObjCtx;

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_FunctionPrototypes Private Functions
  * @{
  */
static int32_t MEM_Probe(uint32_t Instance);

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Deprecated_Functions Deprecated Functions
  * @{
  */
__INLINE uint8_t BSP_MEM_GetTransfertStatus(uint32_t Instance)
{
  return BSP_MEM_GetTransferStatus(Instance);
}

__WEAK void BSP_MEM_SignalTransfertDone(uint32_t Instance, uint8_t Event)
{
  /* Prevent unused argument(s) compilation warning */;
  UNUSED(Event);
  BSP_MEM_SignalTransferDone(Instance);
}

/** @addtogroup STM32G0XX_NUCLEO_MEM_Exported_Functions
  * @{
  */
/**
  * @brief  Initializes the MEM.
  * @param  Instance    MEM Instance
  * @retval BSP status
  */
int32_t BSP_MEM_Init(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  /* MEM OS Initialize */
  if(MEM_OS_Initialize(0) == MEM_OS_ERROR_NONE)
  {
    /* Reset Handlers */
    MemCompObj = NULL;
    MemDrv = NULL;

    ret = MEM_Probe(Instance);
  }

  return ret;
}

/**
  * @brief  De-Initializes the MEM resources.
  * @param  Instance MEM Instance
  * @retval BSP status
  */
int32_t BSP_MEM_DeInit(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MemDrv->DeInit != NULL)
  {
    if(MemDrv->DeInit(MemCompObj) < 0)
    {
      ret = BSP_ERROR_COMPONENT_FAILURE;
    }
  }
  else
  {
    ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  }

  return ret;
}

/**
  * @brief  Write Data to QuadSPI Memory Interface.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be written
  * @param  Address Memory address to write to
  * @param  Size pointer to Data Memory to be written
  * @retval BSP status
  */
int32_t BSP_MEM_BlockErase(uint32_t Instance, uint32_t BlockAddress, uint32_t BlockSize)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->BlockErase != NULL)
    {
      if(MemDrv->BlockErase(MemCompObj, BlockAddress, BlockSize) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }

    MEM_OS_Unlock(Instance);
  }

  return ret;
}

/**
  * @brief  Write Data to QuadSPI Memory Interface.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be written
  * @param  Address Memory address to write to
  * @param  Size pointer to Data Memory to be written
  * @retval BSP status
  */
int32_t BSP_MEM_ChipErase(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->ChipErase != NULL)
    {
      if(MemDrv->ChipErase(MemCompObj) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }

    MEM_OS_Unlock(Instance);
  }

  return ret;
}

/**
  * @brief  Read Data from Serial Periphiral Memory Interface.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be filled
  * @param  Address Memory address to read from
  * @param  Size pointer to Data Memory to be filled
  * @retval BSP status
  */
int32_t BSP_MEM_ReadData(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->Read != NULL)
    {
      if(MemDrv->Read(MemCompObj, MEM_INTERFACE_MODE, pData, Address, Size) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }

    MEM_OS_Unlock(Instance);
  }

  return ret;
}

/**
  * @brief  Read Data from Serial Periphiral Memory Interface using DMA.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be filled
  * @param  Address Memory address to read from
  * @param  Size pointer to Data Memory to be filled
  * @retval BSP status
  */
int32_t BSP_MEM_ReadDataDMA(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->ReadDMA != NULL)
    {
      if(MemDrv->ReadDMA(MemCompObj, MEM_INTERFACE_MODE, pData, Address, Size) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }
  }

  return ret;
}

/**
  * @brief  Write Data to QuadSPI Memory Interface.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be written
  * @param  Address Memory address to write to
  * @param  Size pointer to Data Memory to be written
  * @retval BSP status
  */
int32_t BSP_MEM_WriteData(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->Program != NULL)
    {
      if(MemDrv->Program(MemCompObj, MEM_INTERFACE_MODE, pData, Address, Size) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }

    MEM_OS_Unlock(Instance);
  }

  return ret;
}

/**
  * @brief  Write Data to QuadSPI Memory Interface using DMA.
  * @param  Instance MEM Instance
  * @param  pData pointer to Data Memory to be written
  * @param  Address Memory address to write to
  * @param  Size pointer to Data Memory to be written
  * @retval BSP status
  */
int32_t BSP_MEM_WriteDataDMA(uint32_t Instance, uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->ProgramDMA != NULL)
    {
      if(MemDrv->ProgramDMA(MemCompObj, MEM_INTERFACE_MODE, pData, Address, Size) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }
  }

  return ret;
}

/**
  * @brief  Enable Memory Mapped Mode.
  * @param  Instance MEM Instance
  * @retval Zero if no Transfer, Transfer Operation code otherwise
  */
int32_t BSP_MEM_EnableMemoryMappedMode(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  if(MEM_OS_TryLock(Instance, MEM_OS_NO_WAIT) != MEM_OS_ERROR_NONE)
  {
    ret = BSP_ERROR_BUSY;
  }
  else
  {
    if(MemDrv->EnableMemoryMappedMode != NULL)
    {
      if(MemDrv->EnableMemoryMappedMode(MemCompObj, MEM_INTERFACE_MODE) < 0)
      {
        ret = BSP_ERROR_COMPONENT_FAILURE;
      }
    }
    else
    {
      ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
    }
  }

  return ret;
}

/**
  * @brief  Get the status of the SPI Transfer.
  * @param  Instance MEM Instance
  * @retval Zero if no Transfer, Transfer Operation code otherwise
  */
uint8_t BSP_MEM_GetTransferStatus(uint32_t Instance)
{
  BSP_MEM_CHECK_PARAMS(Instance);

  return MEM_OS_IsLocked(Instance);
}

/**
  * @brief  Wait for until complete SPI Transfer.
  * @param  Instance MEM Instance
  * @retval None
  */
void BSP_MEM_WaitForTransferToBeDone(uint32_t Instance)
{
  if (Instance < MEM_INSTANCES_NBR)
  {
    MEM_OS_WaitForTransferToBeDone(Instance);
  }
}

/**
  * @brief  Signal Transfer Event.
  * @param  Instance MEM Instance
  * @retval None
  */
__weak void BSP_MEM_SignalTransferDone(uint32_t Instance)
{
  /* This is the user's Callback to be implemented at the application level */
}

/**
  * @}
  */

/** @defgroup STM32G0XX_NUCLEO_MEM_Private_Functions Private Functions
  * @{
  */
/** @defgroup SPI Driver for external memory interface
  * @{
  */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  /**
  * @brief  Transfer Read Complete CallBack
  * @param  hspi SPI Handler
  */
static void SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
  if(hspi == ObjCtx.handle)
  {
    /* Set the nCS */
    MEM_CS_HIGH();

    /* Unlock MEM ressources */
    MEM_OS_UnlockFromISR(0);

    /* Signal Transfer Done Event */
    BSP_MEM_SignalTransferDone(0);
  }
}
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

/**
  * @brief  Set Burst Read length
  * @param  burstconfig  Burst length
  */
static int32_t MEM_SetBurstReadLength( uint8_t burstconfig )
{
  int32_t ret = BSP_ERROR_NONE;

  uint8_t cmd[2] = { MEM_SET_BURST_LENGTH_CMD
                   , burstconfig
                   };

  // Chip select go low to start a flash command
  MEM_CS_LOW();

  // Send SBL command and config data
  ret = MEM_SPI_Send( cmd, 2 );

  // Chip select go high to end a flash command
  MEM_CS_HIGH();

  return ret;
}

/**
  * @brief  Software Reset
  * @param  None
  */
static int32_t MEM_SoftwareReset( void )
{
  int32_t ret = BSP_ERROR_NONE;
  uint8_t cmd;

  MEM_CS_LOW();
  cmd = MX25L6433F_RESET_ENABLE_CMD;
  ret = MEM_SPI_Send( &cmd, 1 );
  MEM_CS_HIGH();

  if(ret == BSP_ERROR_NONE)
  {
    MEM_CS_LOW();
    cmd = MX25L6433F_RESET_MEMORY_CMD;
    ret = MEM_SPI_Send( &cmd, 1 );
    MEM_CS_HIGH();
    HAL_Delay(20);
  }

  return ret;
}

/**
  * @brief  Initializes MEM low level.
  * @retval BSP status
  */
static int32_t MEM_IO_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  ret = MEM_SPI_Init();

  if(ret == BSP_ERROR_NONE)
  {
    ret = MEM_SoftwareReset();
  }

  if(ret == BSP_ERROR_NONE)
  {
    /* MEM Initialization */
    MemCompObj = &ObjCtx;
    MemDrv = (MEM_Drv_t *)&MX25L6433F_MEM_Driver;
    ObjCtx.IsInitialized = 0;

    if(MemDrv->Init(MemCompObj) < 0)
    {
      ret = BSP_ERROR_COMPONENT_FAILURE;
    }
  }

  if(ret == BSP_ERROR_NONE)
  {
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    HAL_SPI_RegisterCallback((SPI_HandleTypeDef *)ObjCtx.handle, HAL_SPI_RX_COMPLETE_CB_ID, SPI_RxCpltCallback);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

    /* Enable Burst Read - 64-bytes */
    ret = MEM_SetBurstReadLength(MEM_WRAP_AROUND_64BYTE);
  }

  return ret;
}

/**
  * @brief  DeInitializes MEM low level
  * @retval BSP status
  */
static int32_t MEM_IO_DeInit(void)
{
  int32_t ret = BSP_ERROR_NONE;

  BSP_MEM_CHECK_PARAMS(Instance);

  ret = MEM_SPI_DeInit();

  return ret;
}

/**
  * @brief  Send data to the selected Memory at specified Address.
  * @param  pData  pointer to data to write to the the specified address memory.
  * @param  Address Memory address to be filled
  * @param  Size length of data to write to the the specified address memory
  * @retval BSP status
  */
static int32_t MEM_IO_SendData(uint8_t *pData, uint32_t Address, uint32_t Size)
{
  return BSP_ERROR_FEATURE_NOT_SUPPORTED;
}

/**
  * @brief  Send data using DMA to the selected Memory at specified Address.
  * @param  pData  pointer to data to write to the the specified address memory.
  * @param  Address Memory address to be filled
  * @param  Size length of data to write to the the specified address memory
  * @retval BSP status
  */
static int32_t MEM_IO_SendDataDMA(uint8_t *pData, uint32_t Address, uint32_t Size)
{
  return BSP_ERROR_FEATURE_NOT_SUPPORTED;
}

/**
  * @brief  Read Data from Serial Periphiral Memory Interface.
  * @param  pData pointer to Data Memory to be filled
  * @param  Address Memory address to read from
  * @param  Size pointer to Data Memory to be filled
  * @retval BSP status
  */
static int32_t MEM_IO_RecvData(uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;
  uint8_t cmd[4] = { MEM_READ_CMD
                   , ((Address >> 16) & 0xFF)
                   , ((Address >>  8) & 0xFF)
                   , (Address & 0xFF)
                   };

  /* Reset the nCS pin */
  MEM_CS_LOW();

  ret = MEM_SPI_Send(cmd, 4);
  if(ret == BSP_ERROR_NONE)
  {
    ret = MEM_SPI_Recv(pData, Size);
  }

  /* Set the nCS */
  MEM_CS_HIGH();

  return ret;
}

/**
  * @brief  Read Data from Serial Periphiral Memory Interface using DMA.
  * @param  pData pointer to Data Memory to be filled
  * @param  Address Memory address to read from
  * @param  Size pointer to Data Memory to be filled
  * @retval BSP status
  */
static int32_t MEM_IO_RecvDataDMA(uint8_t *pData, uint32_t Address, uint32_t Size)
{
  int32_t ret = BSP_ERROR_NONE;
  uint8_t cmd[4] = { MEM_READ_CMD
                   , ((Address >> 16) & 0xFF)
                   , ((Address >>  8) & 0xFF)
                   , (Address & 0xFF)
                   };

  /* Reset the nCS pin */
  MEM_CS_LOW();

  ret = MEM_SPI_Send(cmd, 4);
  if(ret == BSP_ERROR_NONE)
  {
    ret = MEM_SPI_Recv_DMA(pData, Size);
  }

  return ret;
}

/**
  * @brief  Register Bus IOs for instance 0 if MX25L6433F ID is OK
  * @param  Instance    MEM Instance
  * @retval BSP status
  */
static int32_t MEM_Probe(uint32_t Instance)
{
  int32_t ret = BSP_ERROR_NONE;

  /* Configure the lcd driver : map to MEM_IO function*/
  IOCtx.Init              = MEM_IO_Init;
  IOCtx.DeInit            = MEM_IO_DeInit;
  IOCtx.SendData          = MEM_IO_SendData;
  IOCtx.SendDataDMA       = MEM_IO_SendDataDMA;
  IOCtx.RecvData          = MEM_IO_RecvData;
  IOCtx.RecvDataDMA       = MEM_IO_RecvDataDMA;

  /* Set Base Address */
  IOCtx.Address           = MEM_BASE_ADDRESS;

  /* Register OSPI handle */
  ObjCtx.handle           = &hMEMSPI;

  if(MX25L6433F_RegisterBusIO(&ObjCtx, &IOCtx) != MX25L6433F_OK)
  {
    ret = BSP_ERROR_COMPONENT_FAILURE;
  }

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

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
