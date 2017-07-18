/*
  NixelOS Kernel
  
  module name: console.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "console.h"

void command_init()
{
	terminal_writestring('usr@/etc/home : # >');
	kbd_wap();
}