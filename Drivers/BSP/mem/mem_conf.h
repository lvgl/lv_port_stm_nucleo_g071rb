/**
  ******************************************************************************
  * File Name          : Target/mem_conf.h
  * Description        : This file provides code for the configuration
  *                      of the MEM instances.
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
#ifndef __MEM_CONF_H__
#define __MEM_CONF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx.h"
#include "stm32g0xx_nucleo_bus.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* Number of MEM instances */
#define MEM_INSTANCES_NBR                   1U

/* BUS IO Instance handlers */
extern  SPI_HandleTypeDef                   hspi2;
#define hMEMSPI                             hspi2

extern  DMA_HandleTypeDef                   hdma_spi2_rx;
extern  DMA_HandleTypeDef                   hdma_spi2_tx;
#define hMEMDMA_rx                          hdma_spi2_rx
#define hMEMDMA_tx                          hdma_spi2_tx

/* BUS IO functions */
#define MEM_SPI_Init                        BSP_SPI2_Init
#define MEM_SPI_DeInit                      BSP_SPI2_DeInit
#define MEM_SPI_Recv                        BSP_SPI2_Recv
#define MEM_SPI_Send                        BSP_SPI2_Send
#define MEM_SPI_SendRecv                    BSP_SPI2_SendRecv
#define MEM_SPI_Recv_DMA                    BSP_SPI2_Recv_DMA
#define MEM_SPI_Send_DMA                    BSP_SPI2_Send_DMA
#define MEM_SPI_SendRecv_DMA                BSP_SPI2_SendRecv_DMA
/* CS Pin mapping */
#define MEM_CS_GPIO_PORT                    GPIOA
#define MEM_CS_GPIO_PIN                     GPIO_PIN_8

#define MEM_INTERFACE_MODE                  MEM_INTERFACE_SPI_MODE

/* Exported macro ------------------------------------------------------------*/
/* Chip Select macro definition */
#define MEM_CS_LOW()                        WRITE_REG(GPIOA->BRR, GPIO_PIN_8)
#define MEM_CS_HIGH()                       WRITE_REG(GPIOA->BSRR, GPIO_PIN_8)

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* __MEM_CONF_H__ */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
