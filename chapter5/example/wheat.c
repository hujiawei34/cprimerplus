/* wheat.c -- 指数增长 */
#include <stdio.h>
#define SQUARES 64 // 国际象棋棋盘格子数
int main(void)
{
    const double CROP = 2E16; // 2的16次方 世界粮食产量
    double current, total;
    int count = 1;

    printf("square       grain       total    ");
    printf("fraction of \n");
    printf("             added       grain    ");
    printf("world total\n");

    total = current = 1.0; // 第一格子上的谷粒数
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);

    while (count < SQUARES)
    {
        count++;
        current = 2 * current; // 每格子上的谷粒数是前一格子的两倍
        total += current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }

    printf("That's all.\n");
    return 0;
}