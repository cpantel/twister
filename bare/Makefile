AVRDEVICE=m328p

BURNER=usbasp

FUSES=lfuse:w:0xE2:m

BINPATH=/home/carlos/bin

GCCPATH=$(BINPATH)/arduino-1.8.10+teensy/hardware/tools/avr/bin

all: twister.c
	$(GCCPATH)/avr-gcc -mmcu=atmega328p -Wall -std=gnu99 -Os -o twister.elf twister.c && \
	$(GCCPATH)/avr-objcopy -j .text -j .data -O ihex twister.elf twister.hex

clean:
	rm twister.elf twister.hex

burnUSB:
	avrdude -p $(AVRDEVICE) -c $(BURNER) -e -F -U flash:w:twister.hex -U $(FUSES) -C /etc/avrdude.conf
