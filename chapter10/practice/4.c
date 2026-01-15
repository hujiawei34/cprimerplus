#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int get_max_index(double ar[], int n);
void init_ar(double ar[], int n);
void print_ar(double ar[], int n);

int main(void)
{
    const int SIZE = 20;
    double ar[SIZE];
    init_ar(ar, 20);
    print_ar(ar, SIZE);
    int max_index = get_max_index(ar, SIZE);
    printf("min index is %d,value is %g\n", max_index, ar[max_index]);

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
int get_max_index(double ar[], int n)
{
    int max_index = 0;
    double max = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > max)
        {
            max = ar[i];
            max_index = i;
        }
    }
    return max_index;
}