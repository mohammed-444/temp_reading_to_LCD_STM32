################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/adc.c \
../driver/src/external_intrupt.c \
../driver/src/gpio.c \
../driver/src/keypad.c \
../driver/src/lcd.c \
../driver/src/lm35_sensor.c 

OBJS += \
./driver/src/adc.o \
./driver/src/external_intrupt.o \
./driver/src/gpio.o \
./driver/src/keypad.o \
./driver/src/lcd.o \
./driver/src/lm35_sensor.o 

C_DEPS += \
./driver/src/adc.d \
./driver/src/external_intrupt.d \
./driver/src/gpio.d \
./driver/src/keypad.d \
./driver/src/lcd.d \
./driver/src/lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o: ../driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"E:/SBME3/second term/embedded/workspace/ADC/driver/inc" -I"E:/SBME3/second term/embedded/workspace/ADC/inc" -I"E:/SBME3/second term/embedded/workspace/ADC/CMSIS/device" -I"E:/SBME3/second term/embedded/workspace/ADC/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


