################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.c 

OBJS += \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.o 

C_DEPS += \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H747I-DISCO/%.o Drivers/BSP/STM32H747I-DISCO/%.su Drivers/BSP/STM32H747I-DISCO/%.cyclo: ../Drivers/BSP/STM32H747I-DISCO/%.c Drivers/BSP/STM32H747I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I"E:/STM_Git_Workspace/STM32/747_2/CM7/Drivers/BSP/STM32H747I-DISCO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO

clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO:
	-$(RM) ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO

