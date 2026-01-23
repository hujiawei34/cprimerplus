#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
typedef struct lens{
    float foclen;
    float fstop;
    char brand[30];
} LENS;
int main(int argc, char *argv[])
{
    LENS lens_list[10]={[3]={500,500/2.0,"Remarkata"}};
    return 0;
}