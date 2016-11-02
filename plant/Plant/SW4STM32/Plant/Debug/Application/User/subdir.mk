################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/dc_model.c \
D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/main.c \
D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/stm32f7xx_hal_msp.c \
D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/stm32f7xx_it.c 

OBJS += \
./Application/User/dc_model.o \
./Application/User/main.o \
./Application/User/stm32f7xx_hal_msp.o \
./Application/User/stm32f7xx_it.o 

C_DEPS += \
./Application/User/dc_model.d \
./Application/User/main.d \
./Application/User/stm32f7xx_hal_msp.d \
./Application/User/stm32f7xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Include" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Include" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_hal_msp.o: D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/stm32f7xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Include" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_it.o: D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Src/stm32f7xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Include" -I"D:/STUDIA/semestr9/WSSiSS_projekt/plant/Plant/Drivers/CMSIS/Device/ST/STM32F7xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


