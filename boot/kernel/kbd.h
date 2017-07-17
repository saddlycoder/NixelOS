/*
  NixelOS Kernel
  
  module name: kbd.h
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#ifndef KBD_H
#define KBD_H

void kbd_ack(void);
void kbd_led_handling(int ledstatus);
#endif