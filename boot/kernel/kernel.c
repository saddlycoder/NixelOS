/*
  NixelOS Kernel
  
  module name: Kernel.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

#include "kernel.h"

void kmain(void)
{

	//--------------------------START--------------------//
    clear();
	print("NixelOS kernel v1.0",0x2);

	while(1);
}