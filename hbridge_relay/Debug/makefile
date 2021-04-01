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
hbridge_relay.lss \

FLASH_IMAGE += \
hbridge_relay.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: hbridge_relay.elf secondary-outputs

# Tool invocations
hbridge_relay.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,hbridge_relay.map -mmcu=atmega32 -o "hbridge_relay.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

hbridge_relay.lss: hbridge_relay.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S hbridge_relay.elf  >"hbridge_relay.lss"
	@echo 'Finished building: $@'
	@echo ' '

hbridge_relay.hex: hbridge_relay.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex hbridge_relay.elf  "hbridge_relay.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: hbridge_relay.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 hbridge_relay.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: hbridge_relay.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:hbridge_relay.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) hbridge_relay.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
