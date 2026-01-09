#include <stdio.h>
#define SIZE 8
int main(void)
{
    int by_twos[SIZE];
    int index;
    for (index = 0; index < SIZE; index++)
        by_twos[index] = 2 * (index + 1);
    for (index = 0; index < SIZE; index++)
        printf("%d ", by_twos[index]);
    // 2 4 6 8 10 12 14 16
    printf("\n");
    return 0;
}