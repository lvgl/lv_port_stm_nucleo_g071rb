################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/meter/lv_example_meter_1.c \
../lvgl/examples/widgets/meter/lv_example_meter_2.c \
../lvgl/examples/widgets/meter/lv_example_meter_3.c \
../lvgl/examples/widgets/meter/lv_example_meter_4.c 

OBJS += \
./lvgl/examples/widgets/meter/lv_example_meter_1.o \
./lvgl/examples/widgets/meter/lv_example_meter_2.o \
./lvgl/examples/widgets/meter/lv_example_meter_3.o \
./lvgl/examples/widgets/meter/lv_example_meter_4.o 

C_DEPS += \
./lvgl/examples/widgets/meter/lv_example_meter_1.d \
./lvgl/examples/widgets/meter/lv_example_meter_2.d \
./lvgl/examples/widgets/meter/lv_example_meter_3.d \
./lvgl/examples/widgets/meter/lv_example_meter_4.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/meter/%.o lvgl/examples/widgets/meter/%.su: ../lvgl/examples/widgets/meter/%.c lvgl/examples/widgets/meter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-meter

clean-lvgl-2f-examples-2f-widgets-2f-meter:
	-$(RM) ./lvgl/examples/widgets/meter/lv_example_meter_1.d ./lvgl/examples/widgets/meter/lv_example_meter_1.o ./lvgl/examples/widgets/meter/lv_example_meter_1.su ./lvgl/examples/widgets/meter/lv_example_meter_2.d ./lvgl/examples/widgets/meter/lv_example_meter_2.o ./lvgl/examples/widgets/meter/lv_example_meter_2.su ./lvgl/examples/widgets/meter/lv_example_meter_3.d ./lvgl/examples/widgets/meter/lv_example_meter_3.o ./lvgl/examples/widgets/meter/lv_example_meter_3.su ./lvgl/examples/widgets/meter/lv_example_meter_4.d ./lvgl/examples/widgets/meter/lv_example_meter_4.o ./lvgl/examples/widgets/meter/lv_example_meter_4.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-meter

