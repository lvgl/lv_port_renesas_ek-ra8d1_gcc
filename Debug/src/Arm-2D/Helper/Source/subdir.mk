################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Arm-2D/Helper/Source/GLCD_Fonts.c \
../src/Arm-2D/Helper/Source/WhiteDotSmall.c \
../src/Arm-2D/Helper/Source/arm_2d_helper.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_built_in.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_control.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_font.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_list.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_map.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_pfb.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_scene.c \
../src/Arm-2D/Helper/Source/arm_2d_helper_shape.c \
../src/Arm-2D/Helper/Source/busy_wheel.c \
../src/Arm-2D/Helper/Source/cmsis_logo.c \
../src/Arm-2D/Helper/Source/console_box.c 

C_DEPS += \
./src/Arm-2D/Helper/Source/GLCD_Fonts.d \
./src/Arm-2D/Helper/Source/WhiteDotSmall.d \
./src/Arm-2D/Helper/Source/arm_2d_helper.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_built_in.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_control.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_font.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_list.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_map.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_pfb.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_scene.d \
./src/Arm-2D/Helper/Source/arm_2d_helper_shape.d \
./src/Arm-2D/Helper/Source/busy_wheel.d \
./src/Arm-2D/Helper/Source/cmsis_logo.d \
./src/Arm-2D/Helper/Source/console_box.d 

OBJS += \
./src/Arm-2D/Helper/Source/GLCD_Fonts.o \
./src/Arm-2D/Helper/Source/WhiteDotSmall.o \
./src/Arm-2D/Helper/Source/arm_2d_helper.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_built_in.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_control.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_font.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_list.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_map.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_pfb.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_scene.o \
./src/Arm-2D/Helper/Source/arm_2d_helper_shape.o \
./src/Arm-2D/Helper/Source/busy_wheel.o \
./src/Arm-2D/Helper/Source/cmsis_logo.o \
./src/Arm-2D/Helper/Source/console_box.o 


# Each subdirectory must supply rules for building sources it contributes
src/Arm-2D/Helper/Source/%.o: ../src/Arm-2D/Helper/Source/%.c src/Arm-2D/Helper/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_renesas/lv_ek_ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_renesas/lv_ek_ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Arm-2d-2D-2f-Helper-2f-Source

clean-src-2f-Arm-2d-2D-2f-Helper-2f-Source:
	-$(RM) ./src/Arm-2D/Helper/Source/GLCD_Fonts.d ./src/Arm-2D/Helper/Source/GLCD_Fonts.o ./src/Arm-2D/Helper/Source/WhiteDotSmall.d ./src/Arm-2D/Helper/Source/WhiteDotSmall.o ./src/Arm-2D/Helper/Source/arm_2d_helper.d ./src/Arm-2D/Helper/Source/arm_2d_helper.o ./src/Arm-2D/Helper/Source/arm_2d_helper_built_in.d ./src/Arm-2D/Helper/Source/arm_2d_helper_built_in.o ./src/Arm-2D/Helper/Source/arm_2d_helper_control.d ./src/Arm-2D/Helper/Source/arm_2d_helper_control.o ./src/Arm-2D/Helper/Source/arm_2d_helper_font.d ./src/Arm-2D/Helper/Source/arm_2d_helper_font.o ./src/Arm-2D/Helper/Source/arm_2d_helper_list.d ./src/Arm-2D/Helper/Source/arm_2d_helper_list.o ./src/Arm-2D/Helper/Source/arm_2d_helper_map.d ./src/Arm-2D/Helper/Source/arm_2d_helper_map.o ./src/Arm-2D/Helper/Source/arm_2d_helper_pfb.d ./src/Arm-2D/Helper/Source/arm_2d_helper_pfb.o ./src/Arm-2D/Helper/Source/arm_2d_helper_scene.d ./src/Arm-2D/Helper/Source/arm_2d_helper_scene.o ./src/Arm-2D/Helper/Source/arm_2d_helper_shape.d ./src/Arm-2D/Helper/Source/arm_2d_helper_shape.o ./src/Arm-2D/Helper/Source/busy_wheel.d ./src/Arm-2D/Helper/Source/busy_wheel.o ./src/Arm-2D/Helper/Source/cmsis_logo.d ./src/Arm-2D/Helper/Source/cmsis_logo.o ./src/Arm-2D/Helper/Source/console_box.d ./src/Arm-2D/Helper/Source/console_box.o

.PHONY: clean-src-2f-Arm-2d-2D-2f-Helper-2f-Source

