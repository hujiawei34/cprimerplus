/* 在字符串中替换*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define PSQR(X) printf("The squre of "#X" is %d.\n",((X)*(X)))
int main(int argc, char *argv[])
{
    int y=5;

    PSQR(y);
    PSQR(2+4);
    
    return 0;
}