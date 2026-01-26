#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>
void itobs(unsigned int n, char *str)
{
    int size = CHAR_BIT * (sizeof(unsigned int));
    memset(str, 0, size);

    str[size] = '\0';
    for (int i = size - 1; i >= 0; i--, n >>= 1)
        str[i] = '0' + (1 & n);
}
unsigned int rotate_1(unsigned int x, int bit)
{
    int size = CHAR_BIT * sizeof(unsigned int);
    unsigned int re=x;
    for (int i = 0; i < bit; i++)
    {
        unsigned int a = re << 1;//先向左移1位,丢失最高位
        unsigned int b=a>>1;//再向右移1位，最高位补0，
        if(re-b ==0){//re-b =0时，最高位为0，否则为1，
            re=a;//最高位为0时，左移结果右边自动补0，最后1位不变（+0）
        }else{
            re=a+1;//最高位为1时，左移结果右边自动补0，最后1位要+1，变成1
        }
    }
    return re;
}
unsigned int rotate_1_bt(unsigned int x,int bit)
{
    //不使用循环，左移bit位，右移size-bit位 求|，就可以
    // 1010 1010 左移2位 ：    101010 00
    // 1010 1010 右移8-2=6位 ：000000 10
    //对这两个结果求|，就可以将最高的2位放到后面
    int size=CHAR_BIT*sizeof(unsigned int);

    return (x<<bit)|(x>>(size-bit));

}
int main(int argc, char *argv[])
{
    char str[CHAR_BIT * sizeof(unsigned int) + 1];
    unsigned int n = 0;
    n=~n;
    n-=2;
    itobs(n, str);
    printf("%u(10)=%s\n", n, str);
    
    printf("after rotate:\n");
    unsigned int x = rotate_1(n, 4);
    itobs(x, str);
    printf("%u(10)=%s\n", x, str);

    printf("after rotate better:\n");
    x = rotate_1_bt(n, 4);
    itobs(x, str);
    printf("%u(10)=%s\n", x, str);

    return 0;
}