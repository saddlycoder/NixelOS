/*
  NixelOS Kernel
  
  module name: VBE.c
  
  (C) DiamondSoft (R) NixelOS 2017 - 2018 y.
  
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "VBE.h"

typedef struct VESA_INFO
   { 
      unsigned char  VESASignature[4]     __attribute__ ((packed));
      unsigned short VESAVersion          __attribute__ ((packed));
      unsigned long  OEMStringPtr         __attribute__ ((packed));
      unsigned char  Capabilities[4]      __attribute__ ((packed));
      unsigned long  VideoModePtr         __attribute__ ((packed));
      unsigned short TotalMemory          __attribute__ ((packed));
      unsigned short OemSoftwareRev       __attribute__ ((packed));
      unsigned long  OemVendorNamePtr     __attribute__ ((packed));
      unsigned long  OemProductNamePtr    __attribute__ ((packed));
      unsigned long  OemProductRevPtr     __attribute__ ((packed));
      unsigned char  Reserved[222]        __attribute__ ((packed));
      unsigned char  OemData[256]         __attribute__ ((packed));
   } VESA_INFO;