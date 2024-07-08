################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.c \
../src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.c 

C_DEPS += \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d 

OBJS += \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o \
./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/draw/renesas/dave2d/%.o: ../src/lvgl/src/draw/renesas/dave2d/%.c src/lvgl/src/draw/renesas/dave2d/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d

clean-src-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d:
	-$(RM) ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d ./src/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d

