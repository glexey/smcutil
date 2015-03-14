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

    printf("AMBIENT_AIR_0: %0.1fC\n", get_tmp(AMBIENT_AIR_0, CELSIUS));
    printf("AMBIENT_AIR_1: %0.1fC\n", get_tmp(AMBIENT_AIR_1, CELSIUS));
    printf("CPU_0_DIODE: %0.1fC\n", get_tmp(CPU_0_DIODE, CELSIUS));
    printf("CPU_0_HEATSINK: %0.1fC\n", get_tmp(CPU_0_HEATSINK, CELSIUS));
    printf("CPU_0_PROXIMITY: %0.1fC\n", get_tmp(CPU_0_PROXIMITY, CELSIUS));
    printf("GPU_0_DIODE: %0.1fC\n", get_tmp(GPU_0_DIODE, CELSIUS));
    printf("GPU_0_HEATSINK: %0.1fC\n", get_tmp(GPU_0_HEATSINK, CELSIUS));
    printf("GPU_0_PROXIMITY: %0.1fC\n", get_tmp(GPU_0_PROXIMITY, CELSIUS));
    printf("ENCLOSURE_BASE_0: %0.1fC\n", get_tmp(ENCLOSURE_BASE_0, CELSIUS));
    printf("ENCLOSURE_BASE_1: %0.1fC\n", get_tmp(ENCLOSURE_BASE_1, CELSIUS));
    printf("ENCLOSURE_BASE_2: %0.1fC\n", get_tmp(ENCLOSURE_BASE_2, CELSIUS));
    printf("ENCLOSURE_BASE_3: %0.1fC\n", get_tmp(ENCLOSURE_BASE_3, CELSIUS));
    printf("HARD_DRIVE_BAY: %0.1fC\n", get_tmp(HARD_DRIVE_BAY, CELSIUS));
    printf("MEMORY_SLOT_0: %0.1fC\n", get_tmp(MEMORY_SLOT_0, CELSIUS));
    printf("MEMORY_SLOTS_PROXIMITY: %0.1fC\n", get_tmp(MEMORY_SLOTS_PROXIMITY, CELSIUS));
    int num_fans = get_num_fans();
    printf("Num fans: %d\n", num_fans);
    for (int i=0; i < num_fans; i++)
	printf("Fan %d: %d RPM\n", i, get_fan_rpm(i));
    
    printf("Voltage: %f\n", get_voltage("VC0C"));

    close_smc();

    return 0;
}
