#include <stdio.h>
#include <stdlib.h>
#include "smc.h"

int main(int argc, char* argv[])
{
   if (open_smc() != kIOReturnSuccess) {
      return -1;
   }

   printf("Fan 0 RPM\n");
   printf("  Current: %.1f\n", get_float("F0Ac"));
   printf("   Target: %.1f\n", get_float("F0Tg"));
   //printf("     Safe: %.1f\n", get_float("F0Sf"));
   printf("      Min: %.1f\n", get_float("F0Mn"));
   printf("      Max: %.1f\n", get_float("F0Mx"));
   if (argc>1) {
      unsigned int r = atoi(argv[1]);
      printf("Setting Min RPM to: %d\n", r);
      if (!set_fan_min_rpm(0, r))
         printf("Failed setting min RPM, try 'sudo %s'\n", argv[0]);
   }

   close_smc();

   return 0;
}
