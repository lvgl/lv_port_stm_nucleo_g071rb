################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/slider/lv_example_slider_1.c \
../lvgl/examples/widgets/slider/lv_example_slider_2.c \
../lvgl/examples/widgets/slider/lv_example_slider_3.c 

OBJS += \
./lvgl/examples/widgets/slider/lv_example_slider_1.o \
./lvgl/examples/widgets/slider/lv_example_slider_2.o \
./lvgl/examples/widgets/slider/lv_example_slider_3.o 

C_DEPS += \
./lvgl/examples/widgets/slider/lv_example_slider_1.d \
./lvgl/examples/widgets/slider/lv_example_slider_2.d \
./lvgl/examples/widgets/slider/lv_example_slider_3.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/slider/%.o lvgl/examples/widgets/slider/%.su: ../lvgl/examples/widgets/slider/%.c lvgl/examples/widgets/slider/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-slider

clean-lvgl-2f-examples-2f-widgets-2f-slider:
	-$(RM) ./lvgl/examples/widgets/slider/lv_example_slider_1.d ./lvgl/examples/widgets/slider/lv_example_slider_1.o ./lvgl/examples/widgets/slider/lv_example_slider_1.su ./lvgl/examples/widgets/slider/lv_example_slider_2.d ./lvgl/examples/widgets/slider/lv_example_slider_2.o ./lvgl/examples/widgets/slider/lv_example_slider_2.su ./lvgl/examples/widgets/slider/lv_example_slider_3.d ./lvgl/examples/widgets/slider/lv_example_slider_3.o ./lvgl/examples/widgets/slider/lv_example_slider_3.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-slider

