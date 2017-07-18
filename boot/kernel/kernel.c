/*
  NixelOS Kernel
  
  module name: Kernel.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>


#include "kernel.h"

void kmain(void)
{

	//--------------------------MAIN--------------------//
    clear();
	terminal_initialize();
    print("NixelOS Kernel loaded",0x4);	
	
    kbd_wap();

	

	while(1);
}

