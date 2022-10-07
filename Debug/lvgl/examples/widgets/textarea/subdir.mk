################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/textarea/lv_example_textarea_1.c \
../lvgl/examples/widgets/textarea/lv_example_textarea_2.c \
../lvgl/examples/widgets/textarea/lv_example_textarea_3.c 

OBJS += \
./lvgl/examples/widgets/textarea/lv_example_textarea_1.o \
./lvgl/examples/widgets/textarea/lv_example_textarea_2.o \
./lvgl/examples/widgets/textarea/lv_example_textarea_3.o 

C_DEPS += \
./lvgl/examples/widgets/textarea/lv_example_textarea_1.d \
./lvgl/examples/widgets/textarea/lv_example_textarea_2.d \
./lvgl/examples/widgets/textarea/lv_example_textarea_3.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/textarea/%.o lvgl/examples/widgets/textarea/%.su: ../lvgl/examples/widgets/textarea/%.c lvgl/examples/widgets/textarea/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-textarea

clean-lvgl-2f-examples-2f-widgets-2f-textarea:
	-$(RM) ./lvgl/examples/widgets/textarea/lv_example_textarea_1.d ./lvgl/examples/widgets/textarea/lv_example_textarea_1.o ./lvgl/examples/widgets/textarea/lv_example_textarea_1.su ./lvgl/examples/widgets/textarea/lv_example_textarea_2.d ./lvgl/examples/widgets/textarea/lv_example_textarea_2.o ./lvgl/examples/widgets/textarea/lv_example_textarea_2.su ./lvgl/examples/widgets/textarea/lv_example_textarea_3.d ./lvgl/examples/widgets/textarea/lv_example_textarea_3.o ./lvgl/examples/widgets/textarea/lv_example_textarea_3.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-textarea

