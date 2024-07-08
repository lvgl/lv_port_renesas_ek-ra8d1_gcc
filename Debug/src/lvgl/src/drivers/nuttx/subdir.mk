################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/drivers/nuttx/lv_nuttx_cache.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_entry.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_lcd.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_libuv.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_profiler.c \
../src/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.c 

C_DEPS += \
./src/lvgl/src/drivers/nuttx/lv_nuttx_cache.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_entry.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_lcd.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_libuv.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_profiler.d \
./src/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.d 

OBJS += \
./src/lvgl/src/drivers/nuttx/lv_nuttx_cache.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_entry.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_lcd.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_libuv.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_profiler.o \
./src/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/drivers/nuttx/%.o: ../src/lvgl/src/drivers/nuttx/%.c src/lvgl/src/drivers/nuttx/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-drivers-2f-nuttx

clean-src-2f-lvgl-2f-src-2f-drivers-2f-nuttx:
	-$(RM) ./src/lvgl/src/drivers/nuttx/lv_nuttx_cache.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_cache.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_entry.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_entry.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_lcd.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_lcd.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_libuv.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_libuv.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_profiler.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_profiler.o ./src/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.d ./src/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-drivers-2f-nuttx

