/*
  NixelOS Kernel
  
  module name: io.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

#ifndef IO_H
#define IO_H
void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);

#endif
