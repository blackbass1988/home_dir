default target:all
all:
	avr-gcc -mmcu=atmega32 -std=gnu99 -Wall -Os -o blink.elf blink.c 
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex
load:
	sudo avrdude -c usbasp -p m32 -e -U flash:w:blink.hex
