// 变参宏
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define PR(X,...) printf("Message " #X ": " __VA_ARGS__)
int main(int argc, char *argv[])
{
    double x=48;
    double y;

    y=sqrt(x);
    PR(1,"x=%g\n",x);//printf("Message ""1"":""x=%g\n",x)==printf("Message 1:x=%g\n",x)
    PR(2,"x=%.2f,y=%.4f\n",x,y);//printf("Message ""2"":""x=%.2f,y=%.4f\n",x,y)==printf("Message 2:x=%.2f,y=%.4f\n",x,y)

    return 0;
}