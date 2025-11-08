# MCU and toolchain settings
MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

# List of projects (subdirectories)
PROJECTS = gpio_read_pin mpu6050_example1

.PHONY: all $(PROJECTS) clean
# Default target: build all projects
all: $(PROJECTS)

# Rule to build each project
$(PROJECTS):
	$(MAKE) -C $@

# Clean all projects
clean:
	for d in $(PROJECTS); do \
	    	$(MAKE) -C $$d clean; \
		done
