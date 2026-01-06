#include <stdio.h>
int main(void)
{
    char ch;
    ch='\n';
    printf("The character ch is:%c",ch);
    printf("-------\n");
    printf("The ASCII value of ch is:%d\n",ch);
    ch=10;
    printf("The character ch is:%c",ch);
    printf("-------\n");
    printf("The ASCII value of ch in octal is:%#o\n",ch);
    ch=012;
    printf("The character ch is:%c",ch);
    printf("-------\n");
    printf("The ASCII value of ch in hexadecimal is:%#x\n",ch);
    ch=0xA;
    printf("The character ch is:%c",ch);
    printf("-------\n");
    return 0;
}