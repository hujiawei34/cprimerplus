#include <stdio.h>
double min(double x, double y)
{
    return y < x ? y : x;
}
int main(void)
{
    double x = 1.2, y = 2.1;
    printf("min of %.2f and %.2f is %.2f\n", x, y, min(x, y));
    x = -100.1, y = 0.11;
    printf("min of %.2f and %.2f is %.2f\n", x, y, min(x, y));

    return 0;
}