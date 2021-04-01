################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
timer0_ICU_dutyT0.lss \

FLASH_IMAGE += \
timer0_ICU_dutyT0.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: timer0_ICU_dutyT0.elf secondary-outputs

# Tool invocations
timer0_ICU_dutyT0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,timer0_ICU_dutyT0.map -mmcu=atmega32 -o "timer0_ICU_dutyT0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

timer0_ICU_dutyT0.lss: timer0_ICU_dutyT0.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S timer0_ICU_dutyT0.elf  >"timer0_ICU_dutyT0.lss"
	@echo 'Finished building: $@'
	@echo ' '

timer0_ICU_dutyT0.hex: timer0_ICU_dutyT0.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex timer0_ICU_dutyT0.elf  "timer0_ICU_dutyT0.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: timer0_ICU_dutyT0.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 timer0_ICU_dutyT0.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: timer0_ICU_dutyT0.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:timer0_ICU_dutyT0.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) timer0_ICU_dutyT0.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
