################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../src/lvgl/examples/widgets/chart/lv_example_chart_8.c 

C_DEPS += \
./src/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./src/lvgl/examples/widgets/chart/lv_example_chart_8.d 

OBJS += \
./src/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./src/lvgl/examples/widgets/chart/lv_example_chart_8.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/examples/widgets/chart/%.o: ../src/lvgl/examples/widgets/chart/%.c src/lvgl/examples/widgets/chart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-src-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./src/lvgl/examples/widgets/chart/lv_example_chart_1.d ./src/lvgl/examples/widgets/chart/lv_example_chart_1.o ./src/lvgl/examples/widgets/chart/lv_example_chart_2.d ./src/lvgl/examples/widgets/chart/lv_example_chart_2.o ./src/lvgl/examples/widgets/chart/lv_example_chart_3.d ./src/lvgl/examples/widgets/chart/lv_example_chart_3.o ./src/lvgl/examples/widgets/chart/lv_example_chart_4.d ./src/lvgl/examples/widgets/chart/lv_example_chart_4.o ./src/lvgl/examples/widgets/chart/lv_example_chart_5.d ./src/lvgl/examples/widgets/chart/lv_example_chart_5.o ./src/lvgl/examples/widgets/chart/lv_example_chart_6.d ./src/lvgl/examples/widgets/chart/lv_example_chart_6.o ./src/lvgl/examples/widgets/chart/lv_example_chart_7.d ./src/lvgl/examples/widgets/chart/lv_example_chart_7.o ./src/lvgl/examples/widgets/chart/lv_example_chart_8.d ./src/lvgl/examples/widgets/chart/lv_example_chart_8.o

.PHONY: clean-src-2f-lvgl-2f-examples-2f-widgets-2f-chart

