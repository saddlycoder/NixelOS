@echo off
@echo ***NixelOS Windows Compiler***

@echo Part 1.Compile MBR
    dev\compillers\nasm -O0 -f bin -o binary/mbr.bin boot/loader/mbr.asm
@echo Part 2.Compile Kernel
 
@echo ***NixelOS Windows Compiler***
@pause