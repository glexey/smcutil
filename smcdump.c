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

int main()
{
		if (open_smc() != kIOReturnSuccess) {
				return -1;
		}

		char s[] = "1234";
		char type[] = "four";

		kern_return_t result;
		smc_return_t  result_smc;

		for (s[0]='A'; s[0]<127; s[0]++) {
				printf("--- %c ---\n", s[0]);
				for (s[1]='0'; s[1]<127; s[1]++)
						for (s[2]='0'; s[2]<127; s[2]++)
								for (s[3]='0'; s[3]<127; s[3]++) {
										result = read_smc(s, &result_smc);
										if (result != kIOReturnSuccess) continue;
										if (!result_smc.dataSize) continue;
										for (int i=0; i<4; i++)
												type[i] = ((char*)&result_smc.dataType)[3-i];
										printf("%s,%s,%d", s, type, result_smc.dataSize);
										for (int i=0; i<result_smc.dataSize; i++)
												printf(",%d", result_smc.data[i]);
										printf("\n");
								}
		}

		close_smc();

		return 0;
}
