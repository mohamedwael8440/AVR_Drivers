################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../LED.c \
../croutine.c \
../event_groups.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../regtest.c \
../stream_buffer.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO.o \
./LED.o \
./croutine.o \
./event_groups.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./regtest.o \
./stream_buffer.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO.d \
./LED.d \
./croutine.d \
./event_groups.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./regtest.d \
./stream_buffer.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


