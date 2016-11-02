################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f7xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f7xx.o: D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Include" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


