@echo off
@echo ***NixelOS Windows Compiler***

@echo Part 1.Compiling boot loaders
    dev\compillers\nasm -O0 -f bin -o binary/mbr.bin boot/loader/mbr.asm
@echo Part 2.Compiling kernel
    dev\compillers\mingw\bin\gcc -c boot/kernel/kernel.c -o binary/kernel.o
	dev\compillers\mingw\bin\ld -o binary/krnl.out binary/kernel.o -nostdlib
    dev\compillers\mingw\bin\objcopy -I elf32-i386 binary/krnl.out binary/kernel 
@echo ***NixelOS Windows Compiler***
@pause