################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/src/misc/lv_anim.c \
../src/lvgl/src/misc/lv_anim_timeline.c \
../src/lvgl/src/misc/lv_area.c \
../src/lvgl/src/misc/lv_array.c \
../src/lvgl/src/misc/lv_async.c \
../src/lvgl/src/misc/lv_bidi.c \
../src/lvgl/src/misc/lv_color.c \
../src/lvgl/src/misc/lv_color_op.c \
../src/lvgl/src/misc/lv_event.c \
../src/lvgl/src/misc/lv_fs.c \
../src/lvgl/src/misc/lv_ll.c \
../src/lvgl/src/misc/lv_log.c \
../src/lvgl/src/misc/lv_lru.c \
../src/lvgl/src/misc/lv_math.c \
../src/lvgl/src/misc/lv_palette.c \
../src/lvgl/src/misc/lv_profiler_builtin.c \
../src/lvgl/src/misc/lv_rb.c \
../src/lvgl/src/misc/lv_style.c \
../src/lvgl/src/misc/lv_style_gen.c \
../src/lvgl/src/misc/lv_templ.c \
../src/lvgl/src/misc/lv_text.c \
../src/lvgl/src/misc/lv_text_ap.c \
../src/lvgl/src/misc/lv_timer.c \
../src/lvgl/src/misc/lv_utils.c 

C_DEPS += \
./src/lvgl/src/misc/lv_anim.d \
./src/lvgl/src/misc/lv_anim_timeline.d \
./src/lvgl/src/misc/lv_area.d \
./src/lvgl/src/misc/lv_array.d \
./src/lvgl/src/misc/lv_async.d \
./src/lvgl/src/misc/lv_bidi.d \
./src/lvgl/src/misc/lv_color.d \
./src/lvgl/src/misc/lv_color_op.d \
./src/lvgl/src/misc/lv_event.d \
./src/lvgl/src/misc/lv_fs.d \
./src/lvgl/src/misc/lv_ll.d \
./src/lvgl/src/misc/lv_log.d \
./src/lvgl/src/misc/lv_lru.d \
./src/lvgl/src/misc/lv_math.d \
./src/lvgl/src/misc/lv_palette.d \
./src/lvgl/src/misc/lv_profiler_builtin.d \
./src/lvgl/src/misc/lv_rb.d \
./src/lvgl/src/misc/lv_style.d \
./src/lvgl/src/misc/lv_style_gen.d \
./src/lvgl/src/misc/lv_templ.d \
./src/lvgl/src/misc/lv_text.d \
./src/lvgl/src/misc/lv_text_ap.d \
./src/lvgl/src/misc/lv_timer.d \
./src/lvgl/src/misc/lv_utils.d 

OBJS += \
./src/lvgl/src/misc/lv_anim.o \
./src/lvgl/src/misc/lv_anim_timeline.o \
./src/lvgl/src/misc/lv_area.o \
./src/lvgl/src/misc/lv_array.o \
./src/lvgl/src/misc/lv_async.o \
./src/lvgl/src/misc/lv_bidi.o \
./src/lvgl/src/misc/lv_color.o \
./src/lvgl/src/misc/lv_color_op.o \
./src/lvgl/src/misc/lv_event.o \
./src/lvgl/src/misc/lv_fs.o \
./src/lvgl/src/misc/lv_ll.o \
./src/lvgl/src/misc/lv_log.o \
./src/lvgl/src/misc/lv_lru.o \
./src/lvgl/src/misc/lv_math.o \
./src/lvgl/src/misc/lv_palette.o \
./src/lvgl/src/misc/lv_profiler_builtin.o \
./src/lvgl/src/misc/lv_rb.o \
./src/lvgl/src/misc/lv_style.o \
./src/lvgl/src/misc/lv_style_gen.o \
./src/lvgl/src/misc/lv_templ.o \
./src/lvgl/src/misc/lv_text.o \
./src/lvgl/src/misc/lv_text_ap.o \
./src/lvgl/src/misc/lv_timer.o \
./src/lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/misc/%.o: ../src/lvgl/src/misc/%.c src/lvgl/src/misc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-misc

clean-src-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./src/lvgl/src/misc/lv_anim.d ./src/lvgl/src/misc/lv_anim.o ./src/lvgl/src/misc/lv_anim_timeline.d ./src/lvgl/src/misc/lv_anim_timeline.o ./src/lvgl/src/misc/lv_area.d ./src/lvgl/src/misc/lv_area.o ./src/lvgl/src/misc/lv_array.d ./src/lvgl/src/misc/lv_array.o ./src/lvgl/src/misc/lv_async.d ./src/lvgl/src/misc/lv_async.o ./src/lvgl/src/misc/lv_bidi.d ./src/lvgl/src/misc/lv_bidi.o ./src/lvgl/src/misc/lv_color.d ./src/lvgl/src/misc/lv_color.o ./src/lvgl/src/misc/lv_color_op.d ./src/lvgl/src/misc/lv_color_op.o ./src/lvgl/src/misc/lv_event.d ./src/lvgl/src/misc/lv_event.o ./src/lvgl/src/misc/lv_fs.d ./src/lvgl/src/misc/lv_fs.o ./src/lvgl/src/misc/lv_ll.d ./src/lvgl/src/misc/lv_ll.o ./src/lvgl/src/misc/lv_log.d ./src/lvgl/src/misc/lv_log.o ./src/lvgl/src/misc/lv_lru.d ./src/lvgl/src/misc/lv_lru.o ./src/lvgl/src/misc/lv_math.d ./src/lvgl/src/misc/lv_math.o ./src/lvgl/src/misc/lv_palette.d ./src/lvgl/src/misc/lv_palette.o ./src/lvgl/src/misc/lv_profiler_builtin.d ./src/lvgl/src/misc/lv_profiler_builtin.o ./src/lvgl/src/misc/lv_rb.d ./src/lvgl/src/misc/lv_rb.o ./src/lvgl/src/misc/lv_style.d ./src/lvgl/src/misc/lv_style.o ./src/lvgl/src/misc/lv_style_gen.d ./src/lvgl/src/misc/lv_style_gen.o ./src/lvgl/src/misc/lv_templ.d ./src/lvgl/src/misc/lv_templ.o ./src/lvgl/src/misc/lv_text.d ./src/lvgl/src/misc/lv_text.o ./src/lvgl/src/misc/lv_text_ap.d ./src/lvgl/src/misc/lv_text_ap.o ./src/lvgl/src/misc/lv_timer.d ./src/lvgl/src/misc/lv_timer.o ./src/lvgl/src/misc/lv_utils.d ./src/lvgl/src/misc/lv_utils.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-misc

