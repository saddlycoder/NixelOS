
  [BITS 16]
  [ORG 0x7c00] 
start:
  cli 
  xor ax,ax
  mov ss,ax 
  mov sp,0x7c00                 
  mov si,sp 
  push ax                     
  pop es  
  push ax   
  pop ds  
  sti
  
  ; копируем MBR 0x600
  cld               
  mov di,0x600  
  mov cx,0x100  
  repne movsw   
   
  jmp word 0x0:code_start-0x7600
code_start:
  mov byte [0x7dfe],00 
  mov si,0x7be 
  
  
  push cs  
  push cs  
  push dword [si+8] 
  push cs
  push word 0x7c00 
	
  push byte 1
  push byte 0x10 
  mov si, sp
	
  mov ah, 0x42 
  mov dl, 0x80 
  int 0x13
	
  jnc read_ok
	
  mov si, err_reading-0x7600 
	
show_message:	
  lodsb              	
  cmp al,0x0
  jz infinite_loop

  push si                       
  mov bx,0x7  
  mov ah,0xe  
  int 0x10
  pop si 
  jmp show_message 
infinite_loop:
  jmp short $  
	
read_ok:
  cmp word [0x7dfe], 0xaa55 
  jz start_os

  mov si, err_signature-0x7600
  jmp show_message
	
start_os:
  jmp word 0x0:0x7c00 
	
err_reading:
  db '[MBR]Error Reading Boot Sector',0
err_signature:
  db '[MBR]Incorrect signature',0	
	
finish:
  times 0x1FE-finish+start db 0
  db   0x55, 0xaa   