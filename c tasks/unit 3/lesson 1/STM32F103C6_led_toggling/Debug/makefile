################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
led_toggling.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
led_toggling.list \

OBJCOPY_HEX += \
led_toggling.hex \

OBJCOPY_BIN += \
led_toggling.bin \


# All Target
all: led_toggling.elf secondary-outputs

# Tool invocations
led_toggling.elf: $(OBJS) $(USER_OBJS) C:\Users\Sence79\Desktop\led_toggling\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "led_toggling.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Sence79\Desktop\led_toggling\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="led_toggling.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

led_toggling.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "led_toggling.list"
	@echo 'Finished building: $@'
	@echo ' '

led_toggling.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "led_toggling.hex"
	@echo 'Finished building: $@'
	@echo ' '

led_toggling.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "led_toggling.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
