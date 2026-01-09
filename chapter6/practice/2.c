#include <stdio.h>
int main(void)
{
    const int LIMIT = 5;
    for (int i = 0; i < LIMIT; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("$");
        printf("\n");
    }
    return 0;
}