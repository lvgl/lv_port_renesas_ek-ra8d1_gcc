################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/tes/dave2d/src/dave_64bitoperation.c \
../ra/tes/dave2d/src/dave_base.c \
../ra/tes/dave2d/src/dave_blit.c \
../ra/tes/dave2d/src/dave_box.c \
../ra/tes/dave2d/src/dave_circle.c \
../ra/tes/dave2d/src/dave_context.c \
../ra/tes/dave2d/src/dave_curve.c \
../ra/tes/dave2d/src/dave_dlist.c \
../ra/tes/dave2d/src/dave_driver.c \
../ra/tes/dave2d/src/dave_edge.c \
../ra/tes/dave2d/src/dave_errorcodes.c \
../ra/tes/dave2d/src/dave_gradient.c \
../ra/tes/dave2d/src/dave_hardware.c \
../ra/tes/dave2d/src/dave_line.c \
../ra/tes/dave2d/src/dave_math.c \
../ra/tes/dave2d/src/dave_memory.c \
../ra/tes/dave2d/src/dave_pattern.c \
../ra/tes/dave2d/src/dave_perfcount.c \
../ra/tes/dave2d/src/dave_polyline.c \
../ra/tes/dave2d/src/dave_quad.c \
../ra/tes/dave2d/src/dave_rbuffer.c \
../ra/tes/dave2d/src/dave_render.c \
../ra/tes/dave2d/src/dave_texture.c \
../ra/tes/dave2d/src/dave_triangle.c \
../ra/tes/dave2d/src/dave_utility.c \
../ra/tes/dave2d/src/dave_viewport.c \
../ra/tes/dave2d/src/dave_wedge.c 

C_DEPS += \
./ra/tes/dave2d/src/dave_64bitoperation.d \
./ra/tes/dave2d/src/dave_base.d \
./ra/tes/dave2d/src/dave_blit.d \
./ra/tes/dave2d/src/dave_box.d \
./ra/tes/dave2d/src/dave_circle.d \
./ra/tes/dave2d/src/dave_context.d \
./ra/tes/dave2d/src/dave_curve.d \
./ra/tes/dave2d/src/dave_dlist.d \
./ra/tes/dave2d/src/dave_driver.d \
./ra/tes/dave2d/src/dave_edge.d \
./ra/tes/dave2d/src/dave_errorcodes.d \
./ra/tes/dave2d/src/dave_gradient.d \
./ra/tes/dave2d/src/dave_hardware.d \
./ra/tes/dave2d/src/dave_line.d \
./ra/tes/dave2d/src/dave_math.d \
./ra/tes/dave2d/src/dave_memory.d \
./ra/tes/dave2d/src/dave_pattern.d \
./ra/tes/dave2d/src/dave_perfcount.d \
./ra/tes/dave2d/src/dave_polyline.d \
./ra/tes/dave2d/src/dave_quad.d \
./ra/tes/dave2d/src/dave_rbuffer.d \
./ra/tes/dave2d/src/dave_render.d \
./ra/tes/dave2d/src/dave_texture.d \
./ra/tes/dave2d/src/dave_triangle.d \
./ra/tes/dave2d/src/dave_utility.d \
./ra/tes/dave2d/src/dave_viewport.d \
./ra/tes/dave2d/src/dave_wedge.d 

OBJS += \
./ra/tes/dave2d/src/dave_64bitoperation.o \
./ra/tes/dave2d/src/dave_base.o \
./ra/tes/dave2d/src/dave_blit.o \
./ra/tes/dave2d/src/dave_box.o \
./ra/tes/dave2d/src/dave_circle.o \
./ra/tes/dave2d/src/dave_context.o \
./ra/tes/dave2d/src/dave_curve.o \
./ra/tes/dave2d/src/dave_dlist.o \
./ra/tes/dave2d/src/dave_driver.o \
./ra/tes/dave2d/src/dave_edge.o \
./ra/tes/dave2d/src/dave_errorcodes.o \
./ra/tes/dave2d/src/dave_gradient.o \
./ra/tes/dave2d/src/dave_hardware.o \
./ra/tes/dave2d/src/dave_line.o \
./ra/tes/dave2d/src/dave_math.o \
./ra/tes/dave2d/src/dave_memory.o \
./ra/tes/dave2d/src/dave_pattern.o \
./ra/tes/dave2d/src/dave_perfcount.o \
./ra/tes/dave2d/src/dave_polyline.o \
./ra/tes/dave2d/src/dave_quad.o \
./ra/tes/dave2d/src/dave_rbuffer.o \
./ra/tes/dave2d/src/dave_render.o \
./ra/tes/dave2d/src/dave_texture.o \
./ra/tes/dave2d/src/dave_triangle.o \
./ra/tes/dave2d/src/dave_utility.o \
./ra/tes/dave2d/src/dave_viewport.o \
./ra/tes/dave2d/src/dave_wedge.o 


# Each subdirectory must supply rules for building sources it contributes
ra/tes/dave2d/src/%.o: ../ra/tes/dave2d/src/%.c ra/tes/dave2d/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -O3 -g -w -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-ra-2f-tes-2f-dave2d-2f-src

clean-ra-2f-tes-2f-dave2d-2f-src:
	-$(RM) ./ra/tes/dave2d/src/dave_64bitoperation.d ./ra/tes/dave2d/src/dave_64bitoperation.o ./ra/tes/dave2d/src/dave_base.d ./ra/tes/dave2d/src/dave_base.o ./ra/tes/dave2d/src/dave_blit.d ./ra/tes/dave2d/src/dave_blit.o ./ra/tes/dave2d/src/dave_box.d ./ra/tes/dave2d/src/dave_box.o ./ra/tes/dave2d/src/dave_circle.d ./ra/tes/dave2d/src/dave_circle.o ./ra/tes/dave2d/src/dave_context.d ./ra/tes/dave2d/src/dave_context.o ./ra/tes/dave2d/src/dave_curve.d ./ra/tes/dave2d/src/dave_curve.o ./ra/tes/dave2d/src/dave_dlist.d ./ra/tes/dave2d/src/dave_dlist.o ./ra/tes/dave2d/src/dave_driver.d ./ra/tes/dave2d/src/dave_driver.o ./ra/tes/dave2d/src/dave_edge.d ./ra/tes/dave2d/src/dave_edge.o ./ra/tes/dave2d/src/dave_errorcodes.d ./ra/tes/dave2d/src/dave_errorcodes.o ./ra/tes/dave2d/src/dave_gradient.d ./ra/tes/dave2d/src/dave_gradient.o ./ra/tes/dave2d/src/dave_hardware.d ./ra/tes/dave2d/src/dave_hardware.o ./ra/tes/dave2d/src/dave_line.d ./ra/tes/dave2d/src/dave_line.o ./ra/tes/dave2d/src/dave_math.d ./ra/tes/dave2d/src/dave_math.o ./ra/tes/dave2d/src/dave_memory.d ./ra/tes/dave2d/src/dave_memory.o ./ra/tes/dave2d/src/dave_pattern.d ./ra/tes/dave2d/src/dave_pattern.o ./ra/tes/dave2d/src/dave_perfcount.d ./ra/tes/dave2d/src/dave_perfcount.o ./ra/tes/dave2d/src/dave_polyline.d ./ra/tes/dave2d/src/dave_polyline.o ./ra/tes/dave2d/src/dave_quad.d ./ra/tes/dave2d/src/dave_quad.o ./ra/tes/dave2d/src/dave_rbuffer.d ./ra/tes/dave2d/src/dave_rbuffer.o ./ra/tes/dave2d/src/dave_render.d ./ra/tes/dave2d/src/dave_render.o ./ra/tes/dave2d/src/dave_texture.d ./ra/tes/dave2d/src/dave_texture.o ./ra/tes/dave2d/src/dave_triangle.d ./ra/tes/dave2d/src/dave_triangle.o ./ra/tes/dave2d/src/dave_utility.d ./ra/tes/dave2d/src/dave_utility.o ./ra/tes/dave2d/src/dave_viewport.d ./ra/tes/dave2d/src/dave_viewport.o ./ra/tes/dave2d/src/dave_wedge.d ./ra/tes/dave2d/src/dave_wedge.o

.PHONY: clean-ra-2f-tes-2f-dave2d-2f-src

