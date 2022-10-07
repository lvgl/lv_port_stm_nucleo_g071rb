################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/st7789v/st7789v.c \
../Drivers/BSP/st7789v/st7789v_reg.c 

OBJS += \
./Drivers/BSP/st7789v/st7789v.o \
./Drivers/BSP/st7789v/st7789v_reg.o 

C_DEPS += \
./Drivers/BSP/st7789v/st7789v.d \
./Drivers/BSP/st7789v/st7789v_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/st7789v/%.o Drivers/BSP/st7789v/%.su: ../Drivers/BSP/st7789v/%.c Drivers/BSP/st7789v/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-st7789v

clean-Drivers-2f-BSP-2f-st7789v:
	-$(RM) ./Drivers/BSP/st7789v/st7789v.d ./Drivers/BSP/st7789v/st7789v.o ./Drivers/BSP/st7789v/st7789v.su ./Drivers/BSP/st7789v/st7789v_reg.d ./Drivers/BSP/st7789v/st7789v_reg.o ./Drivers/BSP/st7789v/st7789v_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-st7789v

