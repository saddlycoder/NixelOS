/*
  NixelOS Kernel
  
  module name: cls.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

void clear()
{
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;


	while(j < 80 * 25 * 2) {

		vidptr[j] = ' ';

		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;
}