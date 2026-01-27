#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SIZE 1000
void showarray(int ar[],int n);
void initarray(int ar[],int n);
int compare(const void *a, const void *b);

int main(int argc, char *argv[])
{
    int ar[SIZE];
    initarray(ar,SIZE);
    printf("origin array:\n");
    showarray(ar,SIZE);
    printf("after sort,array:\n");
    qsort(ar,SIZE,sizeof(int),compare);

    showarray(ar,SIZE);
    return 0;
}
void showarray(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%4d ",ar[i]);
        if((i+1)%10==0)
        {
            puts("");
        }
    }
    puts("");
}
void initarray(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        ar[i]=rand()%10000;
    }
}
int compare(const void *a, const void *b)
{
    int val_a = *(int *)a;
    int val_b = *(int *)b;
    return val_a - val_b;
}
