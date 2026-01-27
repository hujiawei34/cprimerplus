#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    printf("The square root of %s is %f\n",argv[1],sqrt(atof(argv[1])));
    return 0;
}