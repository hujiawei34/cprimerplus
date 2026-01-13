#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
double sum_d(double a, double b)
{
    return a + b;
}
int main(void)
{
    printf("%d\n", sum(1, 2));
    printf("%.2f\n",sum_d(2.1,2.2));
    
    return 0;
}