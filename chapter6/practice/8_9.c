#include <stdio.h>
#include <math.h>
double cal(double a, double b)
{
    double result;
    result = fabs(a - b) / (a * b);
    return result;
}
int main(void)
{
    int status;

    printf("input 2 number:");
    double a, b;
    status = scanf("%lf %lf", &a, &b);
    while (status == 2)
    {
        printf("%.2f and %.2f result is:%.2f\n", a, b, cal(a, b));
        printf("input 2 number:");
        status = scanf("%lf %lf", &a, &b);
    }
    return 0;
}