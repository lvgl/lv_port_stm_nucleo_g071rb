################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/libs/freetype/lv_freetype.c 

OBJS += \
./lvgl/src/extra/libs/freetype/lv_freetype.o 

C_DEPS += \
./lvgl/src/extra/libs/freetype/lv_freetype.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/libs/freetype/%.o lvgl/src/extra/libs/freetype/%.su: ../lvgl/src/extra/libs/freetype/%.c lvgl/src/extra/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-libs-2f-freetype

clean-lvgl-2f-src-2f-extra-2f-libs-2f-freetype:
	-$(RM) ./lvgl/src/extra/libs/freetype/lv_freetype.d ./lvgl/src/extra/libs/freetype/lv_freetype.o ./lvgl/src/extra/libs/freetype/lv_freetype.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-libs-2f-freetype
