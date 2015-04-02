/*
 * Simple example client.
 *
 * ex_1.c
 * libsmc
 *
 * Copyright (C) 2014  beltex <https://github.com/beltex>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdio.h>
#include "smc.h"

int main(int argc, char* argv[])
{
   if (open_smc() != kIOReturnSuccess) {
      return -1;
   }

   for (int i=1; i<argc; i++) {
      if (i>1) printf(",");
      printf("%f", get_float(argv[i]));
   }
   printf("\n");

   close_smc();

   return 0;
}
