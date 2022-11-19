################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART/subdir.mk
-include LCD/subdir.mk
-include GIE/subdir.mk
-include ADC/subdir.mk
-include 01-DIO/subdir.mk
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
Tesla.lss \

FLASH_IMAGE += \
Tesla.hex \

EEPROM_IMAGE += \
Tesla.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tesla.elf secondary-outputs

# Tool invocations
Tesla.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tesla.map -mmcu=atmega32 -o "Tesla.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tesla.lss: Tesla.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tesla.elf  >"Tesla.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tesla.hex: Tesla.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Tesla.elf  "Tesla.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tesla.eep: Tesla.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tesla.elf  "Tesla.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tesla.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tesla.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Tesla.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
