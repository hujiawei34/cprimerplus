#include <stdio.h>
int main(void)
{
    int value;
    for (value=36;value>0;value/=2)
        printf("%3d",value);
        /* 36 18  9  4  2  1*/
    return 0;
}