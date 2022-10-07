################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/lcd/lcd_io.c \
../Drivers/BSP/lcd/lcd_os.c \
../Drivers/BSP/lcd/st7789v.c \
../Drivers/BSP/lcd/st7789v_reg.c 

OBJS += \
./Drivers/BSP/lcd/lcd_io.o \
./Drivers/BSP/lcd/lcd_os.o \
./Drivers/BSP/lcd/st7789v.o \
./Drivers/BSP/lcd/st7789v_reg.o 

C_DEPS += \
./Drivers/BSP/lcd/lcd_io.d \
./Drivers/BSP/lcd/lcd_os.d \
./Drivers/BSP/lcd/st7789v.d \
./Drivers/BSP/lcd/st7789v_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/lcd/%.o Drivers/BSP/lcd/%.su: ../Drivers/BSP/lcd/%.c Drivers/BSP/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-lcd

clean-Drivers-2f-BSP-2f-lcd:
	-$(RM) ./Drivers/BSP/lcd/lcd_io.d ./Drivers/BSP/lcd/lcd_io.o ./Drivers/BSP/lcd/lcd_io.su ./Drivers/BSP/lcd/lcd_os.d ./Drivers/BSP/lcd/lcd_os.o ./Drivers/BSP/lcd/lcd_os.su ./Drivers/BSP/lcd/st7789v.d ./Drivers/BSP/lcd/st7789v.o ./Drivers/BSP/lcd/st7789v.su ./Drivers/BSP/lcd/st7789v_reg.d ./Drivers/BSP/lcd/st7789v_reg.o ./Drivers/BSP/lcd/st7789v_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-lcd

