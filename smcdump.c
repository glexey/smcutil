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
