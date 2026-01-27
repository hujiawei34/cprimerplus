/* 带参数的宏*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SQUARE(X) X*X 
#define PR(X) printf("The result is %d.\n",X)
int main(int argc, char *argv[])
{
    int x =5;
    int z;

    printf("x=%d\n",x);//x=5
    z=SQUARE(x);//z=25
    printf("Evaluating SQUARE(x):");
    PR(z);//the result is 25.
    z=SQUARE(2);//z=2*2=4
    printf("Evaluating SQUARE(2):");
    PR(z);//4
    printf("Evaluating SQUARE(x+2):");
    PR(SQUARE(x+2));//49 x+2*x+2=5*2*5+2=17
    printf("Evaluating 100/SQUARE(2):");
    PR(100/SQUARE(2));//25--100/2*2=100
    printf("x is %d \n",x);//5
    printf("Evaluating SQUARE(++x):");
    PR(SQUARE(++x));//36-->++x*++x=7*7=49
    printf("After incrementing,x is %x.\n",x);//7


    return 0;
}