CPP = g++
CC = gcc
LD = ld
FLAGS = -Wall -c -m32 -nostdlib -fno-builtin
CPPFLAGS = -fno-rtti -fno-exceptions -Wno-write-strings
CCFLAGS = 
LDFLAGS = -lm -lpthread

all: loader support util kernel link grub run

loader: loader.s
	as --32 $< -o loader.o

support: support.cpp
	$(CPP) $(FLAGS) $(CPPFLAGS) $<

util: util.c
	$(CC) $(FLAGS) $(CCFLAGS) $<

kernel: kernel.cpp
	$(CPP) $(FLAGS) $(CPPFLAGS) $^

link: 
	$(LD) $(LDFLAGS) loader.o support.o util.o kernel.o v8/libv8.a -o kernel /usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5/libgcc.a

clean:
	rm *.o
	rm kernel

grub:
	cp kernel ./iso/boot/kernel
	grub-mkrescue -o w8.iso ./iso

run:
	qemu -cdrom w8.iso

.PHONY: all clean run kernel
