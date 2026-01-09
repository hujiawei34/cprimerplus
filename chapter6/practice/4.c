#include <stdio.h>
int main(void)
{
    char current = 'A';
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%c", current++);
        printf("\n");
    }
    return 0;
}