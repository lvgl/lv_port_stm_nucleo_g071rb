################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.c \
../Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.c 

OBJS += \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.o \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.o 

C_DEPS += \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.d \
./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32G0xx_HAL_Driver/%.o Drivers/STM32G0xx_HAL_Driver/%.su: ../Drivers/STM32G0xx_HAL_Driver/%.c Drivers/STM32G0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../../DISPLAY/App -I../../DISPLAY/Target -I../../Core/Inc -I../../../../../../Drivers/STM32G0xx_HAL_Driver/Inc -I../../../../../../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../../../../../../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/BSP/Components/mx25l6433f -I../../../../../../Drivers/BSP/Components/Common -I../../../../../../Drivers/BSP/Components/st7789v -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-STM32G0xx_HAL_Driver

clean-Drivers-2f-STM32G0xx_HAL_Driver:
	-$(RM) ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_cortex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_crc_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_dma_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_exti.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_flash_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_gpio.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_pwr_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_rcc_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_spi_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_hal_tim_ex.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_dma.su ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.d ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.o ./Drivers/STM32G0xx_HAL_Driver/stm32g0xx_ll_rcc.su

.PHONY: clean-Drivers-2f-STM32G0xx_HAL_Driver

