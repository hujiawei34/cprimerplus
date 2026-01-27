#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#define SIZE 100
void showarray(double ar[], int n);
void initarray(double ar[], int n);

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    printf("data1:\n");
    double data1[SIZE];
    initarray(data1, SIZE);
    showarray(data1, SIZE);

    printf("data2:\n");
    double data2[3 * SIZE];
    initarray(data2, 3 * SIZE);
    showarray(data2, 3 * SIZE);
    printf("copy data2 front 100 elements to data1,data1:\n");

    memcpy(data1, data2, SIZE * sizeof(double));
    showarray(data1, SIZE);

    printf("copy data2 backend 100 elements to data1,data1:\n");
    memcpy(data1,data2+2*SIZE,100*sizeof(double));
    showarray(data1,SIZE);

    return 0;
}
void showarray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-8.2f ", ar[i]);
        if ((i + 1) % 10 == 0)
        {
            puts("");
        }
    }
    puts("");
}
void initarray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ar[i] = rand() % 1000 + (rand() % 100) / 100.0;
    }
}