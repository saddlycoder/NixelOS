/*
  NixelOS Kernel
  
  module name: Kernel.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
//Подключаем библиотеки C++
#include "../../include/stdint.h"
#include "../../include/io.h"
#include "../../include/stdbool.h"

#include "IxDraw/NixelDraw.h"

void kmain(void)
{
	//--------------------------START--------------------//
    clear();
	print("NixelOS kernel v1.0",0x2);

	while(1);
}