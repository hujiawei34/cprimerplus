#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    char * p1=malloc(sizeof(char));
    free(p1);
    if(p1!=NULL)
        puts("ohoh!");
    puts("bye.");

    return 0;
}