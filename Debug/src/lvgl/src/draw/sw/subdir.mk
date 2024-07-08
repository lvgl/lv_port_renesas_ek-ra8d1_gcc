################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/draw/sw/lv_draw_sw.c \
../src/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../src/lvgl/src/draw/sw/lv_draw_sw_border.c \
../src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.c \
../src/lvgl/src/draw/sw/lv_draw_sw_fill.c \
../src/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../src/lvgl/src/draw/sw/lv_draw_sw_img.c \
../src/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../src/lvgl/src/draw/sw/lv_draw_sw_line.c \
../src/lvgl/src/draw/sw/lv_draw_sw_mask.c \
../src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.c \
../src/lvgl/src/draw/sw/lv_draw_sw_transform.c \
../src/lvgl/src/draw/sw/lv_draw_sw_triangle.c \
../src/lvgl/src/draw/sw/lv_draw_sw_vector.c 

C_DEPS += \
./src/lvgl/src/draw/sw/lv_draw_sw.d \
./src/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./src/lvgl/src/draw/sw/lv_draw_sw_border.d \
./src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d \
./src/lvgl/src/draw/sw/lv_draw_sw_fill.d \
./src/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./src/lvgl/src/draw/sw/lv_draw_sw_img.d \
./src/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./src/lvgl/src/draw/sw/lv_draw_sw_line.d \
./src/lvgl/src/draw/sw/lv_draw_sw_mask.d \
./src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d \
./src/lvgl/src/draw/sw/lv_draw_sw_transform.d \
./src/lvgl/src/draw/sw/lv_draw_sw_triangle.d \
./src/lvgl/src/draw/sw/lv_draw_sw_vector.d 

OBJS += \
./src/lvgl/src/draw/sw/lv_draw_sw.o \
./src/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./src/lvgl/src/draw/sw/lv_draw_sw_border.o \
./src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o \
./src/lvgl/src/draw/sw/lv_draw_sw_fill.o \
./src/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./src/lvgl/src/draw/sw/lv_draw_sw_img.o \
./src/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./src/lvgl/src/draw/sw/lv_draw_sw_line.o \
./src/lvgl/src/draw/sw/lv_draw_sw_mask.o \
./src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o \
./src/lvgl/src/draw/sw/lv_draw_sw_transform.o \
./src/lvgl/src/draw/sw/lv_draw_sw_triangle.o \
./src/lvgl/src/draw/sw/lv_draw_sw_vector.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/draw/sw/%.o: ../src/lvgl/src/draw/sw/%.c src/lvgl/src/draw/sw/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-draw-2f-sw

clean-src-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./src/lvgl/src/draw/sw/lv_draw_sw.d ./src/lvgl/src/draw/sw/lv_draw_sw.o ./src/lvgl/src/draw/sw/lv_draw_sw_arc.d ./src/lvgl/src/draw/sw/lv_draw_sw_arc.o ./src/lvgl/src/draw/sw/lv_draw_sw_border.d ./src/lvgl/src/draw/sw/lv_draw_sw_border.o ./src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d ./src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o ./src/lvgl/src/draw/sw/lv_draw_sw_fill.d ./src/lvgl/src/draw/sw/lv_draw_sw_fill.o ./src/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./src/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./src/lvgl/src/draw/sw/lv_draw_sw_img.d ./src/lvgl/src/draw/sw/lv_draw_sw_img.o ./src/lvgl/src/draw/sw/lv_draw_sw_letter.d ./src/lvgl/src/draw/sw/lv_draw_sw_letter.o ./src/lvgl/src/draw/sw/lv_draw_sw_line.d ./src/lvgl/src/draw/sw/lv_draw_sw_line.o ./src/lvgl/src/draw/sw/lv_draw_sw_mask.d ./src/lvgl/src/draw/sw/lv_draw_sw_mask.o ./src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d ./src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o ./src/lvgl/src/draw/sw/lv_draw_sw_transform.d ./src/lvgl/src/draw/sw/lv_draw_sw_transform.o ./src/lvgl/src/draw/sw/lv_draw_sw_triangle.d ./src/lvgl/src/draw/sw/lv_draw_sw_triangle.o ./src/lvgl/src/draw/sw/lv_draw_sw_vector.d ./src/lvgl/src/draw/sw/lv_draw_sw_vector.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-draw-2f-sw

