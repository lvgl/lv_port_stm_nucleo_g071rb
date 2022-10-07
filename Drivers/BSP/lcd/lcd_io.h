/**
  ******************************************************************************
  * File Name          : Target/lcd_io.h
  * Description        : This file provides code for the exported APIs
  *                      of the LCD instances.
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
#ifndef __LCD_IO_H__
#define __LCD_IO_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "lcd.h"
#include "lcd_conf.h"
#include "st7789v.h"

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

/* LCD Cache lines */
#define BUFFER_CACHE_LINES                  24

/* LCD Orientation */
#define LCD_ORIENTATION_PORTRAIT            ST7789V_ORIENTATION_PORTRAIT
#define LCD_ORIENTATION_LANDSCAPE           ST7789V_ORIENTATION_LANDSCAPE
#define LCD_ORIENTATION_PORTRAIT_ROT180     ST7789V_ORIENTATION_PORTRAIT_ROT180
#define LCD_ORIENTATION_LANDSCAPE_ROT180    ST7789V_ORIENTATION_LANDSCAPE_ROT180

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
int32_t BSP_LCD_Init(uint32_t Instance, uint32_t Orientation);
int32_t BSP_LCD_DeInit(uint32_t Instance);
int32_t BSP_LCD_SetOrientation(uint32_t Instance, uint32_t Orientation);
int32_t BSP_LCD_GetOrientation(uint32_t Instance, uint32_t *Orientation);
int32_t BSP_LCD_GetXSize(uint32_t Instance, uint32_t *XSize);
int32_t BSP_LCD_GetYSize(uint32_t Instance, uint32_t *YSize);
int32_t BSP_LCD_DisplayOn(uint32_t Instance);
int32_t BSP_LCD_DisplayOff(uint32_t Instance);
int32_t BSP_LCD_WriteData(uint32_t Instance, uint8_t *pData, uint32_t Length);
int32_t BSP_LCD_WriteDataDMA(uint32_t Instance, uint8_t *pData, uint32_t Length);
int32_t BSP_LCD_SetDisplayWindow(uint32_t Instance, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height);
int32_t BSP_LCD_FillRGBRect(uint32_t Instance, uint8_t UseDMA, uint8_t *pData, uint32_t Xpos, uint32_t Ypos, uint32_t Width, uint32_t Height);
uint8_t BSP_LCD_GetTransferStatus(uint32_t Instance);
void    BSP_LCD_WaitForTransferToBeDone(uint32_t Instance);
void    BSP_LCD_SignalTransferDone(uint32_t Instance);
void    BSP_LCD_SignalTearingEffectEvent(uint32_t Instance, uint8_t state, uint16_t Line);

/* Deprecated APIs */
LCD_DEPRECATED("Use BSP_LCD_GetTransferStatus(Instance) instead.", uint8_t BSP_LCD_GetTransfertStatus(uint32_t Instance));
LCD_DEPRECATED("Use BSP_LCD_SignalTransferDone(Instance) instead.", void BSP_LCD_SignalTransfertDone(uint32_t Instance, uint8_t Event));

#ifdef __cplusplus
}
#endif
#endif /* __LCD_IO_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
