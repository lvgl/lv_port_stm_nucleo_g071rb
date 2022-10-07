################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ui/font_14.c \
../ui/ui.c \
../ui/ui_comp.c \
../ui/ui_helpers.c \
../ui/ui_img_aircon_png.c \
../ui/ui_img_back_png.c \
../ui/ui_img_battery_png.c \
../ui/ui_img_ble_png.c \
../ui/ui_img_circle_png.c \
../ui/ui_img_corner_png.c \
../ui/ui_img_ellips_png.c \
../ui/ui_img_info_png.c \
../ui/ui_img_pattern_png.c \
../ui/ui_img_time_png.c \
../ui/ui_img_wifi_png.c 

OBJS += \
./ui/font_14.o \
./ui/ui.o \
./ui/ui_comp.o \
./ui/ui_helpers.o \
./ui/ui_img_aircon_png.o \
./ui/ui_img_back_png.o \
./ui/ui_img_battery_png.o \
./ui/ui_img_ble_png.o \
./ui/ui_img_circle_png.o \
./ui/ui_img_corner_png.o \
./ui/ui_img_ellips_png.o \
./ui/ui_img_info_png.o \
./ui/ui_img_pattern_png.o \
./ui/ui_img_time_png.o \
./ui/ui_img_wifi_png.o 

C_DEPS += \
./ui/font_14.d \
./ui/ui.d \
./ui/ui_comp.d \
./ui/ui_helpers.d \
./ui/ui_img_aircon_png.d \
./ui/ui_img_back_png.d \
./ui/ui_img_battery_png.d \
./ui/ui_img_ble_png.d \
./ui/ui_img_circle_png.d \
./ui/ui_img_corner_png.d \
./ui/ui_img_ellips_png.d \
./ui/ui_img_info_png.d \
./ui/ui_img_pattern_png.d \
./ui/ui_img_time_png.d \
./ui/ui_img_wifi_png.d 


# Each subdirectory must supply rules for building sources it contributes
ui/%.o ui/%.su: ../ui/%.c ui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Core/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/lvgl_hal" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ui

clean-ui:
	-$(RM) ./ui/font_14.d ./ui/font_14.o ./ui/font_14.su ./ui/ui.d ./ui/ui.o ./ui/ui.su ./ui/ui_comp.d ./ui/ui_comp.o ./ui/ui_comp.su ./ui/ui_helpers.d ./ui/ui_helpers.o ./ui/ui_helpers.su ./ui/ui_img_aircon_png.d ./ui/ui_img_aircon_png.o ./ui/ui_img_aircon_png.su ./ui/ui_img_back_png.d ./ui/ui_img_back_png.o ./ui/ui_img_back_png.su ./ui/ui_img_battery_png.d ./ui/ui_img_battery_png.o ./ui/ui_img_battery_png.su ./ui/ui_img_ble_png.d ./ui/ui_img_ble_png.o ./ui/ui_img_ble_png.su ./ui/ui_img_circle_png.d ./ui/ui_img_circle_png.o ./ui/ui_img_circle_png.su ./ui/ui_img_corner_png.d ./ui/ui_img_corner_png.o ./ui/ui_img_corner_png.su ./ui/ui_img_ellips_png.d ./ui/ui_img_ellips_png.o ./ui/ui_img_ellips_png.su ./ui/ui_img_info_png.d ./ui/ui_img_info_png.o ./ui/ui_img_info_png.su ./ui/ui_img_pattern_png.d ./ui/ui_img_pattern_png.o ./ui/ui_img_pattern_png.su ./ui/ui_img_time_png.d ./ui/ui_img_time_png.o ./ui/ui_img_time_png.su ./ui/ui_img_wifi_png.d ./ui/ui_img_wifi_png.o ./ui/ui_img_wifi_png.su

.PHONY: clean-ui

