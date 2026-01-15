#include <stdio.h>
void copy_arr(double target[], double source[], int n);
void copy_prr(double target[], double source[], int n);
void copy_trr(double target[], double source[], double *end);
void print_arr(double[], int n);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.2, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    print_arr(target1, 5);

    copy_prr(target2, source, 5);
    print_arr(target2, 5);

    copy_trr(target3, source, source + 5);
    print_arr(target3, 5);

    return 0;
}
void copy_arr(double target[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}
void copy_prr(double target[], double source[], int n)
{
    double *spt = source; // source point
    double *tpt = target; // target point
    for (int i = 0; i < n; i++)
        *(tpt++) = *(spt++);
}
void copy_trr(double target[], double source[], double *end)
{
    double *spt = source;
    double *tpt = target;
    while (spt < end)
        *(tpt++) = *(spt++);
}
void print_arr(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}