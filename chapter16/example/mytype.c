#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define MY_TYPE(x) _Generic((x),int:"int",float:"float",double:"double",default:"other")
int main(int argc, char *argv[])
{
    int d=5;
    printf("MY_TYPE is %s\n",MY_TYPE(d));
    printf("MY_TYPE is %s\n",MY_TYPE(d/4.0));
    printf("MY_TYPE is %s\n",MY_TYPE(&d));
    return 0;
}