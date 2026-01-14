#include <stdio.h>
void show(const double ar[], int n);
void show2(const double ar[][3], int n);
int main(void)
{
    // a.
    show((double[]){8, 3, 9, 2}, 4);
    show2((double[2][3]){{8, 3, 9}, {5, 4, 1}}, 2);
    return 0;
}
void show(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}
void show2(const double ar[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%g ", ar[i][j]);
        putchar('\n');
    }
}