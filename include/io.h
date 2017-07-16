/*
  NixelOS Kernel
  
  module name: io.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#ifndef __IO_H
#define __IO_H
#include <stdint.h>
#include <stdbool.h>
#define PIC1 0x20
#define PIC2 0xA0
#define ICW1 0x11
#define ICW4 0x01
#define PIC1		0x20		
#define PIC2		0xA0		
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

uint8_t  inb(uint16_t port);                
uint16_t inw(uint16_t port);                
uint32_t inl(uint16_t port);                
void     outb(uint16_t port, uint8_t  val); 
void     outw(uint16_t port, uint16_t val); 
void     outl(uint16_t port, uint32_t val); 
uint64_t rdtsc();                          
void init_pics(int pic1, int pic2);
 
void insl(unsigned short port, unsigned int buffer, unsigned long count);
#endif
