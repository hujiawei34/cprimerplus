/* showf_pt.c -- 以两种方式显示float 类型的值 */
#include <stdio.h>
int main(void)
{
    float about=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;

    printf("%f can be written as %e\n", about, about);
    printf("And it's %a in hexadecimal,power of 2 notation.\n", about);

    printf("%f can be written as %e\n", abet, abet);
    printf("%LF can be written as %Le\n", dip, dip);
    return 0;
}