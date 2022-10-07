/**
  ******************************************************************************
  * @file    st7789v_reg.c
  * @author  MCD Application Team
  * @brief   This file includes the LCD driver for st7789v LCD.
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
#include "st7789v_reg.h"

/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup Components
  * @{
  */ 
  
/** @addtogroup ST7789V
  * @brief     This file provides a set of functions needed to drive the 
  *            ST7789V LCD controller.
  * @{
  */


  
/** @defgroup ST7789V_Private_Functions ST7789V Private Functions
  * @{
  */   

/**
  * @brief  Read ST7789V component registers
  * @param  ctx component context
  * @param  reg Register to read from
  * @param  pdata Pointer to data buffer
  * @param  length Number of data to read  
  * @retval Component status
  */
int32_t st7789v_read_reg(st7789v_ctx_t *ctx, uint8_t* reg, uint32_t length)
{
  return ctx->ReadReg(ctx->handle, reg, length);
}

/**
  * @brief  Write ST7789V component registers
  * @param  ctx component context
  * @param  reg Register to write to
  * @param  pdata Pointer to data buffer
  * @param  length Number of data to write  
  * @retval Component status
  */
int32_t st7789v_write_reg(st7789v_ctx_t *ctx, uint8_t* reg, uint32_t length)
{
  return ctx->WriteReg(ctx->handle, reg, length);
}

/**
  * @brief  Send data
  * @param  ctx    Component context
  * @param  pdata  data to write
  * @param  Length Length of data to write
  * @retval Component status
  */
int32_t st7789v_send_data(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length)
{
  return ctx->SendData(ctx->handle, pdata, length);
}

/**
  * @brief  Send data using DMA
  * @param  ctx    Component context
  * @param  pdata  data to write
  * @param  Length Length of data to write
  * @retval Component status
  */
int32_t st7789v_send_data_dma(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length)
{
  return ctx->SendDataDMA(ctx->handle, pdata, length);
}

/**
  * @brief  Receive data
  * @param  ctx    Component context
  * @param  pdata  data to read
  * @param  Length Length of data to read
  * @retval Component status
  */
int32_t st7789v_recv_data(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length)
{
  return ctx->RecvData(ctx->handle, pdata, length);
}

/**
  * @brief  Receive data using DMA
  * @param  ctx    Component context
  * @param  pdata  data to read
  * @param  Length Length of data to read
  * @retval Component status
  */
int32_t st7789v_recv_data_dma(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length)
{
  return ctx->RecvDataDMA(ctx->handle, pdata, length);
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
