#include <stdio.h>
int main(void)
{
    //6.
    int l1=12;
    printf("l1=%d\n",l1);
    int l2=0X3;
    printf("l2=%#x\n",l2);
    char l3='C';
    printf("l3=%c\n",l3);
    float l4=2.34E07;
    printf("l4=%f\n",l4);
    char l5='\040';
    printf("l5=%c\n",l5);
    float l6=7.0;
    printf("l6=%.1f\n",l6);
    long l7=6L;
    printf("l7=%ld\n",l7);
    float l8=6.0f;
    printf("l8=%.2f\n",l8);
    float l9=0xb.b6p12;
    printf("l9=%a\n",l9);
    return 0;
}