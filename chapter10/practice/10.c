#include <stdio.h>
void sum_arr(int a[], int b[], int c[], int n)
{
    for (size_t i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}
void print_arr(int a[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
int main(void)
{
    int SIZE = 4;
    int a[] = {2, 4, 5, 8};
    int b[] = {1, 0, 4, 6};
    int c[SIZE];

    sum_arr(a, b, c, SIZE);
    print_arr(c,SIZE);
    
    return 0;
}