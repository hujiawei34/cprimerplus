#include <stdio.h>
int main(void)
{

    // 2. 使用整数并且接近 20亿时，使用long类型代替int类型
    printf("int has %zd bytes\n", sizeof(int));

    printf("long has %zd bytes\n", sizeof(long));
    // max number of int is 2147483647
    // max number of long is 9223372036854775807
    // print max number of int
    // 每byte有8位，int的最高位是符号位，所以用(8 * sizeof(int) - 1)
    // 思路：先得到最小值，然后减1（但这个方法有溢出风险）
    int max_int = (1 << (8 * sizeof(int) - 1)) - 1; // 会溢出，有编译器警告
    // 思路：先得到最小值（符号位为1，其余为0），然后取反得到最大值（符号位为0，其余为1）
    int max_int2 = ~(1 << (8 * sizeof(int) - 1));
    printf("max number of int is %d\n", max_int);
    printf("max number of int is %d\n", max_int2);
    printf("check is max_int + 1: %d\n", max_int + 1);
// 直接使用头文件limits.h中的宏
#include <limits.h>
    printf("max number of int from limits.h is %d\n", INT_MAX);
    return 0;
}