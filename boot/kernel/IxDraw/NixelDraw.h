/*
  NixelOS Kernel
  
  module name: NixelDraw.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#define VW 80 // Ширина экрана
#define VH 25 // Его высота
#define RAM 0xb8000 // Видеопамять

int cur; // Где находится курсор
int param; // Параметры

#include "print.h"
#include "cls.h"