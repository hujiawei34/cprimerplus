#include <stdio.h>
int main(void)
{
    // 7.
    int n1 = 012;
    printf("n1 in octal=%o\n", n1);
    printf("n1 in decimal=%d\n", n1);
    long double n2 = 2.9e05L;
    printf("n2=%.2Lf\n", n2);
    char n3 = 's';
    printf("n3=%c\n", n3);
    // int 为16位系统时，最大值为32767，超过会溢出
    long n4 = 100000;
    printf("n4=%ld\n", n4);
    char n5 = '\n';
    printf("n5=%c\n---", n5);
    float n6 = 20.0f;
    printf("n6=%.1f\n", n6);
    int n7 = 0x44;
    printf("n7=%#x\n", n7);
    printf("n7 in decimal=%d\n", n7);
    int n8 = -40;
    printf("n8=%d\n", n8);
    return 0;
}