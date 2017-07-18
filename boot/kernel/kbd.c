/*
  NixelOS Kernel
  
  module name: kbd.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "io.h"

#include "kbd.h"

void kbd_ack(void){
  while(!(inb(0x60)==0xfa));
}


void kbd_led_handling(int ledstatus){
  outb(0x60,0xed);
  kbd_ack();
  outb(0x60,ledstatus);
}

void kbd_wap()
{

    uint8_t i = 0;
    uint8_t reading = 1;
    while(reading)
    {
        if(inb(0x64) & 0x1)                 
        {
            switch(inb(0x60))
            { 
      /*case 1:
                terminal_putcharch('(char)27);           Escape button
                buffstr[i] = (char)27;
                i++;
                break;*/
        case 2:
                terminal_putchar('1');
                break;
		
        case 3:
                terminal_putchar('2');
                break;
		
        case 4:
                terminal_putchar('3',color);
                break;
        case 5:
                terminal_putchar('4',color);
                break;
        case 6:
                terminal_putchar('5',color);
                break;
        case 7:
                terminal_putchar('6',color);
                break;
        case 8:
                terminal_putchar('7',color);
                break;
        case 9:
                terminal_putchar('8',color);
                break;
        case 10:
                terminal_putchar('9',color);
                break;
        case 11:
                terminal_putchar('0',color);
                break;
        case 12:
                terminal_putchar('-',color);
                break;
        case 13:
                terminal_putchar('=',color);
                break;
        case 14:
                terminal_putchar('/',color);
                break;
       /* case 15:
                terminal_putcharch('\t');          Tab button
                break; */
        case 16:
                terminal_putchar('q',color);
                break;
        case 17:
                terminal_putchar('w',color);
                break;
        case 18:
                terminal_putchar('e',color);
                break;
        case 19:
                terminal_putchar('r',color);
                break;
        case 20:
                terminal_putchar('t',color);
                break;
        case 21:
                terminal_putchar('y',color);
                break;
        case 22:
                terminal_putchar('u',color);
                break;
        case 23:
                terminal_putchar('i',color);
                break;
        case 24:
                terminal_putchar('o',color);
                break;
        case 25:
                terminal_putchar('p',color);
                break;
        case 26:
                terminal_putchar('[',color);
                break;
        case 27:
                terminal_putchar(']',color);
                break;
        //case 28:
               // terminal_putcharch('\n');
               // buffstr[i] = '\n';
                  //i++;
               //reading = 0;
               // break;
      /*  case 29:
                terminal_putcharch('q');           Left Control
                buffstr[i] = 'q';
                i++;
                break; */
        case 30:
                terminal_putchar('a',color);
                break;
        case 31:
                terminal_putchar('s',color);
                break;
        case 32:
                terminal_putchar('d',color);
                break;
        case 33:
                terminal_putchar('f',color);
                break;
        case 34:
                terminal_putchar('g',color);
                break;
        case 35:
                terminal_putchar('h',color);
                break;
        case 36:
                terminal_putchar('j',color);
                break;
        case 37:
                terminal_putchar('k',color);
                break;
        case 38:
                terminal_putchar('l',color);
                break;
        case 39:
                terminal_putchar(';',color);
                break;
        case 40:
                terminal_putchar((char)44,color);               //   Single quote (')
                break;
        case 41:
                terminal_putchar((char)44,color);               // Back tick (`)
                break;
     /* case 42:                                 Left shift 
                terminal_putcharch('q');
                buffstr[i] = 'q';
                i++;
                break; */
        case 43:                                 // (< for somekeyboards)   
                terminal_putchar((char)92,color);
                break;
        case 44:
                terminal_putchar('z',color);
                break;
        case 45:
                terminal_putchar('x',color);
                break;
        case 46:
                terminal_putchar('c',color);
                break;
        case 47:
                terminal_putchar('v',color);
                break;                
        case 48:
                terminal_putchar('b',color);
                break;               
        case 49:
                terminal_putchar('n',color);
                break;                
        case 50:
                terminal_putchar('m',color);
                break;               
        case 51:
                terminal_putchar(',',color);
                break;                
        case 52:
                terminal_putchar('.',color);
                break;            
        case 53:
                terminal_putchar('/',color);
                break;            
        case 54:
                terminal_putchar('.',color);
                break;            
        case 55:
                terminal_putchar('/',color);
                break;            
      /*case 56:
                printch(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break; */
        case 57:
                terminal_putchar(' ');
	            break;
            }
        }
    }
}