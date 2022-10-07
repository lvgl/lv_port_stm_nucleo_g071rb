/**
  ******************************************************************************
  * @file    st7789v_reg.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the st7789v_reg.c
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
#ifndef ST7789V_REG_H
#define ST7789V_REG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup ST7789V
  * @{
  */

/** @defgroup ST7789V_Exported_Types ST7789V Exported Types
  * @{
  */
typedef int32_t (*ST7789V_Write_Func)(void *, uint8_t*, uint32_t);
typedef int32_t (*ST7789V_Read_Func) (void *, uint8_t*, uint32_t);
typedef int32_t (*ST7789V_Send_Func) (void *, uint8_t*, uint32_t);
typedef int32_t (*ST7789V_Recv_Func) (void *, uint8_t*, uint32_t);

typedef struct
{
  ST7789V_Write_Func   WriteReg;
  ST7789V_Read_Func    ReadReg;
  ST7789V_Send_Func    SendData;
  ST7789V_Send_Func    SendDataDMA;
  ST7789V_Recv_Func    RecvData;
  ST7789V_Recv_Func    RecvDataDMA;
  void                 *handle;
} st7789v_ctx_t;
/**
  * @}
  */

/** @defgroup ST7789V_Exported_Constants ST7789V Exported Constants
  * @{
  */

/**
  * @brief  ST7789V Registers
  */
/* Level 1 Commands */
#define ST7789V_NOP                       0x00U   /* No operation */
#define ST7789V_SWRESET                   0x01U   /* Software Reset */
#define ST7789V_READ_DISPLAY_ID           0x04U   /* Read display identification information */
#define ST7789V_RDDST                     0x09U   /* Read Display Status */
#define ST7789V_RDDPM                     0x0AU   /* Read Display Power Mode */
#define ST7789V_RDDMADCTL                 0x0BU   /* Read Display MADCTL */
#define ST7789V_RDDCOLMOD                 0x0CU   /* Read Display Pixel Format */
#define ST7789V_RDDIM                     0x0DU   /* Read Display Image Format */
#define ST7789V_RDDSM                     0x0EU   /* Read Display Signal Mode */
#define ST7789V_RDDSDR                    0x0FU   /* Read Display Self-Diagnostic Result */
#define ST7789V_SPLIN                     0x10U   /* Enter Sleep Mode */
#define ST7789V_SLEEP_OUT                 0x11U   /* Sleep out register */
#define ST7789V_PTLON                     0x12U   /* Partial Mode ON */
#define ST7789V_NORMAL_MODE_ON            0x13U   /* Normal Display Mode ON */
#define ST7789V_DINVOFF                   0x20U   /* Display Inversion OFF */
#define ST7789V_DINVON                    0x21U   /* Display Inversion ON */
#define ST7789V_GAMMA                     0x26U   /* Gamma register */
#define ST7789V_DISPLAY_OFF               0x28U   /* Display off register */
#define ST7789V_DISPLAY_ON                0x29U   /* Display on register */
#define ST7789V_CASET                     0x2AU   /* Colomn address register */
#define ST7789V_RASET                     0x2BU   /* Raw address register */
#define ST7789V_GRAM                      0x2CU   /* GRAM register */
#define ST7789V_RGBSET                    0x2DU   /* Color SET */
#define ST7789V_RAMRD                     0x2EU   /* Memory Read */
#define ST7789V_PLTAR                     0x30U   /* Partial Area */
#define ST7789V_VSCRDEF                   0x33U   /* Vertical Scrolling Definition */
#define ST7789V_TEOFF                     0x34U   /* Tearing Effect Line OFF */
#define ST7789V_TEON                      0x35U   /* Tearing Effect Line ON */
#define ST7789V_MAC                       0x36U   /* Memory Access Control register*/
#define ST7789V_VSCRSADD                  0x37U   /* Vertical Scrolling Start Address */
#define ST7789V_IDMOFF                    0x38U   /* Idle Mode OFF */
#define ST7789V_IDMON                     0x39U   /* Idle Mode ON */
#define ST7789V_PIXEL_FORMAT              0x3AU   /* Pixel Format register */
#define ST7789V_WRITE_MEM_CONTINUE        0x3CU   /* Write Memory Continue */
#define ST7789V_READ_MEM_CONTINUE         0x3EU   /* Read Memory Continue */
#define ST7789V_SET_TEAR_SCANLINE         0x44U   /* Set Tear Scanline */
#define ST7789V_GET_SCANLINE              0x45U   /* Get Scanline */
#define ST7789V_WDB                       0x51U   /* Write Brightness Display register */
#define ST7789V_RDDISBV                   0x52U   /* Read Display Brightness */
#define ST7789V_WCD                       0x53U   /* Write Control Display register*/
#define ST7789V_RDCTRLD                   0x54U   /* Read CTRL Display */
#define ST7789V_WRCABC                    0x55U   /* Write Content Adaptive Brightness Control */
#define ST7789V_RDCABC                    0x56U   /* Read Content Adaptive Brightness Control */
#define ST7789V_WRITE_CABC                0x5EU   /* Write CABC Minimum Brightness */
#define ST7789V_READ_CABC                 0x5FU   /* Read CABC Minimum Brightness */
#define ST7789V_READ_ABCSDR               0x68U   /* Read Automatic Brightness Control Self-Diagnostic Result */
#define ST7789V_READ_ID1                  0xDAU   /* Read ID1 */
#define ST7789V_READ_ID2                  0xDBU   /* Read ID2 */
#define ST7789V_READ_ID3                  0xDCU   /* Read ID3 */

/* Level 2 Commands */
#define ST7789V_RAM_CTRL                  0xB0U   /* RAM Control */
#define ST7789V_RGB_INTERFACE_CTRL        0xB1U   /* Porch Setting */
#define ST7789V_PORCH_CTRL                0xB2U   /* RGB Interface Signal Control */
#define ST7789V_FRAME_RATE_CTRL1          0xB3U   /* Frame Rate Control 1 (In partial mode/ idle colors)) */
#define ST7789V_PARTIAL_CTRL              0xB5U   /* N/A */
#define ST7789V_GATE_CTRL                 0xB7U   /* Gate Control */
#define ST7789V_GATE_TIMING_ADJUSTMENT    0xB8U   /* Timing Adjustement */
#define ST7789V_DIGITAL_GAMMA_ENABLE      0xBAU   /* Digital Gamma Enable */
#define ST7789V_VCOM_SET                  0xBBU   /* VCOM Setting */
#define ST7789V_PWR_SAVING_MODE           0xBCU   /* LCM Control */
#define ST7789V_DISPLAY_OFF_PWR_SAVE      0xBDU   /* N/A */
#define ST7789V_LCM_CTRL                  0xC0U   /* N/A */
#define ST7789V_ID_CODE_SETTING           0xC1U   /* ID Code Setting */
#define ST7789V_VDV_VRH_EN                0xC2U   /* VDV and VRH Command Enable */
#define ST7789V_VRH_SET                   0xC3U   /* VRH Set */
#define ST7789V_VDV_SET                   0xC4U   /* VDV Set */
#define ST7789V_VCOMH_OFFSET_SET          0xC5U   /* VCOM Offset Set */
#define ST7789V_FRAME_RATE_CTRL2          0xC6U   /* Frame Rate Control 2 (In Normal Mode) */
#define ST7789V_CABC_CTRL                 0xC7U   /* CABC Control */
#define ST7789V_REG_VALUE_SELECTION1      0xC8U   /* Register Value Selection 1 */
#define ST7789V_REG_VALUE_SELECTION2      0xCAU   /* Register Value Selection 2 */
#define ST7789V_PWM_FREQ_SELECTION        0xCCU   /* PWM Frequency Selection */
#define ST7789V_POWER_CTRL                0xD0U   /* Power Control 1 */
#define ST7789V_EN_VAP_VAN_SIGNAL_OUTPUT  0xD2U   /* Enable VAP/VAN signal output */
#define ST7789V_COMMAND2_ENABLE           0xDFU   /* Command 2 Enable */
#define ST7789V_PV_GAMMA_CTRL             0xE0U   /* Positive Voltage Gamma Control */
#define ST7789V_NV_GAMMA_CTRL             0xE1U   /* Negative Voltage Gamma Control */
#define ST7789V_GAMMA_RED_TABLE           0xE2U   /* Digital Gamma Look-up Table for Red */
#define ST7789V_GAMMA_BLUE_TABLE          0xE3U   /* Digital Gamma Look-up Table for Blue */
#define ST7789V_GATE_CTRL2                0xE4U   /* Gate Control */
#define ST7789V_SPI2_ENABLE               0xE7U   /* SPI2 Enable */
#define ST7789V_PWR_CTRL2                 0xE8U   /* Power Control 2 */
#define ST7789V_EQUALIZE_TIME_CTRL        0xE9U   /* Equalize time control */
#define ST7789V_PROGRAM_MODE_CTRL         0xECU   /* Program Mode Control */
#define ST7789V_PROGRAM_MODE_ENABLE       0xFAU   /* Program Mode Enable */
#define ST7789V_NVM_SETTING               0xFCU   /* NVM Setting */
#define ST7789V_PROGRAM_ACTION            0xFEU   /* Program action */

/**
  * @}
  */

/** @defgroup ST7789V_Exported_Functions ST7789V Exported Functions
  * @{
  */
int32_t st7789v_write_reg(st7789v_ctx_t *ctx, uint8_t* reg, uint32_t length);
int32_t st7789v_read_reg(st7789v_ctx_t *ctx, uint8_t* reg, uint32_t length);
int32_t st7789v_send_data(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length);
int32_t st7789v_send_data_dma(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length);
int32_t st7789v_recv_data(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length);
int32_t st7789v_recv_data_dma(st7789v_ctx_t *ctx, uint8_t *pdata, uint32_t length);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* ST7789V_REG_H */

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
