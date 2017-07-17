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

void kbd_wap(int color)
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
                printch("(char)27);           Escape button
                buffstr[i] = (char)27;
                i++;
                break;*/
        case 2:
                print("1",color);
                break;
		
        case 3:
                print("2",color);
                break;
		
        case 4:
                print("3",color);
                break;
        case 5:
                print("4",color);
                break;
        case 6:
                print("5",color);
                break;
        case 7:
                print("6",color);
                break;
        case 8:
                print("7",color);
                break;
        case 9:
                print("8",color);
                break;
        case 10:
                print("9",color);
                break;
        case 11:
                print("0",color);
                break;
        case 12:
                print("-",color);
                break;
        case 13:
                print("=",color);
                break;
        case 14:
                print("/",color);
                break;
       /* case 15:
                printch("\t");          Tab button
                break; */
        case 16:
                print("q",color);
                break;
        case 17:
                print("w",color);
                break;
        case 18:
                print("e",color);
                break;
        case 19:
                print("r",color);
                break;
        case 20:
                print("t",color);
                break;
        case 21:
                print("y",color);
                break;
        case 22:
                print("u",color);
                break;
        case 23:
                print("i",color);
                break;
        case 24:
                print("o",color);
                break;
        case 25:
                print("p",color);
                break;
        case 26:
                print("[",color);
                break;
        case 27:
                print("]",color);
                break;
        //case 28:
               // printch("\n");
               // buffstr[i] = "\n";
                  //i++;
               //reading = 0;
               // break;
      /*  case 29:
                printch("q");           Left Control
                buffstr[i] = "q";
                i++;
                break; */
        case 30:
                print("a",color);
                break;
        case 31:
                print("s",color);
                break;
        case 32:
                print("d",color);
                break;
        case 33:
                print("f",color);
                break;
        case 34:
                print("g",color);
                break;
        case 35:
                print("h",color);
                break;
        case 36:
                print("j",color);
                break;
        case 37:
                print("k",color);
                break;
        case 38:
                print("l",color);
                break;
        case 39:
                print(";",color);
                break;
        case 40:
                print((char)44,color);               //   Single quote (")
                break;
        case 41:
                print((char)44,color);               // Back tick (`)
                break;
     /* case 42:                                 Left shift 
                printch("q");
                buffstr[i] = "q";
                i++;
                break; */
        case 43:                                 // (< for somekeyboards)   
                print((char)92,color);
                break;
        case 44:
                print("z",color);
                break;
        case 45:
                print("x",color);
                break;
        case 46:
                print("c",color);
                break;
        case 47:
                print("v",color);
                break;                
        case 48:
                print("b",color);
                break;               
        case 49:
                print("n",color);
                break;                
        case 50:
                print("m",color);
                break;               
        case 51:
                print(",",color);
                break;                
        case 52:
                print(".",color);
                break;            
        case 53:
                print("/",color);
                break;            
        case 54:
                print(".",color);
                break;            
        case 55:
                print("/",color);
                break;            
      /*case 56:
                printch(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break;          
        case 57:
                printch(' ');
                buffstr[i] = ' ';
                i++;
	            break;*/
            }
        }
    }
}