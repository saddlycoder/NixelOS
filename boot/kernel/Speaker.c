/*
  NixelOS Kernel
  
  module name: Speaker.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "Speaker.h"

/*
   Нота     Малая октава      Первая октава     Вторая октава      Третья октава
   до          130.810           261.630            523.250           1046.500
  до #         138.590           277.180            554.370
   ре          146.830           293.660            587.330
  ре #         155.560           311.130            622.260
   ми          164.810           329.630            659.260
   фа          174.610           349.230            698.460
  фа #         185.000           369.990            739.990
   соль        196.000           392.000            783.990
  соль #       207.650           415.300            830.610
   ля          220.000           440.000            880.000
  ля #         233.080           466.160            932.330
   си          246.940           493.880            987.770

D B B A B G D D - ре си си ля си соль ре ре 
*/


void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8_t) (Div) );
 	outb(0x42, (uint8_t) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }
 
 //make it shutup
void nosound() {
 	uint8_t tmp = inb(0x61) & 0xFC;
 
 	outb(0x61, tmp);
 }