#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void init_ar(double ar[], int n)
{
    srandom((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        double r = (double)random() / RAND_MAX;
        ar[i] = round(r * 10000) / 100.0;
    }
}
void print_ar(int r, int c, double ar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%4.2f ", ar[i][j]);
        putchar('\n');
    }
}
void copy_arr(int r, int c, double t[r][c], double s[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            t[i][j] = s[i][j];
    }
}
int main(void)
{
    int r = 2, c = 3;
    double s[r][c];
    double t[r][c];
    double *pt = s[0];
    init_ar(pt, r * c);
    print_ar(r, c, s);
    printf("=================\n");
    copy_arr(r, c, t, s);
    print_ar(r, c, t);
    return 0;
}