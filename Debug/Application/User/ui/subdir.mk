################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/ui/font_14.c \
../Application/User/ui/ui.c \
../Application/User/ui/ui_comp.c \
../Application/User/ui/ui_helpers.c \
../Application/User/ui/ui_img_aircon_png.c \
../Application/User/ui/ui_img_back_png.c \
../Application/User/ui/ui_img_battery_png.c \
../Application/User/ui/ui_img_ble_png.c \
../Application/User/ui/ui_img_circle_png.c \
../Application/User/ui/ui_img_corner_png.c \
../Application/User/ui/ui_img_ellips_png.c \
../Application/User/ui/ui_img_info_png.c \
../Application/User/ui/ui_img_pattern_png.c \
../Application/User/ui/ui_img_time_png.c \
../Application/User/ui/ui_img_wifi_png.c 

OBJS += \
./Application/User/ui/font_14.o \
./Application/User/ui/ui.o \
./Application/User/ui/ui_comp.o \
./Application/User/ui/ui_helpers.o \
./Application/User/ui/ui_img_aircon_png.o \
./Application/User/ui/ui_img_back_png.o \
./Application/User/ui/ui_img_battery_png.o \
./Application/User/ui/ui_img_ble_png.o \
./Application/User/ui/ui_img_circle_png.o \
./Application/User/ui/ui_img_corner_png.o \
./Application/User/ui/ui_img_ellips_png.o \
./Application/User/ui/ui_img_info_png.o \
./Application/User/ui/ui_img_pattern_png.o \
./Application/User/ui/ui_img_time_png.o \
./Application/User/ui/ui_img_wifi_png.o 

C_DEPS += \
./Application/User/ui/font_14.d \
./Application/User/ui/ui.d \
./Application/User/ui/ui_comp.d \
./Application/User/ui/ui_helpers.d \
./Application/User/ui/ui_img_aircon_png.d \
./Application/User/ui/ui_img_back_png.d \
./Application/User/ui/ui_img_battery_png.d \
./Application/User/ui/ui_img_ble_png.d \
./Application/User/ui/ui_img_circle_png.d \
./Application/User/ui/ui_img_corner_png.d \
./Application/User/ui/ui_img_ellips_png.d \
./Application/User/ui/ui_img_info_png.d \
./Application/User/ui/ui_img_pattern_png.d \
./Application/User/ui/ui_img_time_png.d \
./Application/User/ui/ui_img_wifi_png.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/ui/%.o Application/User/ui/%.su: ../Application/User/ui/%.c Application/User/ui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Drivers/STM32G0xx_HAL_Driver/Inc/Legacy" -I"/home/kisvegabor/projects/st/cert/cubeide-workspace/lv_port_stm_nucleo_g071rb/Application/User/Core/Inc" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-ui

clean-Application-2f-User-2f-ui:
	-$(RM) ./Application/User/ui/font_14.d ./Application/User/ui/font_14.o ./Application/User/ui/font_14.su ./Application/User/ui/ui.d ./Application/User/ui/ui.o ./Application/User/ui/ui.su ./Application/User/ui/ui_comp.d ./Application/User/ui/ui_comp.o ./Application/User/ui/ui_comp.su ./Application/User/ui/ui_helpers.d ./Application/User/ui/ui_helpers.o ./Application/User/ui/ui_helpers.su ./Application/User/ui/ui_img_aircon_png.d ./Application/User/ui/ui_img_aircon_png.o ./Application/User/ui/ui_img_aircon_png.su ./Application/User/ui/ui_img_back_png.d ./Application/User/ui/ui_img_back_png.o ./Application/User/ui/ui_img_back_png.su ./Application/User/ui/ui_img_battery_png.d ./Application/User/ui/ui_img_battery_png.o ./Application/User/ui/ui_img_battery_png.su ./Application/User/ui/ui_img_ble_png.d ./Application/User/ui/ui_img_ble_png.o ./Application/User/ui/ui_img_ble_png.su ./Application/User/ui/ui_img_circle_png.d ./Application/User/ui/ui_img_circle_png.o ./Application/User/ui/ui_img_circle_png.su ./Application/User/ui/ui_img_corner_png.d ./Application/User/ui/ui_img_corner_png.o ./Application/User/ui/ui_img_corner_png.su ./Application/User/ui/ui_img_ellips_png.d ./Application/User/ui/ui_img_ellips_png.o ./Application/User/ui/ui_img_ellips_png.su ./Application/User/ui/ui_img_info_png.d ./Application/User/ui/ui_img_info_png.o ./Application/User/ui/ui_img_info_png.su ./Application/User/ui/ui_img_pattern_png.d ./Application/User/ui/ui_img_pattern_png.o ./Application/User/ui/ui_img_pattern_png.su ./Application/User/ui/ui_img_time_png.d ./Application/User/ui/ui_img_time_png.o ./Application/User/ui/ui_img_time_png.su ./Application/User/ui/ui_img_wifi_png.d ./Application/User/ui/ui_img_wifi_png.o ./Application/User/ui/ui_img_wifi_png.su

.PHONY: clean-Application-2f-User-2f-ui

