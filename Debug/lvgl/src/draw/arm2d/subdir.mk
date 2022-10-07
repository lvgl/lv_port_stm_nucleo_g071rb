################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/arm2d/lv_gpu_arm2d.c 

OBJS += \
./lvgl/src/draw/arm2d/lv_gpu_arm2d.o 

C_DEPS += \
./lvgl/src/draw/arm2d/lv_gpu_arm2d.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/arm2d/%.o lvgl/src/draw/arm2d/%.su: ../lvgl/src/draw/arm2d/%.c lvgl/src/draw/arm2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-arm2d

clean-lvgl-2f-src-2f-draw-2f-arm2d:
	-$(RM) ./lvgl/src/draw/arm2d/lv_gpu_arm2d.d ./lvgl/src/draw/arm2d/lv_gpu_arm2d.o ./lvgl/src/draw/arm2d/lv_gpu_arm2d.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-arm2d

