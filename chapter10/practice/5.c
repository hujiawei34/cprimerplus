#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double get_diff(double ar[], int n);
void init_ar(double ar[], int n);
void print_ar(double ar[], int n);

int main(void)
{
    const int SIZE = 20;
    double ar[SIZE];
    init_ar(ar, 20);
    print_ar(ar, SIZE);
    printf("max -min = %g\n", get_diff(ar, SIZE));

    return 0;
}
void print_ar(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}
void init_ar(double ar[], int n)
{
    srandom((unsigned int)time(NULL));
    double max = 1000.0;
    double min = 0.0;
    for (int i = 0; i < n; i++)
        ar[i] = min + (double)random() / (double)RAND_MAX * (max - min);
}
double get_diff(double ar[], int n)
{
    double min = ar[0], max = ar[0];
    for (int i = 0; i < n; i++)
    {
        min = ar[i] < min ? ar[i] : min;
        max = ar[i] > max ? ar[i] : max;
    }
    return max - min;
}