#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    int list[SIZE];
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &list[i]);
    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}