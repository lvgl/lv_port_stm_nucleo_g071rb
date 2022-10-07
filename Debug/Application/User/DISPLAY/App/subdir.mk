################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/DISPLAY/App/app_display.c 

OBJS += \
./Application/User/DISPLAY/App/app_display.o 

C_DEPS += \
./Application/User/DISPLAY/App/app_display.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/DISPLAY/App/%.o Application/User/DISPLAY/App/%.su: ../Application/User/DISPLAY/App/%.c Application/User/DISPLAY/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Application/User/Core/Inc" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-DISPLAY-2f-App

clean-Application-2f-User-2f-DISPLAY-2f-App:
	-$(RM) ./Application/User/DISPLAY/App/app_display.d ./Application/User/DISPLAY/App/app_display.o ./Application/User/DISPLAY/App/app_display.su

.PHONY: clean-Application-2f-User-2f-DISPLAY-2f-App

