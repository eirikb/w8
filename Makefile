CC = gcc
LD = ld
AS = as
CPP = g++


CPPOPTS	= -m32 -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions -c

VIDEO_OBJ = video.o

all: offsetof bootblock createimage kernel process1 process2 image
all: video kernel grub

video: video.o
	$(CPP) $(CPPOPTS) -o video.o

kernel: $(KERNEL_OBJS)
	$(CPP) $(CPPOPTS) video.o -o kernel

grub:
	cp kernel ./iso/boot/kernel;
	grub-mkrescue -o w8.iso ./iso

# How to compile a C file
%.o:%.c
	$(CC) $(CCOPTS) $<

# How to assemble
%.o:%.s
	$(CC) $(CCOPTS) $<

# How to produce assembler input from a C file
%.s:%.c
	$(CC) $(CCOPTS) -S $<

# Include dependencies (the leading dash prevents
# warnings if the file doesn't exist)
-include .depend
