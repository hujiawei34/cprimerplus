#include <stdio.h>
#include <limits.h>
int main(void)
{
    int max_int = INT_MAX;
    printf("max number of int is %d\n", max_int);
    printf("整数上溢出测试：max_int + 1 = %d\n", max_int + 1);
    double f = 1.234e308;
    printf("浮点数上溢出测试：f = %.2f\n", f+1.0);
    double d = 1.0e-320;
    printf("浮点数下溢出测试：d = %.2f\n", d- 1.0);
    return 0;
}