################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

C_DEPS += \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d 

OBJS += \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/demos/multilang/assets/avatars/%.o: ../src/lvgl/demos/multilang/assets/avatars/%.c src/lvgl/demos/multilang/assets/avatars/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

clean-src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars:
	-$(RM) ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d ./src/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o

.PHONY: clean-src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

