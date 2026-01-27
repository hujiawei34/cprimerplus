#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define TEST
#define  PR_DATE
#define FUNC(X) _Generic((X),_Bool:"boolean",default:"not boolean")
int main(int argc, char *argv[])
{
    #ifndef TEST
    printf("this code should skip when test \n");
    #endif
    printf("balabala\n");

    #ifdef PR_DATE
    printf("%s\n",__DATE__);
    #endif

    bool flag=true;
    printf("FUNC(flag)=%s,FUNC(1)=%s\n",FUNC(flag),FUNC(1));

    return 0;
}