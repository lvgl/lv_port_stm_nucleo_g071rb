################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Common/key_io.c \
../Drivers/BSP/Common/lcd_io.c \
../Drivers/BSP/Common/lcd_os.c \
../Drivers/BSP/Common/mem_io.c \
../Drivers/BSP/Common/mem_os.c 

OBJS += \
./Drivers/BSP/Common/key_io.o \
./Drivers/BSP/Common/lcd_io.o \
./Drivers/BSP/Common/lcd_os.o \
./Drivers/BSP/Common/mem_io.o \
./Drivers/BSP/Common/mem_os.o 

C_DEPS += \
./Drivers/BSP/Common/key_io.d \
./Drivers/BSP/Common/lcd_io.d \
./Drivers/BSP/Common/lcd_os.d \
./Drivers/BSP/Common/mem_io.d \
./Drivers/BSP/Common/mem_os.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Common/%.o Drivers/BSP/Common/%.su: ../Drivers/BSP/Common/%.c Drivers/BSP/Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Common

clean-Drivers-2f-BSP-2f-Common:
	-$(RM) ./Drivers/BSP/Common/key_io.d ./Drivers/BSP/Common/key_io.o ./Drivers/BSP/Common/key_io.su ./Drivers/BSP/Common/lcd_io.d ./Drivers/BSP/Common/lcd_io.o ./Drivers/BSP/Common/lcd_io.su ./Drivers/BSP/Common/lcd_os.d ./Drivers/BSP/Common/lcd_os.o ./Drivers/BSP/Common/lcd_os.su ./Drivers/BSP/Common/mem_io.d ./Drivers/BSP/Common/mem_io.o ./Drivers/BSP/Common/mem_io.su ./Drivers/BSP/Common/mem_os.d ./Drivers/BSP/Common/mem_os.o ./Drivers/BSP/Common/mem_os.su

.PHONY: clean-Drivers-2f-BSP-2f-Common

