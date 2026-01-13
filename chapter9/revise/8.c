#include <stdio.h>
/** 返回三个整数参数中最大值 */
int max(int a, int b, int c)
{
    int max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;
    return max;
}
int main(void)
{
    printf("max of 1 2 3 is %d\n", max(1, 2, 3));
    printf("max of -11 1 11 is %d\n", max(-11, 1, 11));
    printf("max of -221 222 223 is %d\n", max(-221, 222, 223));

    return 0;
}