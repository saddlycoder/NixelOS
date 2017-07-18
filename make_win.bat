@echo off
@echo ***NixelOS Windows Compiler***

@echo Part 1.Compiling boot loaders
    dev\compillers\nasm -O0 -f bin -o binary/mbr.bin boot/loader/mbr.asm
@echo Part 2.Compiling kernel
    dev\compillers\nasm -f elf32 -o binary/kasm.elf boot/kernel/kasm.asm
    dev\compillers\mingw\bin\gcc -c boot/kernel/kernel.c -o binary/kernel.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
    dev\compillers\mingw\bin\gcc -c boot/kernel/tty.c -o binary/tty.o -Wall -Wextra -std=c99 -nostdlib -nostartfiles -nodefaultlibs -m32
    dev\compillers\mingw\bin\gcc -c boot/kernel/kbd.c -o binary/kbd.o -Wall -Wextra -std=c99 -nostdlib -nostartfiles -nodefaultlibs -m32
    dev\compillers\mingw\bin\gcc -c boot/kernel/io.c -o binary/io.o -Wall -Wextra -std=c99 -nostdlib -nostartfiles -nodefaultlibs -m32
    dev\compillers\mingw\bin\gcc -c boot/kernel/console.c -o binary/console.o -Wall -Wextra -std=c99 -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\gcc -c boot/kernel/NixelDraw/print.c -o binary/print.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\gcc -c boot/kernel/NixelDraw/cls.c -o binary/cls.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\gcc -c boot/kernel/NixelDraw/graphics.c -o binary/graphics.o -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32
	dev\compillers\mingw\bin\ld -Tlink.ld -o binary/krnl.out binary/kernel.o binary/cls.o binary/print.o binary/kbd.o binary/tty.o binary/io.o binary/console.o binary/graphics.o binary/kasm.elf
    dev\compillers\mingw\bin\objcopy -I elf32-i386 binary/krnl.out binary/kernel 
@echo ***NixelOS Windows Compiler***
@pause