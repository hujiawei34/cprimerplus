/* 用qsort() 排序一组数字 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 40
void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);

    return 0;
}
void fillarray(double ar[], int n)
{
    int index;
    for (index = 0; index < n; index++)
        ar[index] = (double)rand() / ((double)rand() + 0.1);
}
void showarray(double ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
        {
            putchar('\n');
        }
    }
    if (index % 6 != 0)
    {
        putchar('\n');
    }
}
int mycomp(const void *p1, const void *p2)
{
    const double *a1 = p1;//c中可以不做强制转换，C++必需
    const double *a2 = (const double *)p2;
    if (*a1 < *a2)
    {
        return -1;
    }
    else if (*a1 == *a2)
    {
        return 0;
    }
    return 1;
}