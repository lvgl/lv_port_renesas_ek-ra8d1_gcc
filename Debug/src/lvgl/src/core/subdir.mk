################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/core/lv_group.c \
../src/lvgl/src/core/lv_obj.c \
../src/lvgl/src/core/lv_obj_class.c \
../src/lvgl/src/core/lv_obj_draw.c \
../src/lvgl/src/core/lv_obj_event.c \
../src/lvgl/src/core/lv_obj_id_builtin.c \
../src/lvgl/src/core/lv_obj_pos.c \
../src/lvgl/src/core/lv_obj_property.c \
../src/lvgl/src/core/lv_obj_scroll.c \
../src/lvgl/src/core/lv_obj_style.c \
../src/lvgl/src/core/lv_obj_style_gen.c \
../src/lvgl/src/core/lv_obj_tree.c \
../src/lvgl/src/core/lv_refr.c 

C_DEPS += \
./src/lvgl/src/core/lv_group.d \
./src/lvgl/src/core/lv_obj.d \
./src/lvgl/src/core/lv_obj_class.d \
./src/lvgl/src/core/lv_obj_draw.d \
./src/lvgl/src/core/lv_obj_event.d \
./src/lvgl/src/core/lv_obj_id_builtin.d \
./src/lvgl/src/core/lv_obj_pos.d \
./src/lvgl/src/core/lv_obj_property.d \
./src/lvgl/src/core/lv_obj_scroll.d \
./src/lvgl/src/core/lv_obj_style.d \
./src/lvgl/src/core/lv_obj_style_gen.d \
./src/lvgl/src/core/lv_obj_tree.d \
./src/lvgl/src/core/lv_refr.d 

OBJS += \
./src/lvgl/src/core/lv_group.o \
./src/lvgl/src/core/lv_obj.o \
./src/lvgl/src/core/lv_obj_class.o \
./src/lvgl/src/core/lv_obj_draw.o \
./src/lvgl/src/core/lv_obj_event.o \
./src/lvgl/src/core/lv_obj_id_builtin.o \
./src/lvgl/src/core/lv_obj_pos.o \
./src/lvgl/src/core/lv_obj_property.o \
./src/lvgl/src/core/lv_obj_scroll.o \
./src/lvgl/src/core/lv_obj_style.o \
./src/lvgl/src/core/lv_obj_style_gen.o \
./src/lvgl/src/core/lv_obj_tree.o \
./src/lvgl/src/core/lv_refr.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/core/%.o: ../src/lvgl/src/core/%.c src/lvgl/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-core

clean-src-2f-lvgl-2f-src-2f-core:
	-$(RM) ./src/lvgl/src/core/lv_group.d ./src/lvgl/src/core/lv_group.o ./src/lvgl/src/core/lv_obj.d ./src/lvgl/src/core/lv_obj.o ./src/lvgl/src/core/lv_obj_class.d ./src/lvgl/src/core/lv_obj_class.o ./src/lvgl/src/core/lv_obj_draw.d ./src/lvgl/src/core/lv_obj_draw.o ./src/lvgl/src/core/lv_obj_event.d ./src/lvgl/src/core/lv_obj_event.o ./src/lvgl/src/core/lv_obj_id_builtin.d ./src/lvgl/src/core/lv_obj_id_builtin.o ./src/lvgl/src/core/lv_obj_pos.d ./src/lvgl/src/core/lv_obj_pos.o ./src/lvgl/src/core/lv_obj_property.d ./src/lvgl/src/core/lv_obj_property.o ./src/lvgl/src/core/lv_obj_scroll.d ./src/lvgl/src/core/lv_obj_scroll.o ./src/lvgl/src/core/lv_obj_style.d ./src/lvgl/src/core/lv_obj_style.o ./src/lvgl/src/core/lv_obj_style_gen.d ./src/lvgl/src/core/lv_obj_style_gen.o ./src/lvgl/src/core/lv_obj_tree.d ./src/lvgl/src/core/lv_obj_tree.o ./src/lvgl/src/core/lv_refr.d ./src/lvgl/src/core/lv_refr.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-core

