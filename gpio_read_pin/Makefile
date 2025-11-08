MCU=atmega328p
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy

CFLAGS=-mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

all: main.hex

main.elf: main.c
    $(CC) $(CFLAGS) -o $@ $<

main.hex: main.elf
    $(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
    rm -f *.elf *.hex
