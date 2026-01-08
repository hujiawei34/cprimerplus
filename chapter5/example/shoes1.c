/* shoes1.c -- 把鞋码转换成英寸 */
#include <stdio.h>
#define ADJUST 7.31
int main(void)
{
    const float SCALE = 0.333;
    double shoe, foot;

    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("shoe size (men's) \tfoot length\n");
    printf("%10.1f\t %15.2f inches\n", shoe, foot);

    return 0;
}