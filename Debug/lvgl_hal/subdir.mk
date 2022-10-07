################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl_hal/disp.c \
../lvgl_hal/indev.c 

OBJS += \
./lvgl_hal/disp.o \
./lvgl_hal/indev.o 

C_DEPS += \
./lvgl_hal/disp.d \
./lvgl_hal/indev.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl_hal/%.o lvgl_hal/%.su: ../lvgl_hal/%.c lvgl_hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl_hal

clean-lvgl_hal:
	-$(RM) ./lvgl_hal/disp.d ./lvgl_hal/disp.o ./lvgl_hal/disp.su ./lvgl_hal/indev.d ./lvgl_hal/indev.o ./lvgl_hal/indev.su

.PHONY: clean-lvgl_hal

