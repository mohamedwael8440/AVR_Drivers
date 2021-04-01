################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../SEG_HAL.c \
../clk.c \
../lcd.c \
../main.c \
../timer.c 

OBJS += \
./DIO.o \
./SEG_HAL.o \
./clk.o \
./lcd.o \
./main.o \
./timer.o 

C_DEPS += \
./DIO.d \
./SEG_HAL.d \
./clk.d \
./lcd.d \
./main.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


