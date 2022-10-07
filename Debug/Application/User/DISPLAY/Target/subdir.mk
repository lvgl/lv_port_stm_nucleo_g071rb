################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/DISPLAY/Target/key_io.c \
../Application/User/DISPLAY/Target/lcd_io.c \
../Application/User/DISPLAY/Target/lcd_os.c \
../Application/User/DISPLAY/Target/mem_io.c \
../Application/User/DISPLAY/Target/mem_os.c 

OBJS += \
./Application/User/DISPLAY/Target/key_io.o \
./Application/User/DISPLAY/Target/lcd_io.o \
./Application/User/DISPLAY/Target/lcd_os.o \
./Application/User/DISPLAY/Target/mem_io.o \
./Application/User/DISPLAY/Target/mem_os.o 

C_DEPS += \
./Application/User/DISPLAY/Target/key_io.d \
./Application/User/DISPLAY/Target/lcd_io.d \
./Application/User/DISPLAY/Target/lcd_os.d \
./Application/User/DISPLAY/Target/mem_io.d \
./Application/User/DISPLAY/Target/mem_os.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/DISPLAY/Target/%.o Application/User/DISPLAY/Target/%.su: ../Application/User/DISPLAY/Target/%.c Application/User/DISPLAY/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Application/User/Core/Inc" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-DISPLAY-2f-Target

clean-Application-2f-User-2f-DISPLAY-2f-Target:
	-$(RM) ./Application/User/DISPLAY/Target/key_io.d ./Application/User/DISPLAY/Target/key_io.o ./Application/User/DISPLAY/Target/key_io.su ./Application/User/DISPLAY/Target/lcd_io.d ./Application/User/DISPLAY/Target/lcd_io.o ./Application/User/DISPLAY/Target/lcd_io.su ./Application/User/DISPLAY/Target/lcd_os.d ./Application/User/DISPLAY/Target/lcd_os.o ./Application/User/DISPLAY/Target/lcd_os.su ./Application/User/DISPLAY/Target/mem_io.d ./Application/User/DISPLAY/Target/mem_io.o ./Application/User/DISPLAY/Target/mem_io.su ./Application/User/DISPLAY/Target/mem_os.d ./Application/User/DISPLAY/Target/mem_os.o ./Application/User/DISPLAY/Target/mem_os.su

.PHONY: clean-Application-2f-User-2f-DISPLAY-2f-Target

