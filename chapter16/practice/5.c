#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#define SIZE 100
void func_select(int ar[], int size, int t);
void initarray(int ar[], int n);
void showarray(int ar[], int n);

int main(int argc, char *argv[])
{
    int ar[SIZE];
    initarray(ar, SIZE);
    showarray(ar, SIZE);
    func_select(ar, SIZE, 10);
    return 0;
}
void func_select(int ar[], int size, int t)
{
    srand(time(NULL));
    int selected[1];
    for (int i = 0; i < t; i++)
    {
        int index = rand() % size;
        memmove(selected, ar + index, 1);
        size--;
        printf("loop #%d:%d\n",i,selected[0]);
    }
}
void initarray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ar[i] = i + 1;
    }
}
void showarray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d ", ar[i]);
        if ((i + 1) % 10 == 0)
        {
            puts("");
        }
    }
    puts("");
}