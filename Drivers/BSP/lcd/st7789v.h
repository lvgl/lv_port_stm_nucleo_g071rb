/**
  ******************************************************************************
  * @file    st7789v.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the st7789v.c
  *          driver.
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
#ifndef ST7789V_H
#define ST7789V_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "st7789v_reg.h"
#include <stddef.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @defgroup ST7789V ST7789V
  * @{
  */

/** @defgroup ST7789V_Exported_Types Exported Types
  * @{
  */
typedef int32_t (*ST7789V_Init_Func)     (void);
typedef int32_t (*ST7789V_DeInit_Func)   (void);
typedef int32_t (*ST7789V_GetTick_Func)  (void);
typedef int32_t (*ST7789V_Delay_Func)    (uint32_t);
typedef int32_t (*ST7789V_WriteReg_Func) (uint8_t*, uint32_t);
typedef int32_t (*ST7789V_ReadReg_Func)  (uint8_t*, uint32_t);
typedef int32_t (*ST7789V_SendData_Func) (uint8_t*, uint32_t);
typedef int32_t (*ST7789V_RecvData_Func) (uint8_t*, uint32_t);

typedef enum
{
  ST7789V_ENDIAN_BIG = 0
, ST7789V_ENDIAN_LITTLE
} ST7789V_Endian_t;

typedef enum
{
  ST7789V_TE_DISABLED = 0
, ST7789V_TE_MODE_1
, ST7789V_TE_MODE_2
} ST7789V_TE_Mode_t;

typedef struct
{
  ST7789V_Init_Func          Init;
  ST7789V_DeInit_Func        DeInit;
  uint16_t                   Address;
  ST7789V_WriteReg_Func      WriteReg;
  ST7789V_ReadReg_Func       ReadReg;
  ST7789V_SendData_Func      SendData;
  ST7789V_SendData_Func      SendDataDMA;
  ST7789V_RecvData_Func      RecvData;
  ST7789V_RecvData_Func      RecvDataDMA;
  ST7789V_GetTick_Func       GetTick;
  ST7789V_Delay_Func         Delay;
} ST7789V_IO_t;

typedef struct
{
  ST7789V_IO_t               IO;
  st7789v_ctx_t              Ctx;
  uint8_t                    IsInitialized;
  uint32_t                   XSize;
  uint32_t                   YSize;
} ST7789V_Object_t;

typedef struct
{
  uint32_t                   hsync;   /* Horizontal synchronization */
  uint32_t                   hbp;     /* Horizontal back porch      */
  uint32_t                   hfp;     /* Horizontal front porch     */
  uint32_t                   vsync;   /* Vertical synchronization   */
  uint32_t                   vbp;     /* Vertical back porch        */
  uint32_t                   vfp;     /* Vertical front porch       */
} ST7789V_TimingParams_t;

typedef struct
{
  ST7789V_Endian_t           Endian;
  uint32_t                   SwapRB;
  uint32_t                   ColorCoding;
  uint32_t                   Orientation;
  uint32_t                   TEScanline;
  ST7789V_TE_Mode_t          TEMode;
  ST7789V_TimingParams_t     Timings;
} ST7789V_InitParams_t;

typedef struct
{
  /* Control functions */
  int32_t (*Init             )(ST7789V_Object_t*, ST7789V_InitParams_t*);
  int32_t (*DeInit           )(ST7789V_Object_t*);
  int32_t (*ReadID           )(ST7789V_Object_t*, uint32_t*);
  int32_t (*DisplayOn        )(ST7789V_Object_t*);
  int32_t (*DisplayOff       )(ST7789V_Object_t*);
  int32_t (*SetDisplayWindow )(ST7789V_Object_t*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t (*SetBrightness    )(ST7789V_Object_t*, uint32_t);
  int32_t (*GetBrightness    )(ST7789V_Object_t*, uint32_t*);
  int32_t (*SetOrientation   )(ST7789V_Object_t*, uint32_t);
  int32_t (*GetOrientation   )(ST7789V_Object_t*, uint32_t*);

  /* Drawing functions*/
  int32_t ( *SetCursor       ) (ST7789V_Object_t*, uint32_t, uint32_t);
  int32_t ( *DrawBitmap      ) (ST7789V_Object_t*, uint32_t, uint32_t, uint8_t *);
  int32_t ( *FillRGBRect     ) (ST7789V_Object_t*, uint32_t, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t ( *DrawHLine       ) (ST7789V_Object_t*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *DrawVLine       ) (ST7789V_Object_t*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *FillRect        ) (ST7789V_Object_t*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetPixel        ) (ST7789V_Object_t*, uint32_t, uint32_t, uint32_t*);
  int32_t ( *SetPixel        ) (ST7789V_Object_t*, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetXSize        ) (ST7789V_Object_t*, uint32_t *);
  int32_t ( *GetYSize        ) (ST7789V_Object_t*, uint32_t *);
}ST7789V_LCD_Drv_t;

/**
  * @}
  */

/** @defgroup ST7789V_Exported_Constants Exported Constants
  * @{
  */

/**
  * @brief  ST7789V Size
  */
#define ST7789V_OK                (0)
#define ST7789V_ERROR             (-1)

/**
  * @brief  ST7789V ID
  */
#define  ST7789V_ID              0x858552U

/**
  * @brief  ST7789V Size
  */
#define  ST7789V_WIDTH           240U
#define  ST7789V_HEIGHT          320U

/**
  * @brief  ST7789V Timing
  */
/* Timing configuration  (Typical configuration from ST7789V datasheet)
  HSYNC=10 (9+1)
  HBP=20 (29-10+1)
  ActiveW=240 (269-20-10+1)
  HFP=10 (279-240-20-10+1)

  VSYNC=2 (1+1)
  VBP=2 (3-2+1)
  ActiveH=320 (323-2-2+1)
  VFP=4 (327-320-2-2+1)
*/
#define  ST7789V_HSYNC            ((uint32_t)9)     /* Horizontal synchronization */
#define  ST7789V_HBP              ((uint32_t)29)    /* Horizontal back porch      */
#define  ST7789V_HFP              ((uint32_t)2)     /* Horizontal front porch     */
#define  ST7789V_VSYNC            ((uint32_t)1)     /* Vertical synchronization   */
#define  ST7789V_VBP              ((uint32_t)3)     /* Vertical back porch        */
#define  ST7789V_VFP              ((uint32_t)2)     /* Vertical front porch       */

/**
 *  @brief LCD_OrientationTypeDef
 *  Possible values of Display Orientation
 */
#define ST7789V_ORIENTATION_PORTRAIT         0x00U /* Portrait orientation choice of LCD screen               */
#define ST7789V_ORIENTATION_PORTRAIT_ROT180  0x01U /* Portrait rotated 180° orientation choice of LCD screen  */
#define ST7789V_ORIENTATION_LANDSCAPE        0x02U /* Landscape orientation choice of LCD screen              */
#define ST7789V_ORIENTATION_LANDSCAPE_ROT180 0x03U /* Landscape rotated 180° orientation choice of LCD screen */

/**
 *  @brief  Possible values of pixel data format (ie color coding)
 */
#define ST7789V_FORMAT_RBG565                0x55U /* Pixel format chosen is RGB565 : 16 bpp */
#define ST7789V_FORMAT_RBG666                0x66U /* Pixel format chosen is RGB666 : 18 bpp */
#define ST7789V_FORMAT_DEFAULT               ST7789V_FORMAT_RBG565
/**
  * @}
  */

/** @defgroup ST7789H2_Exported_Variables ST7789V Exported Variables
  * @{
  */
extern ST7789V_LCD_Drv_t   ST7789V_LCD_Driver;
/**
  * @}
  */

/** @defgroup ST7789V_Exported_Functions Exported Functions
  * @{
  */
int32_t ST7789V_RegisterBusIO (ST7789V_Object_t *pObj, ST7789V_IO_t *pIO);
int32_t ST7789V_Init(ST7789V_Object_t *pObj, ST7789V_InitParams_t* pInitParams);
int32_t ST7789V_DeInit(ST7789V_Object_t *pObj);
int32_t ST7789V_ReadID(ST7789V_Object_t *pObj, uint32_t *Id);
int32_t ST7789V_DisplayOn(ST7789V_Object_t *pObj);
int32_t ST7789V_DisplayOff(ST7789V_Object_t *pObj);
int32_t ST7789V_SetDisplayWindow(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height);
int32_t ST7789V_SetBrightness(ST7789V_Object_t *pObj, uint32_t Brightness);
int32_t ST7789V_GetBrightness(ST7789V_Object_t *pObj, uint32_t *Brightness);
int32_t ST7789V_SetOrientation(ST7789V_Object_t *pObj, uint32_t Orientation);
int32_t ST7789V_GetOrientation(ST7789V_Object_t *pObj, uint32_t *Orientation);

int32_t ST7789V_SetCursor(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos);
int32_t ST7789V_DrawBitmap(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint8_t *pBmp);
int32_t ST7789V_FillRGBRect(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint8_t *pData, uint32_t Width, uint32_t Height);
int32_t ST7789V_DrawHLine(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Length, uint32_t Color);
int32_t ST7789V_DrawVLine(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Length, uint32_t Color);
int32_t ST7789V_FillRect(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height, uint32_t Color);
int32_t ST7789V_SetPixel(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t Color);
int32_t ST7789V_GetPixel(ST7789V_Object_t *pObj, uint32_t Xpos, uint32_t Ypos, uint32_t *Color);
int32_t ST7789V_GetXSize(ST7789V_Object_t *pObj, uint32_t *XSize);
int32_t ST7789V_GetYSize(ST7789V_Object_t *pObj, uint32_t *YSize);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* ST7789V_H */

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
