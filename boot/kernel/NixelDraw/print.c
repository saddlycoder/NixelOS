/*
  NixelOS Kernel
  
  module name: print.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include "print.h"


void print(char* message, int color)
{
	char* mem = (char*)(0xb8000);
	while(*message != 0)
	{
	   *mem = *message;
        mem++;
        message++;
        *mem = (char*)color;
		mem++;
	}
}

