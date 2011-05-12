.global _start
# setting up the Multiboot header - see GRUB docs for details
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum required

.align 4
.long MAGIC

_start:
    mov   $(stack + STACKSIZE), %esp # set up the stack
    push  %eax                       # Multiboot magic number
    push  %ebx                       # Multiboot data structure

    call  main # call kernel proper
    cli
hang:
    hlt                    # halt machine should kernel return
    jmp   hang
