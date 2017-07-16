/*
  NixelOS Kernel
  
  module name: print.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

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