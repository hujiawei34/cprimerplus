#include <stdio.h>
int main(void)
{
    //a.
    int x=0 ;
    x+=10;
    printf("%d\n",x);
    //b.
    x=0;
    x++;
    printf("%d\n",x);
    //c.
    int a,b,c;
    a=1,b=2;
    c=2*(a+b);
    printf("%d\n",c);
    //d.
    c=a+2*b;
    printf("%d\n",c);
    return 0;
}