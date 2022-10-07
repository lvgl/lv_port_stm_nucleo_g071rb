################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_posix.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_posix.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_posix.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/libs/fsdrv/%.o lvgl/src/extra/libs/fsdrv/%.su: ../lvgl/src/extra/libs/fsdrv/%.c lvgl/src/extra/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv:
	-$(RM) ./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d ./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o ./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.su ./lvgl/src/extra/libs/fsdrv/lv_fs_posix.d ./lvgl/src/extra/libs/fsdrv/lv_fs_posix.o ./lvgl/src/extra/libs/fsdrv/lv_fs_posix.su ./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d ./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o ./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.su ./lvgl/src/extra/libs/fsdrv/lv_fs_win32.d ./lvgl/src/extra/libs/fsdrv/lv_fs_win32.o ./lvgl/src/extra/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

