/*
  NixelOS Kernel
  
  module name: Kernel.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include "IxDraw/NixelDraw.h"

void kmain(void)
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;
	
	//--------------------------START--------------------
	print("NixelOS kernel v1.0",0x2);
	while(1);
}