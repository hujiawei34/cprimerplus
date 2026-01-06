#include <stdio.h>
int main(void)
{
    //4.
    //a.
    char c='\b';// escape character backspace
    //only print 3 ,because backspace will erase the previous character 1 and 2
    printf("The backspace character is represented as: 1\b2\b3\n");
    //b.
    int a=1066;// decimal number
    printf("The decimal number is: %d\n",a);
    //c.
    float f =99.44;// float number
    printf("The float number is: %.2f\n",f);
    //d.
    int x=0XAA;// hexadecimal number
    printf("The hexadecimal number is: %X\n",x);
    printf("The hexadecimal number in decimal is: %d\n",x);
    //e.
    double d=2.0e30;// double number
    printf("The double number is: %.2e\n",d);
    return 0;
}