#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define MIN(x,y) x<y?x:y
#define EVEN_GT(X,Y) (((X%2)==0) && (X>Y)) ?1:0
#define FUNC(X,Y) printf(#X" is %d and "#Y" is %d\n",X,Y)
int main(int argc, char *argv[])
{
    printf("MIN(1,2)=%d\n",MIN(1,2));
    int x,y;
    x=3;
    y=1;
    printf("EVEN_GT(x,y)=%d\n",EVEN_GT(x,y));
    FUNC(3+4,4*12);

    return 0;
}