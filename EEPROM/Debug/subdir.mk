################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../I2C.c \
../KeyPad.c \
../LCD.c \
../SPI_Slave_C_file.c \
../eeprom.c \
../main.c 

OBJS += \
./DIO.o \
./I2C.o \
./KeyPad.o \
./LCD.o \
./SPI_Slave_C_file.o \
./eeprom.o \
./main.o 

C_DEPS += \
./DIO.d \
./I2C.d \
./KeyPad.d \
./LCD.d \
./SPI_Slave_C_file.d \
./eeprom.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


