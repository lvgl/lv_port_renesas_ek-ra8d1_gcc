################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables.c \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.c \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs.c \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.c \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables.c \
../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.c 

C_DEPS += \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables.d \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.d \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs.d \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.d \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables.d \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.d 

OBJS += \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables.o \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.o \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs.o \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.o \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables.o \
./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.o 


# Each subdirectory must supply rules for building sources it contributes
ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/%.o: ../ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/%.c ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 6.22'
	armclang --target=arm-arm-none-eabi -mcpu=cortex-m85 -fvectorize -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src" -I"." -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/api" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/inc/instances" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/fsp/src/rm_freertos_port" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_gen" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg/bsp" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/fsp_cfg" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra_cfg/aws" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/tes/dave2d/inc" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/src/lvgl" -O3 -g -w -Omax -flto -Wno-int-conversion -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-unused-but-set-variable -Wfloat-equal -Waggregate-return -Wshadow -Wpointer-arith -Wconversion -Wmissing-declarations -Wuninitialized -Wunused -Wno-license-management -Wextra -Wno-implicit-int-conversion -Wno-sign-conversion -mfloat-abi=hard -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/Include/" -I"/home/kisvegabor/projects/lvgl/e2_studio-workspace/lv_port_renesas_ek-ra8d1/ra/arm/CMSIS_5/CMSIS/DSP/PrivateInclude/" -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-ra-2f-arm-2f-CMSIS_5-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables

clean-ra-2f-arm-2f-CMSIS_5-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables:
	-$(RM) ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables.o ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_common_tables_f16.o ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs.o ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_const_structs_f16.o ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables.o ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.d ./ra/arm/CMSIS_5/CMSIS/DSP/Source/CommonTables/arm_mve_tables_f16.o

.PHONY: clean-ra-2f-arm-2f-CMSIS_5-2f-CMSIS-2f-DSP-2f-Source-2f-CommonTables

