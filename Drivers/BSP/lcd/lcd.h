/**
  ******************************************************************************
  * @file    lcd.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the LCD driver.
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
#ifndef LCD_H
#define LCD_H

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

/** @addtogroup LCD
  * @{
  */

/** @defgroup LCD_Exported_Constants LCD Exported Constants
  * @{
  */
#define LCD_PIXEL_FORMAT_ARGB8888        0x00000000U   /*!< ARGB8888 LTDC pixel format */
#define LCD_PIXEL_FORMAT_RGB888          0x00000001U   /*!< RGB888 LTDC pixel format   */
#define LCD_PIXEL_FORMAT_RGB565          0x00000002U   /*!< RGB565 LTDC pixel format   */
#define LCD_PIXEL_FORMAT_ARGB1555        0x00000003U   /*!< ARGB1555 LTDC pixel format */
#define LCD_PIXEL_FORMAT_ARGB4444        0x00000004U   /*!< ARGB4444 LTDC pixel format */
#define LCD_PIXEL_FORMAT_L8              0x00000005U   /*!< L8 LTDC pixel format       */
#define LCD_PIXEL_FORMAT_AL44            0x00000006U   /*!< AL44 LTDC pixel format     */
#define LCD_PIXEL_FORMAT_AL88            0x00000007U   /*!< AL88 LTDC pixel format     */
/**
  * @}
  */

/** @defgroup LCD_Exported_Types
  * @{
  */

/** @defgroup LCD_Exported_Macros
  * @{
  */
/**
 * Compiler specific macros.
 * LCD_DEPRECATED is used to mark a function deprecated.
 */
#if defined(__GNUC__) && !defined(__ARMCC_VERSION)
// xgcc
#define LCD_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#elif defined __ICCARM__
// IAR
#if __IAR_SYSTEMS_ICC__ >= 9
#define LCD_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#else
#define LCD_DEPRECATED(message, decl) decl
#endif
#elif defined(__ARMCC_VERSION)
// Keil
#if __ARMCC_VERSION >= 6000000
// Only newer Keil support message to be given
#define LCD_DEPRECATED(message, decl) decl __attribute__((deprecated(message)))
#else
#define LCD_DEPRECATED(message, decl) decl __attribute__((deprecated))
#endif
#else
// Other/Unknown
#define LCD_DEPRECATED(message, decl) decl
#endif

/** @defgroup LCD_Driver_structure  LCD Driver structure
  * @{
  */
typedef struct
{
  int32_t ( *DrawBitmap      ) (uint32_t, uint32_t, uint32_t, uint8_t *);
  int32_t ( *FillRGBRect     ) (uint32_t, uint32_t, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t ( *DrawHLine       ) (uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *DrawVLine       ) (uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *FillRect        ) (uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetPixel        ) (uint32_t, uint32_t, uint32_t, uint32_t*);
  int32_t ( *SetPixel        ) (uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetXSize        ) (uint32_t, uint32_t *);
  int32_t ( *GetYSize        ) (uint32_t, uint32_t *);
  int32_t ( *SetLayer        ) (uint32_t, uint32_t);
  int32_t ( *GetFormat       ) (uint32_t, uint32_t *);
} LCD_UTILS_Drv_t;

typedef struct
{
  /* Control functions */
  int32_t (*Init             )(void*, void*);
  int32_t (*DeInit           )(void*);
  int32_t (*ReadID           )(void*, uint32_t*);
  int32_t (*DisplayOn        )(void*);
  int32_t (*DisplayOff       )(void*);
  int32_t (*SetDisplayWindow )(void*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t (*SetBrightness    )(void*, uint32_t);
  int32_t (*GetBrightness    )(void*, uint32_t*);
  int32_t (*SetOrientation   )(void*, uint32_t);
  int32_t (*GetOrientation   )(void*, uint32_t*);

  /* Drawing functions*/
  int32_t ( *SetCursor       ) (void*, uint32_t, uint32_t);
  int32_t ( *DrawBitmap      ) (void*, uint32_t, uint32_t, uint8_t *);
  int32_t ( *FillRGBRect     ) (void*, uint32_t, uint32_t, uint8_t*, uint32_t, uint32_t);
  int32_t ( *DrawHLine       ) (void*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *DrawVLine       ) (void*, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *FillRect        ) (void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetPixel        ) (void*, uint32_t, uint32_t, uint32_t*);
  int32_t ( *SetPixel        ) (void*, uint32_t, uint32_t, uint32_t);
  int32_t ( *GetXSize        ) (void*, uint32_t *);
  int32_t ( *GetYSize        ) (void*, uint32_t *);
}LCD_Drv_t;


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

#endif /* LCD_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
