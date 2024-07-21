################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../L293B.c \
../adc.c \
../flex_sensor.c \
../gpio.c \
../lcd.c \
../main.c \
../uart.c 

OBJS += \
./L293B.o \
./adc.o \
./flex_sensor.o \
./gpio.o \
./lcd.o \
./main.o \
./uart.o 

C_DEPS += \
./L293B.d \
./adc.d \
./flex_sensor.d \
./gpio.d \
./lcd.d \
./main.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


