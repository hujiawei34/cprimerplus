#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void copy_arr(double target[], double source[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}
void print_ar(int r, int c, double ar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%g ", ar[i][j]);
        putchar('\n');
    }
}
void init_ar(double ar[], int n)
{
    srandom((unsigned int)time(NULL));
    double max = 1000.0;
    double min = 0.0;
    for (int i = 0; i < n; i++)
        ar[i] = min + (double)random() / (double)RAND_MAX * (max - min);
}
int main(void)
{
    int r = 5, c = 2;
    double source[r][c];
    double target[r][c];
    double *pt = source[0];
    double *tpt = target[0];

    init_ar(pt, r * c);
    print_ar(r, c, source);

    printf("=============\n");
    copy_arr(tpt, pt, r * c);
    print_ar(r, c, target);

    return 0;
}
