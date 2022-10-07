/**
  ******************************************************************************
  * @file    st7789v.c
  * @author  MCD Application Team
  * @brief   This file includes the drivers for ST7789V LCD controller
  *
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
#include "st7789v.h"
#include "lcd_conf.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup ST7789V
  * @brief      This file provides a set of functions needed to drive the
  *             ST7789V LCD controller.
  * @{
  */

/** @defgroup ST7789V_Private_Types Private Types
  * @{
  */
typedef struct
{
  uint32_t        Width;
  uint32_t        Height;
  uint32_t        Orientation;
} ST7789V_Ctx_t;
/**
  * @}
  */

/** @defgroup ST7789V_Private_Variables Private Variables
  * @{
  */
ST7789V_LCD_Drv_t   ST7789V_LCD_Driver =
{
  ST7789V_Init,
  ST7789V_DeInit,
  ST7789V_ReadID,
  ST7789V_DisplayOn,
  ST7789V_DisplayOff,
  ST7789V_SetDisplayWindow,
  NULL, // ST7789V_SetBrightness,
  NULL, // ST7789V_GetBrightness,
  ST7789V_SetOrientation,
  ST7789V_GetOrientation,
  NULL, // ST7789V_SetCursor,
  NULL, // ST7789V_DrawBitmap,
  NULL, // ST7789V_FillRGBRect,
  NULL, // ST7789V_DrawHLine,
  NULL, // ST7789V_DrawVLine,
  NULL, // ST7789V_FillRect,
  NULL, // ST7789V_GetPixel,
  NULL, // ST7789V_SetPixel,
  ST7789V_GetXSize,
  ST7789V_GetYSize,
};

/* The below table handle the different values to be set to Memory Data Access Control
   depending on the orientation and pbm image writing where the data order is inverted
*/
static uint32_t OrientationTab[4] =
{
  0x00U , /* Portrait orientation choice of LCD screen               */
  0xC0U , /* Portrait rotated 180° orientation choice of LCD screen  */
  0xA0U , /* Landscape orientation choice of LCD screen              */
  0x60U , /* Landscape rotated 180° orientation choice of LCD screen */
};

static ST7789V_Ctx_t ST7789VCtx;
/**
  * @}
  */

/** @defgroup ST7789V_Private_FunctionsPrototypes Private Functions Prototypes
  * @{
  */
static int32_t ST7789V_ReadRegWrap(void *Handle, uint8_t* Reg, uint32_t Length);
static int32_t ST7789V_WriteRegWrap(void *Handle, uint8_t* Reg, uint32_t Length);
static int32_t ST7789V_SendDataWrap(void *Handle, uint8_t *pData, uint32_t Length);
static int32_t ST7789V_SendDataDMAWrap(void *Handle, uint8_t *pData, uint32_t Length);
static int32_t ST7789V_RecvDataWrap(void *Handle, uint8_t *pData, uint32_t Length);
static int32_t ST7789V_RecvDataDMAWrap(void *Handle, uint8_t *pData, uint32_t Length);
static int32_t ST7789V_Delay(ST7789V_Object_t *pObj, uint32_t Delay);
/**
* @}
*/

/** @addtogroup ST7789V_Exported_Functions
  * @{
  */
/**
  * @brief  Register component IO bus
  * @param  pObj Component object pointer
  * @param  pIO  Component IO structure pointer
  * @retval Component status
  */
int32_t ST7789V_RegisterBusIO (ST7789V_Object_t *pObj, ST7789V_IO_t *pIO)
{
  int32_t ret;

  if(pObj == NULL)
  {
    ret = ST7789V_ERROR;
  }
  else
  {
    pObj->IO.Init         = pIO->Init;
    pObj->IO.DeInit       = pIO->DeInit;
    pObj->IO.Address      = pIO->Address;
    pObj->IO.WriteReg     = pIO->WriteReg;
    pObj->IO.ReadReg      = pIO->ReadReg;
    pObj->IO.SendData     = pIO->SendData;
    pObj->IO.SendDataDMA  = pIO->SendDataDMA;
    pObj->IO.RecvData     = pIO->RecvData;
    pObj->IO.RecvDataDMA  = pIO->RecvDataDMA;
    pObj->IO.GetTick      = pIO->GetTick;

    pObj->Ctx.ReadReg     = ST7789V_ReadRegWrap;
    pObj->Ctx.WriteReg    = ST7789V_WriteRegWrap;
    pObj->Ctx.SendData    = ST7789V_SendDataWrap;
    pObj->Ctx.SendDataDMA = ST7789V_SendDataDMAWrap;
    pObj->Ctx.RecvData    = ST7789V_RecvDataWrap;
    pObj->Ctx.RecvDataDMA = ST7789V_RecvDataDMAWrap;
    pObj->Ctx.handle      = pObj;

    if(pObj->IO.Init != NULL)
    {
      ret = pObj->IO.Init();
    }
    else
    {
      ret = ST7789V_ERROR;
    }
  }

  return ret;
}

/**
  * @brief  Initialize the st7789v LCD Component.
  * @param  pObj Component object
  * @param  pInitParams Initialization Parameters
  * @retval Component status
  */
int32_t ST7789V_Init(ST7789V_Object_t *pObj, ST7789V_InitParams_t* pInitParams)
{
  uint8_t i;
  uint8_t parameter[15];
  uint8_t reg;
  int32_t ret = ST7789V_OK;

  if((pObj == NULL) || (pInitParams->Orientation > ST7789V_ORIENTATION_LANDSCAPE_ROT180))
  {
    ret = ST7789V_ERROR;
  }
  else if (pObj->IsInitialized == 0)
  {
    /* Sleep In Command */
    reg = ST7789V_SPLIN;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    /* Wait for 10ms */
    ST7789V_Delay(pObj, 10);

    /* SW Reset Command */
    reg = ST7789V_SWRESET;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    /* Wait for 200ms */
    ST7789V_Delay(pObj, 200);

    /* Sleep Out Command */
    reg = ST7789V_SLEEP_OUT;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    /* Wait for 120ms */
    ST7789V_Delay(pObj, 120);

    /* Display Normal mode Command */
    reg = ST7789V_NORMAL_MODE_ON;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    /* Wait for 100ms */
    ST7789V_Delay(pObj, 100);

    /* RAM Control Command */
    reg = ST7789V_RAM_CTRL;
    parameter[0] = 0x00;
    if(pInitParams->Endian == ST7789V_ENDIAN_LITTLE)
    {
      parameter[1] = 0xF8;
    }
    else
    {
      parameter[1] = 0xF0;
    }
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 2);

    if(pInitParams->SwapRB)
    {
      for(i = 0; i < 4; i++)
      {
        OrientationTab[i] |= 0x08;
      }

      /* LCM Control Command */
      reg = ST7789V_LCM_CTRL;
      parameter[0] = 0x0C;
      ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
      ret += st7789v_send_data(&pObj->Ctx, parameter, 1);
    }

    /* Set Display Orientation */
    ret += ST7789V_SetOrientation(pObj, pInitParams->Orientation);

    /* Set Full Screen Display Window */
    ret += ST7789V_SetDisplayWindow(pObj, 0U, 0U, ST7789V_WIDTH, ST7789V_HEIGHT);

    /* Set Pixel Format */
    reg = ST7789V_PIXEL_FORMAT;
    parameter[0] = (uint8_t) pInitParams->ColorCoding;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /* Frame Rate Control in normal mode */
    reg = ST7789V_FRAME_RATE_CTRL2;
    parameter[0] = 0x0F; /* Default is 60 Hz */
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /* PORCH control setting */
    reg = ST7789V_PORCH_CTRL;
    parameter[0] = 0x0C;
    parameter[1] = 0x0C;
    parameter[2] = 0x00;
    parameter[3] = 0x33;
    parameter[4] = 0x33;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 5);

    /* GATE control setting */
    reg = ST7789V_GATE_CTRL;
    parameter[0] = 0x35;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /*--------------- ST7789H2 Power setting ---------------------------------*/
    /* VCOM setting */
    reg = ST7789V_VCOM_SET;
    parameter[0] = 0x1F;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /* LCM Control setting */
    reg = ST7789V_LCM_CTRL;
    parameter[0] = 0x2C;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /* VDV and VRH Command Enable */
    reg = ST7789V_VDV_VRH_EN;
    parameter[0] = 0x01;
    parameter[1] = 0xC3;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 2);

    /* VDV Set */
    reg = ST7789V_VDV_SET;
    parameter[0] = 0x20;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 1);

    /* Power Control */
    reg = ST7789V_POWER_CTRL;
    parameter[0] = 0xA4;
    parameter[1] = 0xA1;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 2);

    /*--------------- ST7789H2 Gamma setting ---------------------------------*/
    /* Positive Voltage Gamma Control */
    reg = ST7789V_PV_GAMMA_CTRL;
    parameter[0]  = 0xD0;
    parameter[1]  = 0x08;
    parameter[2]  = 0x11;
    parameter[3]  = 0x08;
    parameter[4]  = 0x0C;
    parameter[5]  = 0x15;
    parameter[6]  = 0x39;
    parameter[7]  = 0x33;
    parameter[8]  = 0x50;
    parameter[9]  = 0x36;
    parameter[10] = 0x13;
    parameter[11] = 0x14;
    parameter[12] = 0x29;
    parameter[13] = 0x2D;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 14);

    /* Negative Voltage Gamma Control */
    reg = ST7789V_NV_GAMMA_CTRL;
    parameter[0]  = 0xD0;
    parameter[1]  = 0x08;
    parameter[2]  = 0x10;
    parameter[3]  = 0x08;
    parameter[4]  = 0x06;
    parameter[5]  = 0x06;
    parameter[6]  = 0x39;
    parameter[7]  = 0x44;
    parameter[8]  = 0x51;
    parameter[9]  = 0x0B;
    parameter[10] = 0x16;
    parameter[11] = 0x14;
    parameter[12] = 0x2F;
    parameter[13] = 0x31;
    ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
    ret += st7789v_send_data(&pObj->Ctx, parameter, 14);

    if(pInitParams->TEMode == ST7789V_TE_MODE_1)
    {
      // Set TE scan line
      reg = ST7789V_SET_TEAR_SCANLINE;
      ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
      parameter[0] = (pInitParams->TEScanline & 0x100);
      parameter[1] = (pInitParams->TEScanline & 0x0FF);
      ret += st7789v_send_data(&pObj->Ctx, parameter, 2);

      reg = ST7789V_TEON;
      parameter[0] = 0x00; /* VSYNC Only */
      ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
      ret += st7789v_send_data(&pObj->Ctx, parameter, 1);
    }
    else if(pInitParams->TEMode == ST7789V_TE_MODE_2)
    {
      // Reset TE scan line
      reg = ST7789V_SET_TEAR_SCANLINE;
      ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
      parameter[0] = 0;
      parameter[1] = 0;
      ret += st7789v_send_data(&pObj->Ctx, parameter, 2);

      // Enable TE
      reg = ST7789V_TEON;
      parameter[0] = 0x01; /* VSYNC + HSYNC */
      ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
      ret += st7789v_send_data(&pObj->Ctx, parameter, 1);
    }

    pObj->IsInitialized = 1U;
  }

  if(ret != ST7789V_OK)
  {
    ret = ST7789V_ERROR;
  }

  return ret;
}

/**
  * @brief  De-Initialize the st7789v LCD Component.
  * @param  pObj Component object
  * @retval Component status
  */
int32_t ST7789V_DeInit(ST7789V_Object_t *pObj)
{
  return pObj->IO.DeInit();
}

/**
  * @brief  Get the st7789v ID.
  * @param  pObj Component object
  * @param  Id Component ID
  * @retval The component status
  */
int32_t ST7789V_ReadID(ST7789V_Object_t *pObj, uint32_t *Id)
{
  int32_t ret;
  uint8_t data[4] = {ST7789V_READ_DISPLAY_ID, 0, 0, 0 };

  if(st7789v_recv_data(&pObj->Ctx, data, 4) != ST7789V_OK)
  {
    ret = ST7789V_ERROR;
  }
  else
  {
    *Id = ((data[1] << 16) | (data[2] << 8) | data[3]);
    if(*Id != ST7789V_ID)
    {
      data[0] <<= 1;
      if(data[1] & 0x80)
        data[0] |= 1;
      data[1] <<= 1;
      if(data[2] & 0x80)
        data[1] |= 1;
      data[2] <<= 1;
      if(data[3] & 0x80)
        data[2] |= 1;

      *Id = ((data[0] << 16) | (data[1] << 8) | data[2]);
    }
    ret = ST7789V_OK;
  }

  return ret;
}

/**
  * @brief  Enables the Display.
  * @param  pObj Component object
  * @retval The component status
  */
int32_t ST7789V_DisplayOn(ST7789V_Object_t *pObj)
{
  uint8_t reg = ST7789V_DISPLAY_ON;

  return st7789v_write_reg(&pObj->Ctx, &reg, 1);
}

/**
  * @brief  Disables the Display.
  * @param  pObj Component object
  * @retval The component status
  */
int32_t ST7789V_DisplayOff(ST7789V_Object_t *pObj)
{
  uint8_t reg = ST7789V_DISPLAY_OFF;

  return st7789v_write_reg(&pObj->Ctx, &reg, 1);
}

/**
  * @brief  Set the Display Orientation.
  * @param  pObj Component object
  * @param  Orientation ST7789V_ORIENTATION_PORTRAIT, ST7789V_ORIENTATION_PORTRAIT_ROT180
  *                     ST7789V_ORIENTATION_LANDSCAPE or ST7789V_ORIENTATION_LANDSCAPE_ROT180
  * @retval The component status
  */
int32_t ST7789V_SetOrientation(ST7789V_Object_t *pObj, uint32_t Orientation)
{
  int32_t ret;
  uint8_t parameter, reg;

  parameter = (uint8_t)OrientationTab[Orientation];
  reg = ST7789V_MAC;
  ret = st7789v_write_reg(&pObj->Ctx, &reg, 1);
  ret += st7789v_send_data(&pObj->Ctx, &parameter, 1);

  if(ret == ST7789V_OK)
  {
    ST7789VCtx.Orientation = Orientation;

    switch (Orientation)
    {
      case ST7789V_ORIENTATION_LANDSCAPE:
      case ST7789V_ORIENTATION_LANDSCAPE_ROT180:
        ST7789VCtx.Width  = ST7789V_HEIGHT;
        ST7789VCtx.Height = ST7789V_WIDTH;
      break;
      default:
      case ST7789V_ORIENTATION_PORTRAIT_ROT180:
      case ST7789V_ORIENTATION_PORTRAIT:
        ST7789VCtx.Width  = ST7789V_WIDTH;
        ST7789VCtx.Height = ST7789V_HEIGHT;
      break;
    }

    pObj->XSize = ST7789VCtx.Width;
    pObj->YSize = ST7789VCtx.Height;
  }
  else
  {
    ret = ST7789V_ERROR;
  }

  return ret;
}

/**
  * @brief  Set the Display Orientation.
  * @param  pObj Component object
  * @param  Orientation pointer to the LCD orientation
  * @retval The component status
  */
int32_t ST7789V_GetOrientation(ST7789V_Object_t *pObj, uint32_t *Orientation)
{
  (void)pObj;

  *Orientation = ST7789VCtx.Orientation;

  return ST7789V_OK;
}

/**
  * @brief  Get the LCD pixel Width.
  * @param  pObj Component object
  * @retval The Lcd Pixel Width
  */
int32_t ST7789V_GetXSize(ST7789V_Object_t *pObj, uint32_t *XSize)
{
  (void)pObj;

  *XSize = ST7789VCtx.Width;

  return ST7789V_OK;
}

/**
  * @brief  Get the LCD pixel Height.
  * @param  pObj Component object
  * @retval The Lcd Pixel Height
  */
int32_t ST7789V_GetYSize(ST7789V_Object_t *pObj, uint32_t *YSize)
{
  (void)pObj;

  *YSize = ST7789VCtx.Height;

  return ST7789V_OK;
}

/**
  * @brief  Sets a display window
  * @param  Xpos   specifies the X bottom left position.
  * @param  Ypos   specifies the Y bottom left position.
  * @param  Height display window height.
  * @param  Width  display window width.
  * @retval Component status
  */
int32_t ST7789V_SetDisplayWindow(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height)
{
  int32_t ret;
  uint8_t parameter[4];
  uint8_t reg = ST7789V_CASET;

  /* Column addr set, 4 args, no delay: XSTART = Xpos, XEND = (Xpos + Width - 1) */
  ret = st7789v_write_reg(&pObj->Ctx, &reg, 1);
  parameter [0] = (uint8_t)(Xpos >> 8U);
  parameter [1] = (uint8_t)(Xpos & 0xFFU);
  parameter [2] = (uint8_t)((Xpos + Width - 1U) >> 8U);
  parameter [3] = (uint8_t)((Xpos + Width - 1U) & 0xFFU);
  ret += st7789v_send_data(&pObj->Ctx, parameter, 4);

  /* Row addr set, 4 args, no delay: YSTART = Ypos, YEND = (Ypos + Height - 1) */
  reg = ST7789V_RASET;
  ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);
  parameter [0] = (uint8_t)(Ypos >> 8U);
  parameter [1] = (uint8_t)(Ypos & 0xFFU);
  parameter [2] = (uint8_t)((Ypos + Height - 1U) >> 8U);
  parameter [3] = (uint8_t)((Ypos + Height - 1U) & 0xFFU);
  ret += st7789v_send_data(&pObj->Ctx, parameter, 4);

  reg = ST7789V_GRAM;
  ret += st7789v_write_reg(&pObj->Ctx, &reg, 1);

  if(ret != ST7789V_OK)
  {
    ret = ST7789V_ERROR;
  }

  return ret;
}

/**
  * @}
  */

/** @defgroup ST7789V_Private_Functions  Private Functions
  * @{
  */
/**
  * @brief  Wrap component ReadReg to Bus Read function
  * @param  Handle  Component object handle
  * @param  Reg  The target register address to write
  * @param  pData  The target register value to be written
  * @retval Component error status
  */
static int32_t ST7789V_ReadRegWrap(void *Handle, uint8_t* Reg, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.ReadReg(Reg, Length);
}

/**
  * @brief  Wrap component WriteReg to Bus Write function
  * @param  handle  Component object handle
  * @param  Reg  The target register address to write
  * @param  pData  The target register value to be written
  * @param  Length  buffer size to be written
  * @retval Component error status
  */
static int32_t ST7789V_WriteRegWrap(void *Handle, uint8_t* Reg, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.WriteReg(Reg, Length);
}


/**
  * @brief  Wrap component SendData to Bus Write function
  * @param  handle  Component object handle
  * @param  pData  The target register value to be written
  * @retval Component error status
  */
static int32_t ST7789V_SendDataWrap(void *Handle, uint8_t *pData, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.SendData(pData, Length);
}

/**
  * @brief  Wrap component SendDataDMA to Bus Write function
  * @param  handle  Component object handle
  * @param  pData  The target register value to be written
  * @retval Component error status
  */
static int32_t ST7789V_SendDataDMAWrap(void *Handle, uint8_t *pData, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.SendDataDMA(pData, Length);
}

/**
  * @brief  Wrap component SendData to Bus Write function
  * @param  handle  Component object handle
  * @param  pData  The target register value to be written
  * @retval Component error status
  */
static int32_t ST7789V_RecvDataWrap(void *Handle, uint8_t *pData, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.RecvData(pData, Length);
}

/**
  * @brief  Wrap component SendDataDMA to Bus Write function
  * @param  handle  Component object handle
  * @param  pData  The target register value to be written
  * @retval Component error status
  */
static int32_t ST7789V_RecvDataDMAWrap(void *Handle, uint8_t *pData, uint32_t Length)
{
  ST7789V_Object_t *pObj = (ST7789V_Object_t *)Handle;

  return pObj->IO.RecvDataDMA(pData, Length);
}

/**
  * @brief  ST7789V delay
  * @param  Delay  Delay in ms
  * @retval Component error status
  */
static int32_t ST7789V_Delay(ST7789V_Object_t *pObj, uint32_t Delay)
{
  uint32_t tickstart;
  tickstart = pObj->IO.GetTick();
  while((pObj->IO.GetTick() - tickstart) < Delay)
  {
  }
  return ST7789V_OK;
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
