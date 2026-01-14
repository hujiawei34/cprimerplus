#include <stdio.h>
void larger_of(double *x, double *y)
{
    double max = *x > *y ? *x : *y;
    *x = max;
    *y = max;
}
int main(void)
{
    double d1 = 1.111, d2 = -1.1112;
    printf("origin d1=%.4f,d2=%.4f\n", d1, d2);
    larger_of(&d1, &d2);
    printf("now d1=%.4f,d2=%.4f\n", d1, d2);

    return 0;
}