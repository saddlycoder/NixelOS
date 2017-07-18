/*
  NixelOS Kernel
  
  module name: Kernel.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#if !defined(__cplusplus)
#include <stdbool.h> 
#endif
#include <stddef.h>
#include <stdint.h>


#include "kernel.h"

void kmain(void)
{

	//--------------------------MAIN--------------------//
    clear();
	terminal_initialize();
	
	command_init();
    
	/* This end of kernel
       userinit initialising	
	   system to work
	*/
    //userinit(302524);
	while(1);
}
    //-------------------INITIALISING MODES---------------//
void userinit(int USMOD)
{
	if (USMOD = 302524)
	{
        print("[kernel] You are switched to rootmode",0x6);
	}
	if (USMOD = 564530)
	{
        print("[kernel] You are switched to protectedmode",0x6);
	}
	if (USMOD = 234215)
	{
        print("[kernel] You are switched to usermode",0x6);
	}	
}