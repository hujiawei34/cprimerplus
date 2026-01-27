#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define LIMIT 25
#define SPACE ' '
#define PS() putchar(SPACE)
#define BIG(X) X+3
#define SUMSQ(X,Y) ((X)*(X)+(Y)*(Y))
#define PRINT(X) printf("name: "#X"; value: %d; address: %p\n",X,&X)
int main(int argc, char *argv[])
{
    printf("====");
    PS();
    printf("=====\n");

    printf("BIG(3)=%d\n",BIG(3));

    printf("SUMSQ(1,2)=%d\n",SUMSQ(1,2));
    
    int fop=23;
    PRINT(fop);
    printf("address:%p\n",&fop);

    return 0;
}