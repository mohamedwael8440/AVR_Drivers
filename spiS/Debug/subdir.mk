################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATmega32_SPI_Slave.c \
../DIO.c \
../LCD.c \
../SPI_Slave_C_file.c 

OBJS += \
./ATmega32_SPI_Slave.o \
./DIO.o \
./LCD.o \
./SPI_Slave_C_file.o 

C_DEPS += \
./ATmega32_SPI_Slave.d \
./DIO.d \
./LCD.d \
./SPI_Slave_C_file.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


