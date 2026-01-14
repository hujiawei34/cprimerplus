#include <stdio.h>
double func(double d1, double d2)
{
    return 1 / ((1.0 / d1 + 1.0 / d2) / 2);
}
int main(void)
{
    double d1 = 1.1, d2 = 2.1;
    printf("%.2f and %.2f result is %.2f\n", d1, d2, func(d1, d2));
    d1 = 0.11, d2 = 0.22;
    printf("%.2f and %.2f result is %.2f\n", d1, d2, func(d1, d2));
    return 0;
}