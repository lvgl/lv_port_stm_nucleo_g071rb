################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Core/Src/main.c \
../Application/User/Core/Src/stm32g0xx_hal_msp.c \
../Application/User/Core/Src/stm32g0xx_it.c \
../Application/User/Core/Src/stm32g0xx_nucleo_bus.c \
../Application/User/Core/Src/system_stm32g0xx.c 

OBJS += \
./Application/User/Core/Src/main.o \
./Application/User/Core/Src/stm32g0xx_hal_msp.o \
./Application/User/Core/Src/stm32g0xx_it.o \
./Application/User/Core/Src/stm32g0xx_nucleo_bus.o \
./Application/User/Core/Src/system_stm32g0xx.o 

C_DEPS += \
./Application/User/Core/Src/main.d \
./Application/User/Core/Src/stm32g0xx_hal_msp.d \
./Application/User/Core/Src/stm32g0xx_it.d \
./Application/User/Core/Src/stm32g0xx_nucleo_bus.d \
./Application/User/Core/Src/system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/Src/%.o Application/User/Core/Src/%.su: ../Application/User/Core/Src/%.c Application/User/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Application/User/Core/Inc" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core-2f-Src

clean-Application-2f-User-2f-Core-2f-Src:
	-$(RM) ./Application/User/Core/Src/main.d ./Application/User/Core/Src/main.o ./Application/User/Core/Src/main.su ./Application/User/Core/Src/stm32g0xx_hal_msp.d ./Application/User/Core/Src/stm32g0xx_hal_msp.o ./Application/User/Core/Src/stm32g0xx_hal_msp.su ./Application/User/Core/Src/stm32g0xx_it.d ./Application/User/Core/Src/stm32g0xx_it.o ./Application/User/Core/Src/stm32g0xx_it.su ./Application/User/Core/Src/stm32g0xx_nucleo_bus.d ./Application/User/Core/Src/stm32g0xx_nucleo_bus.o ./Application/User/Core/Src/stm32g0xx_nucleo_bus.su ./Application/User/Core/Src/system_stm32g0xx.d ./Application/User/Core/Src/system_stm32g0xx.o ./Application/User/Core/Src/system_stm32g0xx.su

.PHONY: clean-Application-2f-User-2f-Core-2f-Src

