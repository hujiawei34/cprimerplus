#include <stdio.h>
int main(void)
{
    const int SIZE = 26;
    char char_arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        char_arr[i] = 'a' + i;
    }
    for (int i = 0; i < SIZE; i++)
        printf("%c ", char_arr[i]);
    printf("\n");

    return 0;
}