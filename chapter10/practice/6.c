#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_ar(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}
void init_ar(double ar[], int n)
{
    srandom((unsigned int)time(NULL));
    double max = 100.0;
    double min = 0.0;
    for (int i = 0; i < n; i++)
        ar[i] = min + (double)random() / (double)RAND_MAX * (max - min);
}
void sort(double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[i])
            {
                double tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;
            }
        }
    }
}
int main(void)
{
    int SIZE = 10;
    double ar[SIZE];
    init_ar(ar, SIZE);
    print_ar(ar, SIZE);
    sort(ar,SIZE);
    print_ar(ar,SIZE);

    return 0;
}