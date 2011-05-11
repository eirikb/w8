CPP = g++

CPPOPTS	= -m32 -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions

all: video kernel grub

video: video.cpp
	$(CPP) $(CPPOPTS) -o video.o $^

kernel: kernel.cpp
	$(CPP) $(CPPOPTS) loader.S video.o -o kernel $^

grub:
	cp kernel ./iso/boot/kernel
	grub-mkrescue -o w8.iso ./iso

run:
	qemu -cdrom w8.iso

.PHONY: all run
