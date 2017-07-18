global loader
extern _kmain
MODULEALIGN equ 1<<0
MEMINFO equ 1<<1
GRAPH equ 1<<2 
FLAGS equ  MODULEALIGN | MEMINFO | GRAPH
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .text
align 4
MultiBootHeader:
dd MAGIC
dd FLAGS
dd CHECKSUM
dd 0, 0, 0, 0, 0
dd 0
dd 1024, 768, 32

STACKSIZE equ 0x4000

loader:
   mov esp,stack+STACKSIZE
   push eax
   push ebx
	
   jmp _kmain
   
   cli
   
hang:
   hlt
   jmp hang
   

section .bss
align 4
stack:
 resb STACKSIZE