#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
void itobs(int n, char *str)
{
    int size = CHAR_BIT * sizeof(int);
    str[size] = '\0';
    for (int i = size - 1; i >= 0; i--)
    {
        str[i] = (1 & n) + '0';
        n >>= 1;
    }
}
int get_open_bit(int n)
{
    char str[CHAR_BIT * sizeof(int) + 1];
    itobs(n, str);
    int re = 0;
    for (int i = 0; i < CHAR_BIT * sizeof(int); i++)
    {
        if (str[i] == '1')
            re++;
    }
    return re;
}
int main(int argc, char *argv[])
{
    int n = 55;
    printf("%d has %d open bits\n", n, get_open_bit(n));

    return 0;
}