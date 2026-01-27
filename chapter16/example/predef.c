#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
void whyme();
int main(int argc, char *argv[])
{
    printf("DATE is %s\n", __DATE__);
    printf("TIME is %s\n", __TIME__);
    printf("FILE is %s\n", __FILE__);
    printf("func is %s\n", __func__);
    printf("line is %d\n", __LINE__);
    printf("version is %ld\n",__STDC_VERSION__);

    whyme();

    return 0;
}
void whyme()
{
    printf("start whyme()\n");

    printf("func is %s\n", __func__);
    printf("line is %d\n", __LINE__);
}