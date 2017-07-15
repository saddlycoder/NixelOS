;регистр dl cодержит номер загрузочного диска!

[BITS 16]
;======== Копируем самого себя по адресу 0000:0600h ===================
    mov ax, 7C0h
    mov ds, ax
    xor si, si

    mov ax, 60h
    mov es, ax
    xor di, di

    mov cx, 0FFh ;в cx лежит число повторений функции копирования слов

    ;[DS:SI] => [ES:DI]; SI += 2; DI += 2;
    rep movsw

    ;Передаем управление на новое расположение кода
    jmp 0000:0618h

;======== Приветствуем пользователя ===================================
	  mov ax, hello_msg_1
	  call print
	  mov ax, hello_msg_2
	  call print

;======== Проверяем таблицу разделов ===================================
	  mov si, [part_adr]
	  mov bh, 80h

	  mov cl, -1
partitions_chek:
	  cmp cl, 3			   ;если уже было проверено 4 записи, выходим из цикла и переходим к обработке записей
	  je partition_select

	  add si, 10h
	  inc cl

	  mov bl, [es:si]
	  cmp bl, bh
	  jne partitions_chek		   ;запись не является загрузочной

	  call partitions_process	   ;запись загрузочная!
					   ;[es:si] содержит адрес записи в таблице разделов
					   ;cl - номер раздела

	  jmp partitions_chek

;======== Подпрограмма вывода инофрмации об активном разделе =============================
partitions_process:
	  mov ax, boot_part_msg
	  call print

	  mov di, part_num
	  add [ds:di], cl
	  mov ax, part_num
	  call print
	  sub [ds:di], cl

	  mov di, boot_flags
	  mov ch, 0
	  add di, cx
	  mov byte[ds:di], 1

	  ret;
;=======================================================================

partition_select:
	  ;Обрабатываем пользовательский ввод
	  mov ax, select_part_msg
	  call print

choise:   mov di, boot_flags
	  mov si, [part_adr]

	  mov ah, 0
	  int 16h

p0:	  cmp al, 48
	  jne p1
	  add si, 10h
	  jmp disk

p1:	  cmp al, 49
	  jne p2
	  add si, 20h
	  jmp disk

p2:	  cmp al, 50
	  jne p3
	  add si, 30h
	  jmp disk

p3:	  add si, 40h
	  cmp al, 51
	  je disk

wrong_choise:
	  mov ax, wrong_input_msg
	  call print
	  jmp choise

disk:	  mov ah, 0
	  sub al, 48		      ; сначала проверка, выбрал ли пользователь действительно загрузочный раздел
	  add di, ax
	  cmp byte [ds:di], 0
	  je wrong_choise
				      ; по [es:si] содержится запись таблицы разделов
				      ; о выбранном загрузочном диске

	  mov ah, 41h		      ; проверка поддержки диском расширенного режима (> 8 GB)
				      ; dl содержит номер диска
	  mov bx, 55AAh
	  int 13h
	  jc  ext_not_present_error
	  shr  cx, 1
	  jnb  ext_not_present_error
	  cmp  bx, 0AA55h
	  je   read_boot_sect

ext_not_present_error:
	  mov ax, ext_not_pres_msg
	  call print
	  int 18h

read_boot_sect:
	  mov ah, 42h
	  mov di, DAP_structure
	  add di, 8
	  add si, 8
	  mov ebx, [ds:si]
	  mov [ds:di], ebx
	  mov si, DAP_structure
	  int 13h
	  jc  ext_not_present_error

	  jmp 0000:7C00h
;======== Подпрограмма вывода сообщений ================================
print:
	  push si
	  push bx

	  mov bx, ax
	  xor si, si
	  mov ah, 0Eh

p:	  mov al, [bx + si]
	  cmp al, 0Ah
	  int 10h

	  je end_print

	  inc si
	  jmp p

end_print:
	  pop bx
	  pop si
	  ret

;=======================================================================
hello_msg_1	 db '===========================================', 0Dh, 0Ah
hello_msg_2	 db '*PupokLoader 00.01*', 0Dh, 0Ah
boot_part_msg	 db 'Find bootable partitions:', 0Dh, 0Ah
select_part_msg  db 'Select part to boot from (press 0 ... 3)', 0Dh, 0Ah
wrong_input_msg  db 'Wrong choise. Try again', 0Dh, 0Ah
ext_not_pres_msg db 'a disk read error occured', 0Dh, 0Ah
part_num	 db '0', 0Dh, 0Ah
part_adr	 dw 1AEh
boot_flags	 db 4
DAP_structure	 db 10h, 0, 1, 0, 0, 7Ch, 0, 0, 8
 