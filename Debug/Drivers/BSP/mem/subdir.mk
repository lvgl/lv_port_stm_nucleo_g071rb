################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/mem/mem_io.c \
../Drivers/BSP/mem/mem_os.c \
../Drivers/BSP/mem/mx25l6433f.c 

OBJS += \
./Drivers/BSP/mem/mem_io.o \
./Drivers/BSP/mem/mem_os.o \
./Drivers/BSP/mem/mx25l6433f.o 

C_DEPS += \
./Drivers/BSP/mem/mem_io.d \
./Drivers/BSP/mem/mem_os.d \
./Drivers/BSP/mem/mx25l6433f.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/mem/%.o Drivers/BSP/mem/%.su: ../Drivers/BSP/mem/%.c Drivers/BSP/mem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-mem

clean-Drivers-2f-BSP-2f-mem:
	-$(RM) ./Drivers/BSP/mem/mem_io.d ./Drivers/BSP/mem/mem_io.o ./Drivers/BSP/mem/mem_io.su ./Drivers/BSP/mem/mem_os.d ./Drivers/BSP/mem/mem_os.o ./Drivers/BSP/mem/mem_os.su ./Drivers/BSP/mem/mx25l6433f.d ./Drivers/BSP/mem/mx25l6433f.o ./Drivers/BSP/mem/mx25l6433f.su

.PHONY: clean-Drivers-2f-BSP-2f-mem

