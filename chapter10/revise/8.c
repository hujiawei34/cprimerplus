#include <stdio.h>
int main(void)
{
    // a.
    int a[6];
    a[0] = 1;
    for (int i = 1; i < 6; i++)
        a[i] = a[i - 1] * 2;
    // b.
    printf("a[2]=%d.\n", a[2]);
    // c.
    int b[100];
    b[99] = -1;
    // d.
    int d[100];
    d[5] = d[10] = d[11] = d[12] = d[3] = 101;

    return 0;
}