CPP = g++
CPPOPTS	= -lm -m32 -lpthread -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions -Wno-write-strings

all: kernel grub run

kernel: console.cpp kernel.cpp
	$(CPP) $(CPPOPTS) loader.s -o kernel $^ v8/libv8.a -lgcc

clean:
	rm kernel

grub:
	cp kernel ./iso/boot/kernel
	grub-mkrescue -o w8.iso ./iso

run:
	qemu -cdrom w8.iso

.PHONY: all clean run
