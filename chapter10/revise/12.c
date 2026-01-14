#include <stdio.h>
void func_a1(double[], int n);
void func_a2(int n, double[*]);
void func_b1(short[][30], int n);
void func_b2(int, int, short[*][*]);
void func_c1(long[][10][15], int n);
void func_c2(int, int, int, long[*][*][*]);

int main(void)
{
    double trots[20];
    short clops[10][30];
    long shots[5][10][15];
    // func_a1(trots, 10);
    // func_a2(15, trots);

    // func_b1(clops, 30);
    // func_b2(10, 30, clops);
    func_c1(shots, 5);
    func_c2(5, 5, 5, shots);
    return 0;
}
void func_c1(long ar[][10][15], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 15; k++)
                ar[i][j][k] = i + j + k;
        }
    }
}
void func_c2(int a, int b, int c, long ar[a][b][c])
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            putchar('{');
            for (int k = 0; k < c; k++)
                printf("%ld,",ar[i][j][k]);
            putchar('}');
        }
        putchar('\n');
    }
}
void func_b1(short ar[][30], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
            ar[i][j] = i + j;
    }
}
void func_b2(int r, int c, short ar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", ar[i][j]);
        putchar('\n');
    }
}
void func_a1(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] = i * 2.0;
}
void func_a2(int n, double ar[n])
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}