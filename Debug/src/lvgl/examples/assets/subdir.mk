################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/examples/assets/animimg001.c \
../src/lvgl/examples/assets/animimg002.c \
../src/lvgl/examples/assets/animimg003.c \
../src/lvgl/examples/assets/img_caret_down.c \
../src/lvgl/examples/assets/img_cogwheel_argb.c \
../src/lvgl/examples/assets/img_cogwheel_indexed16.c \
../src/lvgl/examples/assets/img_cogwheel_rgb.c \
../src/lvgl/examples/assets/img_hand.c \
../src/lvgl/examples/assets/img_skew_strip.c \
../src/lvgl/examples/assets/img_star.c \
../src/lvgl/examples/assets/imgbtn_left.c \
../src/lvgl/examples/assets/imgbtn_mid.c \
../src/lvgl/examples/assets/imgbtn_right.c 

C_DEPS += \
./src/lvgl/examples/assets/animimg001.d \
./src/lvgl/examples/assets/animimg002.d \
./src/lvgl/examples/assets/animimg003.d \
./src/lvgl/examples/assets/img_caret_down.d \
./src/lvgl/examples/assets/img_cogwheel_argb.d \
./src/lvgl/examples/assets/img_cogwheel_indexed16.d \
./src/lvgl/examples/assets/img_cogwheel_rgb.d \
./src/lvgl/examples/assets/img_hand.d \
./src/lvgl/examples/assets/img_skew_strip.d \
./src/lvgl/examples/assets/img_star.d \
./src/lvgl/examples/assets/imgbtn_left.d \
./src/lvgl/examples/assets/imgbtn_mid.d \
./src/lvgl/examples/assets/imgbtn_right.d 

OBJS += \
./src/lvgl/examples/assets/animimg001.o \
./src/lvgl/examples/assets/animimg002.o \
./src/lvgl/examples/assets/animimg003.o \
./src/lvgl/examples/assets/img_caret_down.o \
./src/lvgl/examples/assets/img_cogwheel_argb.o \
./src/lvgl/examples/assets/img_cogwheel_indexed16.o \
./src/lvgl/examples/assets/img_cogwheel_rgb.o \
./src/lvgl/examples/assets/img_hand.o \
./src/lvgl/examples/assets/img_skew_strip.o \
./src/lvgl/examples/assets/img_star.o \
./src/lvgl/examples/assets/imgbtn_left.o \
./src/lvgl/examples/assets/imgbtn_mid.o \
./src/lvgl/examples/assets/imgbtn_right.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/examples/assets/%.o: ../src/lvgl/examples/assets/%.c src/lvgl/examples/assets/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-examples-2f-assets

clean-src-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./src/lvgl/examples/assets/animimg001.d ./src/lvgl/examples/assets/animimg001.o ./src/lvgl/examples/assets/animimg002.d ./src/lvgl/examples/assets/animimg002.o ./src/lvgl/examples/assets/animimg003.d ./src/lvgl/examples/assets/animimg003.o ./src/lvgl/examples/assets/img_caret_down.d ./src/lvgl/examples/assets/img_caret_down.o ./src/lvgl/examples/assets/img_cogwheel_argb.d ./src/lvgl/examples/assets/img_cogwheel_argb.o ./src/lvgl/examples/assets/img_cogwheel_indexed16.d ./src/lvgl/examples/assets/img_cogwheel_indexed16.o ./src/lvgl/examples/assets/img_cogwheel_rgb.d ./src/lvgl/examples/assets/img_cogwheel_rgb.o ./src/lvgl/examples/assets/img_hand.d ./src/lvgl/examples/assets/img_hand.o ./src/lvgl/examples/assets/img_skew_strip.d ./src/lvgl/examples/assets/img_skew_strip.o ./src/lvgl/examples/assets/img_star.d ./src/lvgl/examples/assets/img_star.o ./src/lvgl/examples/assets/imgbtn_left.d ./src/lvgl/examples/assets/imgbtn_left.o ./src/lvgl/examples/assets/imgbtn_mid.d ./src/lvgl/examples/assets/imgbtn_mid.o ./src/lvgl/examples/assets/imgbtn_right.d ./src/lvgl/examples/assets/imgbtn_right.o

.PHONY: clean-src-2f-lvgl-2f-examples-2f-assets

