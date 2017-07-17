/*
  NixelOS Kernel
  
  module name: print.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#ifndef PRINT_H
#define PRINT_H

void print(char* message, int color);
void update_cursor(int row, int col);
#endif