#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <tgmath.h>
int main(int argc, char *argv[])
{
    float x=2.0;
    double y1,y2;
    y1=sqrt(x);
    y2=(sqrt)(x);
    printf("y1=%.17lf\n",y1);
    printf("y2=%.17lf\n",y2);

    return 0;
}