################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/draw/lv_draw.c \
../src/lvgl/src/draw/lv_draw_arc.c \
../src/lvgl/src/draw/lv_draw_buf.c \
../src/lvgl/src/draw/lv_draw_image.c \
../src/lvgl/src/draw/lv_draw_label.c \
../src/lvgl/src/draw/lv_draw_line.c \
../src/lvgl/src/draw/lv_draw_mask.c \
../src/lvgl/src/draw/lv_draw_rect.c \
../src/lvgl/src/draw/lv_draw_triangle.c \
../src/lvgl/src/draw/lv_draw_vector.c \
../src/lvgl/src/draw/lv_image_decoder.c 

C_DEPS += \
./src/lvgl/src/draw/lv_draw.d \
./src/lvgl/src/draw/lv_draw_arc.d \
./src/lvgl/src/draw/lv_draw_buf.d \
./src/lvgl/src/draw/lv_draw_image.d \
./src/lvgl/src/draw/lv_draw_label.d \
./src/lvgl/src/draw/lv_draw_line.d \
./src/lvgl/src/draw/lv_draw_mask.d \
./src/lvgl/src/draw/lv_draw_rect.d \
./src/lvgl/src/draw/lv_draw_triangle.d \
./src/lvgl/src/draw/lv_draw_vector.d \
./src/lvgl/src/draw/lv_image_decoder.d 

OBJS += \
./src/lvgl/src/draw/lv_draw.o \
./src/lvgl/src/draw/lv_draw_arc.o \
./src/lvgl/src/draw/lv_draw_buf.o \
./src/lvgl/src/draw/lv_draw_image.o \
./src/lvgl/src/draw/lv_draw_label.o \
./src/lvgl/src/draw/lv_draw_line.o \
./src/lvgl/src/draw/lv_draw_mask.o \
./src/lvgl/src/draw/lv_draw_rect.o \
./src/lvgl/src/draw/lv_draw_triangle.o \
./src/lvgl/src/draw/lv_draw_vector.o \
./src/lvgl/src/draw/lv_image_decoder.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/draw/%.o: ../src/lvgl/src/draw/%.c src/lvgl/src/draw/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-draw

clean-src-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./src/lvgl/src/draw/lv_draw.d ./src/lvgl/src/draw/lv_draw.o ./src/lvgl/src/draw/lv_draw_arc.d ./src/lvgl/src/draw/lv_draw_arc.o ./src/lvgl/src/draw/lv_draw_buf.d ./src/lvgl/src/draw/lv_draw_buf.o ./src/lvgl/src/draw/lv_draw_image.d ./src/lvgl/src/draw/lv_draw_image.o ./src/lvgl/src/draw/lv_draw_label.d ./src/lvgl/src/draw/lv_draw_label.o ./src/lvgl/src/draw/lv_draw_line.d ./src/lvgl/src/draw/lv_draw_line.o ./src/lvgl/src/draw/lv_draw_mask.d ./src/lvgl/src/draw/lv_draw_mask.o ./src/lvgl/src/draw/lv_draw_rect.d ./src/lvgl/src/draw/lv_draw_rect.o ./src/lvgl/src/draw/lv_draw_triangle.d ./src/lvgl/src/draw/lv_draw_triangle.o ./src/lvgl/src/draw/lv_draw_vector.d ./src/lvgl/src/draw/lv_draw_vector.o ./src/lvgl/src/draw/lv_image_decoder.d ./src/lvgl/src/draw/lv_image_decoder.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-draw

