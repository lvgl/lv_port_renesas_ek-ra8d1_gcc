################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_grad.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_math.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_path.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_pending.c \
../src/lvgl/src/draw/vg_lite/lv_vg_lite_utils.c 

C_DEPS += \
./src/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_math.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_path.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d 

OBJS += \
./src/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_math.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_path.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o \
./src/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/draw/vg_lite/%.o: ../src/lvgl/src/draw/vg_lite/%.c src/lvgl/src/draw/vg_lite/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-draw-2f-vg_lite

clean-src-2f-lvgl-2f-src-2f-draw-2f-vg_lite:
	-$(RM) ./src/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d ./src/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d ./src/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_math.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_math.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_path.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_path.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o ./src/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d ./src/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-draw-2f-vg_lite

