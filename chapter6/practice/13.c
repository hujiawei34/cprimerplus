#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    long list[SIZE];
    long current = 1;
    for (int i = 0; i < SIZE; i++)
    {
        list[i] = current;
        current *= 2;
    }
    int i = 0;
    do
    {
        printf("%ld ", list[i]);
    } while (++i < SIZE);

    return 0;
}