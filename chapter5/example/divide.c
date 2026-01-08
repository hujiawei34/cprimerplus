/* divide.c -- 整数除法 */
#include <stdio.h>
int main(void)
{
    printf("integer division: 5/4 is %d \n", 5 / 4);
    printf("integer division: 6/3 is %d \n", 6 / 3);
    printf("integer division: 7/4 is %d \n", 7 / 4);
    printf("floating division: 7./4. is %1.2f \n", 7. / 4.);
    printf("mixed division: 7./4 is %1.2f \n", 7. / 4);

    // 测试趋零截断
    printf("test truncation toward zero:\n");
    printf("5/4 is %d \n", 5 / 4);
    printf("-5/4 is %d \n", -5 / 4);
    printf("-5/-4 is %d \n", -5 / -4);
    printf("5/-4 is %d \n", 5 / -4);

    printf("5/2 is %d \n", 5 / 2);
    printf("5/-2 is %d \n", 5 / -2);
    
    printf("5/3 is %d \n", 5 / 3);
    printf("-5/3 is %d \n", -5 / 3);
    return 0;
}