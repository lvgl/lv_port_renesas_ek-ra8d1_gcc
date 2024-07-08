################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lvgl/src/libs/fsdrv/lv_fs_arduino_esp_littlefs.cpp 

C_SRCS += \
../src/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
../src/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
../src/lvgl/src/libs/fsdrv/lv_fs_littlefs.c \
../src/lvgl/src/libs/fsdrv/lv_fs_memfs.c \
../src/lvgl/src/libs/fsdrv/lv_fs_posix.c \
../src/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
../src/lvgl/src/libs/fsdrv/lv_fs_win32.c 

CPP_DEPS += \
./src/lvgl/src/libs/fsdrv/lv_fs_arduino_esp_littlefs.d 

C_DEPS += \
./src/lvgl/src/libs/fsdrv/lv_fs_cbfs.d \
./src/lvgl/src/libs/fsdrv/lv_fs_fatfs.d \
./src/lvgl/src/libs/fsdrv/lv_fs_littlefs.d \
./src/lvgl/src/libs/fsdrv/lv_fs_memfs.d \
./src/lvgl/src/libs/fsdrv/lv_fs_posix.d \
./src/lvgl/src/libs/fsdrv/lv_fs_stdio.d \
./src/lvgl/src/libs/fsdrv/lv_fs_win32.d 

OBJS += \
./src/lvgl/src/libs/fsdrv/lv_fs_arduino_esp_littlefs.o \
./src/lvgl/src/libs/fsdrv/lv_fs_cbfs.o \
./src/lvgl/src/libs/fsdrv/lv_fs_fatfs.o \
./src/lvgl/src/libs/fsdrv/lv_fs_littlefs.o \
./src/lvgl/src/libs/fsdrv/lv_fs_memfs.o \
./src/lvgl/src/libs/fsdrv/lv_fs_posix.o \
./src/lvgl/src/libs/fsdrv/lv_fs_stdio.o \
./src/lvgl/src/libs/fsdrv/lv_fs_win32.o 


# Each subdirectory must supply rules for building sources it contributes
src/lvgl/src/libs/fsdrv/%.o: ../src/lvgl/src/libs/fsdrv/%.cpp src/lvgl/src/libs/fsdrv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lvgl/src/libs/fsdrv/%.o: ../src/lvgl/src/libs/fsdrv/%.c src/lvgl/src/libs/fsdrv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Helper/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/Arm-2D/Library/Include" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl/tests" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include" -O3 -g -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-lvgl-2f-src-2f-libs-2f-fsdrv

clean-src-2f-lvgl-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./src/lvgl/src/libs/fsdrv/lv_fs_arduino_esp_littlefs.d ./src/lvgl/src/libs/fsdrv/lv_fs_arduino_esp_littlefs.o ./src/lvgl/src/libs/fsdrv/lv_fs_cbfs.d ./src/lvgl/src/libs/fsdrv/lv_fs_cbfs.o ./src/lvgl/src/libs/fsdrv/lv_fs_fatfs.d ./src/lvgl/src/libs/fsdrv/lv_fs_fatfs.o ./src/lvgl/src/libs/fsdrv/lv_fs_littlefs.d ./src/lvgl/src/libs/fsdrv/lv_fs_littlefs.o ./src/lvgl/src/libs/fsdrv/lv_fs_memfs.d ./src/lvgl/src/libs/fsdrv/lv_fs_memfs.o ./src/lvgl/src/libs/fsdrv/lv_fs_posix.d ./src/lvgl/src/libs/fsdrv/lv_fs_posix.o ./src/lvgl/src/libs/fsdrv/lv_fs_stdio.d ./src/lvgl/src/libs/fsdrv/lv_fs_stdio.o ./src/lvgl/src/libs/fsdrv/lv_fs_win32.d ./src/lvgl/src/libs/fsdrv/lv_fs_win32.o

.PHONY: clean-src-2f-lvgl-2f-src-2f-libs-2f-fsdrv

