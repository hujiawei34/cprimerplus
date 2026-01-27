#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define LIMIT 4
#define JUST_CHECKING
int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 0; i < LIMIT; i++)
    {
        sum += 2 * i * i + 1;
        if (i % 2 == 0){
            #undef JUST_CHECKING
        }

#ifdef JUST_CHECKING
            printf("i=%d,sum=%d\n", i, sum);
#endif
    }
    printf("sum=%d\n", sum);
    return 0;
}