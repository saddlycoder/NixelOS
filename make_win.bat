@echo off
@echo ***NixelOS Windows Compiler***

@echo Part 1.Compiling boot loaders
    dev\compillers\nasm -O0 -f bin -o binary/mbr.bin boot/loader/mbr.asm
@echo Part 2.Compiling kernel
    dev\compillers\nasm -f elf32 -o binary/kasm.elf boot/kernel/kasm.asm
    dev\compillers\mingw\bin\gcc -c boot/kernel/kernel.c -o binary/kernel.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\gcc -c boot/kernel/NixelDraw/print.c -o binary/print.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\gcc -c boot/kernel/NixelDraw/cls.c -o binary/cls.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\ld -Tlink.ld -o binary/krnl.out binary/kernel.o binary/cls.o binary/print.o binary/kasm.elf
    dev\compillers\mingw\bin\objcopy -I elf32-i386 binary/krnl.out binary/kernel 
@echo ***NixelOS Windows Compiler***
@pause