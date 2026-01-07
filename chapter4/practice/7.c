#include <stdio.h>
#include <float.h>
int main(void)
{
    double d = 1.0 / 3.0;
    float f = 1.0f / 3.0f;
    printf("double类型1/3的值是%.6lf, float类型1/3的值是%.6f\n", d, f);
    printf("double类型1/3的值是%.12lf, float类型1/3的值是%.12f\n", d, f);
    printf("double类型1/3的值是%.16lf, float类型1/3的值是%.16f\n", d, f);
    printf("FLT_DIG的值是%d\n", FLT_DIG);
    printf("DBL_DIG的值是%d\n", DBL_DIG);
    return 0;
}