/*
  NixelOS Kernel
  
  module name: graphics.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/

#include "graphics.h"

/* only valid for 800x600x16M */
void putpixel2(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*3 + y*2400;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}
 
/* only valid for 800x600x32bpp */
void putpixel(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*4 + y*3200;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}

