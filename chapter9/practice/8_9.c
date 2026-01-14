#include <stdio.h>
#include <math.h>
double power(double x, int y)
{
    /* return x^y*/
    double result;
    if (fabs(x) == 0)
    {
        if (y == 0)
        {
            printf("0^0 not define,return 1");
            return 1;
        }
        else
            return 0;
    }
    if (y == 0)
        return 1;
    result = 1;
    if (y > 0)
    {
        for (int i = 0; i < y; i++)
        {
            result *= x;
            printf("result=%g\n", result);
        }
    }
    else
    {
        for (int i = 0; i < fabs(y); i++)
            result *= x;
        result = 1.0 / result;
    }
    return result;
}
double rpower(double x, int y)
{
    /* return x^y using recursion */
    // 处理 x = 0 的特殊情况
    if (fabs(x) == 0)
    {
        if (y == 0)
        {
            printf("0^0 not define,return 1\n");
            return 1;
        }
        else if (y > 0)
            return 0;
        else
        {
            printf("0^(negative) is undefined\n");
            return 1; // 或者可以返回 NaN
        }
    }

    // 基础情况：任何数的 0 次方等于 1
    if (y == 0)
        return 1;

    // 递归情况
    if (y > 0)
    {
        // 正指数：x^y = x * x^(y-1)
        return x * rpower(x, y - 1);
    }
    else
    {
        // 负指数：x^y = 1 / x^(-y)
        return 1.0 / rpower(x, -y);
    }
}
int main(void)
{
    double x = 1.5;
    int y = 10;

    printf("=== 测试循环版本 power() ===\n");
    printf("%.2f^%d=%g\n", x, y, power(x, y));
    y = -1;
    printf("%.2f^%d=%g\n", x, y, power(x, y));
    y = -10;
    printf("%.2f^%d=%g\n", x, y, power(x, y));

    printf("\n=== 测试递归版本 rpower() ===\n");
    y = 10;
    printf("%.2f^%d=%g\n", x, y, rpower(x, y));
    y = -1;
    printf("%.2f^%d=%g\n", x, y, rpower(x, y));
    y = -10;
    printf("%.2f^%d=%g\n", x, y, rpower(x, y));
    y = 0;
    printf("%.2f^%d=%g\n", x, y, rpower(x, y));

    return 0;
}