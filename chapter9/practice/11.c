#include <stdio.h>
long feb(int n)
{
    if (n <= 2)
        return 1;
    /** 1 1 2 3 .. */
    long re;       // f(n)
    long prev = 1; // f(n-1)
    long pp = 1;   // f(n-2)
    for (int i = 3; i <= n; i++)
    {
        re = pp + prev;
        pp = prev;
        prev = re;
    }
    return re;
}
int main(void)
{
    int n = 20;
    for (int i = 1; i < n; i++)
        printf("%ld\n", feb(i));

    return 0;
}