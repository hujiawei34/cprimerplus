#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define FUNC(X,Y) 1.0/((1.0/(X)+1.0/(Y))/2.0)
int main(int argc, char *argv[])
{
    printf("FUNC(1.0,2.0)=%g\n",FUNC(1.0,2.0));
    
    return 0;
}