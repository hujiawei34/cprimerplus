#include <stdio.h>
int main(void)
{
    const int SIZE = 8;
    double la[SIZE], lb[SIZE];
    printf("input 8 number:");
    for (int i = 0; i < SIZE; i++)
        scanf("%lf", &la[i]);
    double current = la[0];
    for (int i = 0; i < SIZE; i++)
    {
        lb[i] = current;
        current += la[i];
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%-4.1f ", la[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%-4.1f ", lb[i]);
    }

    return 0;
}