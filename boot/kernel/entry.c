/*
*  kernel.c
*/

void kernel_main(); // функция ядра

void kernel_entry() {
   kernel_main(); // передадим ей управление
}