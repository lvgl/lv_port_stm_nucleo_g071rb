/**
  ******************************************************************************
  * File Name          : Target/lcd_conf.h
  * Description        : This file provides code for the configuration
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
#ifndef __LCD_CONF_H__
#define __LCD_CONF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx.h"
#include "stm32g0xx_nucleo_bus.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* Number of LCD instances */
#define LCD_INSTANCES_NBR                   1U

/* BUS IO Instance handlers */
extern  SPI_HandleTypeDef                   hspi1;
#define hLCDSPI                             hspi1

extern  DMA_HandleTypeDef                   hdma_spi1_rx;
extern  DMA_HandleTypeDef                   hdma_spi1_tx;
#define hLCDDMA_rx                          hdma_spi1_rx
#define hLCDDMA_tx                          hdma_spi1_tx

/* BUS IO functions */
#define LCD_SPI_Init                        BSP_SPI1_Init
#define LCD_SPI_DeInit                      BSP_SPI1_DeInit
#define LCD_SPI_Send                        BSP_SPI1_Send
#define LCD_SPI_Recv                        BSP_SPI1_Recv
#define LCD_SPI_SendRecv                    BSP_SPI1_SendRecv
#define LCD_SPI_Send_DMA                    BSP_SPI1_Send_DMA
#define LCD_SPI_Recv_DMA                    BSP_SPI1_Recv_DMA
#define LCD_SPI_SendRecv_DMA                BSP_SPI1_SendRecv_DMA

/* CS Pin mapping */
#define LCD_CS_GPIO_PORT                    GPIOA
#define LCD_CS_GPIO_PIN                     GPIO_PIN_9

/* DCX Pin mapping */
#define LCD_DCX_GPIO_PORT                   GPIOB
#define LCD_DCX_GPIO_PIN                    GPIO_PIN_14

/* RESET Pin mapping */
#define LCD_RESET_GPIO_PORT                 GPIOA
#define LCD_RESET_GPIO_PIN                  GPIO_PIN_1

/* TE Pin mapping */
#define LCD_TE_GPIO_PORT                    GPIOA
#define LCD_TE_GPIO_PIN                     GPIO_PIN_0
#define LCD_TE_GPIO_LINE                    EXTI_LINE_0
#define LCD_TE_GPIO_IRQn                    EXTI0_1_IRQn
extern EXTI_HandleTypeDef                   hexti_lcd_te;
#define H_EXTI_0                            hexti_lcd_te

/* Exported macro ------------------------------------------------------------*/
/* Chip Reset macro definition */
#define LCD_RST_LOW()                       WRITE_REG(GPIOA->BRR, GPIO_PIN_1)
#define LCD_RST_HIGH()                      WRITE_REG(GPIOA->BSRR, GPIO_PIN_1)

/* Chip Select macro definition */
#define LCD_CS_LOW()                        WRITE_REG(GPIOA->BRR, GPIO_PIN_9)
#define LCD_CS_HIGH()                       WRITE_REG(GPIOA->BSRR, GPIO_PIN_9)

/* Data/Command macro definition */
#define LCD_DC_LOW()                        WRITE_REG(GPIOB->BSRR, GPIO_PIN_14)
#define LCD_DC_HIGH()                       WRITE_REG(GPIOB->BRR, GPIO_PIN_14)

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* __LCD_CONF_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
