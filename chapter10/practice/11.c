#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 5
void init_arr(int ar[], int n)
{
    srandom((unsigned long)time(NULL));

    for (size_t i = 0; i < n; i++)
    {
        ar[i] = (int)random() % 100;
    }
}
void print_arr(int ar[][COLS], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            printf("%d ", ar[i][j]);
        }
        putchar('\n');
    }
}
void double_arr(int ar[][COLS], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            ar[i][j] *= 2;
        }
    }
}
int main(void)
{
    int r = 3, c = 5;
    int s[r][c];
    int *pt = s[0];
    init_arr(pt, r * c);
    print_arr(s, ROWS);
    printf("=================\n");

    double_arr(s,ROWS);
    print_arr(s,ROWS);

    return 0;
}