#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#define RAD_TO_DEG (180 / (4 * atanl(1)))
#define SQRT(X) _Generic((X), long double: sqrtl, default: sqrt, float: sqrtf)(X)
#define SIN(X) _Generic((X),\
long double:sinl((X)/RAD_TO_DEG),\
default: sin((X)/RAD_TO_DEG),\
float:sinf((X)/RAD_TO_DEG)\
)
int main(int argc, char *argv[])
{

    float x=45.00f;
    double xx=45.0;
    long double xxx=45.0L;
    long double y=SQRT(x);
    long double yy=SQRT(xx);
    long double yyy=SQRT(xxx);
    printf("%.17LF\n",y);
    printf("%.17LF\n",yy);
    printf("%.17LF\n",yyy);

    int i=45;
    yy=SQRT(i);
    printf("%.17LF\n",yy);
    yyy=SIN(xxx);
    printf("%.17LF\n",yyy);

    return 0;
}